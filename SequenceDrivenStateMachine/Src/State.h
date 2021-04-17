#pragma once

#include <map>
#include "StateInterface.h"
#include "Event.h"

using std::vector;
using std::map;
using std::string;

class StateInterface;//forword decleration to prevent circular dependencies
class State
{
    public:
    State() = default;
    inline StateInterface* getCurrentState() const 
    {
        return currentState;
    }

    ~State() noexcept = default;
    void Invoke();
    void SetState(StateInterface& nextState);
    StateInterface& ValidateState(Event eventDescription);
    string GetLastSequence();
    void SetEventSequences(map<string, vector<string>> eventSequences);
    inline vector<int>& GetEventRunner()
    {
        return m_eventRunners;
    } 
    inline vector<string>& GetLegalEvents()
    {
        return m_legalEvents;
    } 

    private:
    StateInterface* currentState;   
    map<string, vector<string>> m_eventSequences;
    vector<int> m_eventRunners;
    vector<string> m_legalEvents;


    StateInterface* InnerValidateState(const std::vector<std::string>* itMap, size_t itRunner, std::string event);
};//State

