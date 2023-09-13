#include <string.h>

#include "Arduino.h"
#include "Quad.h"

QuadEngine::QuadEngine(void)
{
    memset(&m_output, 0, sizeof(m_output));
    m_process = NULL;
    memset(&m_state, 0, sizeof(m_state));
    m_clock = 0;
}

void QuadEngine::setOutput(int i, int pin)
{
    m_output[i] = pin;
    pinMode(pin, OUTPUT);
}

void QuadEngine::init(QuadProcess *process)
{
    m_process = process;
    memset(&m_state, 0, sizeof(QuadState));

    QuadProperties props = m_process->getProperties();
    m_clock = props.startSeq;
}

void QuadEngine::tick(void)
{
    m_process->tick(m_clock, &m_state);
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(m_output[i], m_state.values[i] ? HIGH : LOW);
    }

    QuadProperties props = m_process->getProperties();
    m_clock = props.minSeq + (m_clock + 1 - props.minSeq) % (props.maxSeq - props.minSeq + 1);

    delay(props.tickSpeed);
}
