#include <functional>
#include <iostream>

#include "Machine.h"
#include "TerminalEventListener.h"


int main()
{
    Machine stateMachine;
    TerminalEventListener eventListener;
    eventListener.Start();
    eventListener.ListenToEvent(stateMachine);
}