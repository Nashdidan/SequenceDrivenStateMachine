#pragma once

class State;//forword decleration to prevent circular dependencies
class StateInterface
{
public:
	virtual void Enter(State* light) = 0;
	virtual void Invoke(State* light) = 0;
	virtual void Exit(State* light) = 0;
    virtual int GetUniqueId() = 0;
    private:
    int m_uniqueId = 0;
};//StateInterface
