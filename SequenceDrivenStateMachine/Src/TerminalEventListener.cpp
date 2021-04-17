#include <iostream>
#include <vector>
#include <string>
#include "TerminalEventListener.h"
#include "Event.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void TerminalEventListener::ListenToEvent(Machine& machine)
{
    
    string input;
    string endRun = "End";
    m_listen = true;
    while(m_listen)
    {        
        static Event event;
        vector<string> valuesVector;
        cout<<"\nenter next event: ";
        cin>>input;
        if(endRun.compare(input) == 0)
        {
            cout<<"End Key Recieved" <<endl;
            m_listen = false;
        }
        else
        {        
            event.SetValues(input);       
            machine.RegisterEvent(event);
        }
    }
}