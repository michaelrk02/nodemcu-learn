#include <Quad.h>

class QuadBinary : public QuadProcess
{
public:
  QuadBinary(void)
  {
    //
  }

  QuadProperties getProperties(void)
  {
    QuadProperties props;
    props.minSeq = 0;
    props.maxSeq = 15;
    props.startSeq = 0;
    props.tickSpeed = 1000;
    return props;
  }

  void tick(int clock, QuadState *state)
  {
    for (int i = 0; i < 4; i++)
    {
      state->values[i] = ((clock >> i) & 0x1) != 0;
    }
  }
};

QuadEngine g_engine;
QuadBinary g_process;

void setup()
{
  g_engine.setOutput(0, D0);
  g_engine.setOutput(1, D2);
  g_engine.setOutput(2, D6);
  g_engine.setOutput(3, D8);

  g_engine.init(&g_process);
}

void loop()
{
  g_engine.tick();
}