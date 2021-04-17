#pragma once

#include <iostream>
#include <vector>
#include <string>

using std::string;

class Event
{
    public:
    explicit Event() = default;
    Event(const Event& src);
    Event& operator=(const Event& src);
    ~Event() noexcept = default;

    void SetValues(string& value);    
    string m_eventDescription;
};//Even

