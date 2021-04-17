#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <utility>
#include "State.h"
#include "ExampleStates.hpp"


using std::string;
using std::vector;
using std::find;
using std::map;

void State::SetState(StateInterface& nextState)
{   
    if(currentState != nullptr)
    {
    	currentState->Exit(this);  // do stuff before we change state
    }  
	currentState = &nextState;  // change state
	currentState->Enter(this); // do stuff after we change state
}

void State::Invoke()
{
    currentState->Invoke(this);
}

StateInterface& State::ValidateState(Event eventDescription)
{
    string event = eventDescription.m_eventDescription;
    size_t i = 0;

    StateInterface* retState = &InitialMachine::getInstance();
    for(auto itMap = m_eventSequences.begin(); itMap != m_eventSequences.end(); itMap++)
    {
        StateInterface* tempRetState = &Ignore::getInstance();           
        tempRetState = InnerValidateState(&itMap->second, i, event);

        if(SequenceEnded::getInstance().GetUniqueId() == tempRetState->GetUniqueId())
        {
            m_eventRunners[i] = -2; 
            retState = tempRetState;
        }
        else if(WaitingForEvent::getInstance().GetUniqueId() == tempRetState->GetUniqueId())
        {
            if(retState->GetUniqueId() != SequenceEnded::getInstance().GetUniqueId())                     
                retState = tempRetState;
        }
        else
        {  
            m_eventRunners[i] = -1;  
            if(retState->GetUniqueId() != WaitingForEvent::getInstance().GetUniqueId() && retState->GetUniqueId() != SequenceEnded::getInstance().GetUniqueId())                     
                retState = tempRetState;
        }

        i++;
    }
    return *retState;    
}

string State::GetLastSequence()
{
    size_t i = 0;
    for(auto itMap = m_eventSequences.begin(); itMap != m_eventSequences.end(); ++itMap)
    {
        if(m_eventRunners[i] == - 2)
        {
            m_eventRunners[i] = -1;
            return itMap->first;
        }
        i++;
    }

    return "Warning: no Sequence Found Maching";
}

StateInterface* State::InnerValidateState(const vector<string>* itMap, size_t itRunner, string event)
{
    m_eventRunners[itRunner] += 1;  

    //if event is not in the legal event vector - ignore
    if(find(m_legalEvents.begin(), m_legalEvents.end(), event) == m_legalEvents.end())
    {
        return &Ignore::getInstance();
    }
    //if event equals the wanted event in seq
    if(event.compare((*itMap)[m_eventRunners[itRunner]]) == 0 || (*itMap)[m_eventRunners[itRunner]] == "Any")
    {
        if(m_eventRunners[itRunner] == (int)(*itMap).size() - 1)
        {      
            return &SequenceEnded::getInstance();                    
        }
        else
        {
            return &WaitingForEvent::getInstance();
        }
    }
    //sequnce should be ignored
    else
    {       
        return &Ignore::getInstance();        
    }        
}

void State::SetEventSequences(map<string, vector<string>> eventSequences)
{    
    m_eventSequences = eventSequences;
}


