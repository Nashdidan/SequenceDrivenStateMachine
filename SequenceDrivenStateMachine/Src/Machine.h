#pragma once

#include <vector>
#include <map>
#include <vector>

#include "State.h"
#include "StateInterface.h"
#include "Event.h"

using std::map;
using std::vector;
using std::string;

class Machine
{
    public:
    explicit Machine();
    Machine(const Machine& src);
    Machine& operator=(const Machine& src);
    void RegisterEvent(Event eventDescription);//TODO maybe return handler_id_type
    void SetState(StateInterface& nextState);

    private:
    map<string, vector<string>> ReadMachineStateFromXML();
    State currentState;
};//Machine