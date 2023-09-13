#ifndef QUAD_H
#define QUAD_H

struct QuadState;
struct QuadProperties;

class QuadEngine;
class QuadProcess;

struct QuadState
{
    bool values[4];
};

struct QuadProperties
{
    int minSeq;
    int maxSeq;
    int startSeq;
    int tickSpeed;
};

class QuadEngine
{
public:
    QuadEngine(void);

    void setOutput(int i, int pin);

    void init(QuadProcess *process);
    void tick(void);

protected:
    int m_output[4];
    QuadProcess *m_process;
    QuadState m_state;
    int m_clock;
};

class QuadProcess
{
public:
    virtual QuadProperties getProperties(void) = 0;
    virtual void tick(int clock, QuadState *state) = 0;
};

#endif
