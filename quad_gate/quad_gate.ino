#include <Quad.h>

class QuadGate : public QuadProcess
{
public:
  QuadGate(void)
  {
    //
  }

  QuadProperties getProperties(void)
  {
    QuadProperties props;
    props.minSeq = 0;
    props.maxSeq = 3;
    props.startSeq = 0;
    props.tickSpeed = 1000;
    return props;
  }

  void tick(int clock, QuadState *state)
  {
    state->values[0] = ((clock >> 0) & 0x1) != 0;
    state->values[1] = ((clock >> 1) & 0x1) != 0;
    state->values[2] = state->values[0] && state->values[1];
    state->values[3] = state->values[0] || state->values[1];
  }
};

QuadEngine g_engine;
QuadGate g_process;

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