#pragma once

#include "Machine.h"

class EventListenerIntrerface
{
    public:
    explicit EventListenerIntrerface() = default;
    EventListenerIntrerface(const EventListenerIntrerface& src) = delete;
    EventListenerIntrerface& operator = (const EventListenerIntrerface& src) = delete;
    
    inline void Start()
    {
        m_listen = true;
    }
    inline void Stop()
    {
        m_listen = false;   
    }
    virtual void ListenToEvent(Machine& machine) = 0;
    protected:
    bool m_listen;
};//EventListenerInterface