#include <iostream>
#include "ExampleStates.hpp"
#include "State.h"
#include "Utils.hpp"

using std::string;
using std::cout;
using std::endl;

static WaitingForEvent* singletonWaitingForEvent = nullptr;
static SequenceEnded* singletonSequenceEnded = nullptr;
static Ignore* singletonIgnore = nullptr;
static InitialMachine* singletonInitialMachine = nullptr;

static int uniqeIdGenerator = 0;

InitialMachine::InitialMachine()
{
    m_uniqueId = uniqeIdGenerator++;
}
int InitialMachine::GetUniqueId()
{
    return m_uniqueId;
}
StateInterface& InitialMachine::getInstance()
{
    static InitialMachine singleton;
    if(singletonInitialMachine == nullptr)
    {        
        singletonInitialMachine = new InitialMachine();
    }
    return singleton;
}

void InitialMachine::Invoke(State* state)
{
    cout<<"\nInitialMachine Is Invoked"<<endl;    
}

void InitialMachine::Enter(State* state)
{
    cout<<"\nMachine Entered InitialMachine State"<<endl;
}

void InitialMachine::Exit(State* state)
{
    cout<<"\nMachine Exit InitialMachine State"<<endl;
}

WaitingForEvent::WaitingForEvent()
{
    m_uniqueId = uniqeIdGenerator++;
}

StateInterface& WaitingForEvent::getInstance()
{
    if(singletonWaitingForEvent == 0)
    {
        singletonWaitingForEvent = new WaitingForEvent();
    }
    return *singletonWaitingForEvent;
}
int WaitingForEvent::GetUniqueId()
{
    return m_uniqueId;
}
void WaitingForEvent::Invoke(State* state)
{
    cout<<"\nWaitingForEvent Is Invoked"<<endl;    
}

void WaitingForEvent::Enter(State* state)
{
    cout<<"\nMachine Entered WaitingForEvent State"<<endl;
}

void WaitingForEvent::Exit(State* state)
{
    cout<<"\nMachine Exit WaitingForEvent State"<<endl;
}

SequenceEnded::SequenceEnded()
{
    m_uniqueId = uniqeIdGenerator++;
}

StateInterface& SequenceEnded::getInstance()
{
    if(singletonSequenceEnded == 0)
    {
        singletonSequenceEnded = new SequenceEnded();
    }
    return *singletonSequenceEnded;
}
int SequenceEnded::GetUniqueId()
{
    return m_uniqueId;
}
void SequenceEnded::Invoke(State* state)
{
    cout<<"\nSequnce Ended: "<<state->GetLastSequence()<<endl;    
}

void SequenceEnded::Enter(State* state)
{
    cout<<"\nMachine Entered SequenceEnded State"<<endl;
}

void SequenceEnded::Exit(State* state)
{
    cout<<"\nMachine Exit SequenceEnded State"<<endl;
}

StateInterface& Ignore::getInstance()
{
    if(singletonIgnore == 0)
    {
        singletonIgnore = new Ignore();
    }
    return *singletonIgnore;
}

Ignore::Ignore()
{
    m_uniqueId = uniqeIdGenerator++;
}

int Ignore::GetUniqueId()
{
    return m_uniqueId;
}
void Ignore::Enter(State* state)
{
    cout<<"\nMachine Entered Ignore State"<<endl;
}

void Ignore::Exit(State* state)
{
    cout<<"\nMachine Exit Ignore State"<<endl;
}

void Ignore::Invoke(State* state)
{
    cout<<"State Ignore Is Invoked"<<endl;
}