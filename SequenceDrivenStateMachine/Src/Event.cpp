#include <string>
#include "Event.h"

Event::Event(const Event& src){
        m_eventDescription = src.m_eventDescription;
    };

void Event::SetValues(std::string& value)
{
    m_eventDescription = value;
}

Event& Event::operator=(const Event& src)
{
    m_eventDescription = src.m_eventDescription;
    return *this;
}