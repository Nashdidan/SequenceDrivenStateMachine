#pragma once

#include "EventListenerInterface.h"

class TerminalEventListener : public EventListenerIntrerface
{
    public:
    TerminalEventListener() = default;
    TerminalEventListener(const TerminalEventListener& src) = delete;
    TerminalEventListener& operator=(TerminalEventListener& src) = delete;
    ~TerminalEventListener() noexcept = default;

    virtual void ListenToEvent(Machine& machine);
    protected:
    bool m_listen = false;
};//TerminalEventListener