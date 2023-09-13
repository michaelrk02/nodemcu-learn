#include <Quad.h>

class QuadFill : public QuadProcess
{
public:
  QuadFill(void)
  {
    //
  }

  QuadProperties getProperties(void)
  {
    QuadProperties props;
    props.minSeq = 0;
    props.maxSeq = 4;
    props.startSeq = 0;
    props.tickSpeed = 250;
    return props;
  }

  void tick(int clock, QuadState *state)
  {
    for (int i = 0; i < 4; i++)
    {
      state->values[i] = clock >= (i + 1);
    }
  }
};

QuadEngine g_engine;
QuadFill g_process;

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