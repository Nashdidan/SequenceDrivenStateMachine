#pragma once

#include <list>
#include <iostream>
#include <vector>

#include "StateInterface.h"
#include "State.h"

class InitialMachine : public StateInterface
{
    public:
    virtual void Enter(State* state);
    virtual void Invoke(State* state);
    virtual void Exit(State* state);
    static StateInterface& getInstance(); // for singleton implementation
    
    virtual ~InitialMachine(){};
    InitialMachine(const InitialMachine& src) = delete;
    InitialMachine& operator=(const InitialMachine& src) = delete;  
    virtual int GetUniqueId();

    private:
    InitialMachine();// private ctor for singleton implementation
    int m_uniqueId = 1;

};//InitialMachine


class WaitingForEvent : public StateInterface
{
    public:
    virtual void Enter(State* state);
    virtual void Invoke(State* state);
    virtual void Exit(State* state);
    static StateInterface& getInstance(); // for singleton implementation
    
    virtual ~WaitingForEvent(){};
    virtual int GetUniqueId();

    private:
    WaitingForEvent();// private ctor for singleton implementation
    WaitingForEvent(const WaitingForEvent& src) = delete;
    WaitingForEvent& operator=(const WaitingForEvent& src) = delete; 
    int m_uniqueId = 2;  
};//WaitingForEvent



class SequenceEnded : public StateInterface
{
    public:
    virtual void Enter(State* state);
    virtual void Invoke(State* state);
    virtual void Exit(State* state);
    static StateInterface& getInstance(); // for singleton implementation
    
    virtual ~SequenceEnded() {};   
    virtual int GetUniqueId(); 
    

    private:
    SequenceEnded();// private ctor for singleton implementation
    SequenceEnded(const SequenceEnded& src);
    SequenceEnded& operator=(const SequenceEnded& src) = delete;
    int m_uniqueId = 3;
};//SequenceEnded

class Ignore : public StateInterface
{
    public:
    virtual void Enter(State* state);
    virtual void Invoke(State* state);
    virtual void Exit(State* state);
    static StateInterface& getInstance(); // for singleton implementation
    
    virtual ~Ignore() = default;  
    virtual int GetUniqueId();  
    
    private:
    Ignore();// private ctor for singleton implementation
    Ignore(const Ignore& src);
    Ignore& operator=(const Ignore& src) = delete;
    static Ignore* singleton;
    int m_uniqueId = 4;
};//Ignore