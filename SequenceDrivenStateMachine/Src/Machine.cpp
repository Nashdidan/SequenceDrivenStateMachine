#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <cstring>
#include <iterator>
#include <filesystem>

#include "../Resources/rapidxml/rapidxml.hpp"

#include "State.h"
#include "Machine.h"
#include "ExampleStates.hpp"

using std::string;
using std::vector;
using std::map;
using std::cout;
using std::endl;
using std::ifstream;
using std::iterator;
using std::istreambuf_iterator;
using std::cin;
using namespace rapidxml;

map<string, vector<string>> Machine::ReadMachineStateFromXML ()
{
    xml_document<> doc;
    xml_node<> * root_node = NULL;
    map<string, vector<string>> machineStateMap;
    string fileLocation;
    bool isFileValid = false;
    while(!isFileValid)
    {
        cout<<"\nPlease Enter Valid .xml file: ";    
        cin>>fileLocation;
        cout<<endl;        
        if(std::filesystem::exists(fileLocation))
        {
            isFileValid = true;
        }
        else
        {
            cout<<"\nError: File Location Is Invalid"<<endl;
        }
    }

    cout << "\nParsing Sequences from XML";
    ifstream file(fileLocation);
    vector<char> buffer ((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);

    root_node = doc.first_node("MachineState");

    xml_node<>* legalEvent = root_node -> first_node("LegalEvents");
    cout<<"\nLegal Events: "<<endl;
    for(xml_node<> *itr_activity_node = legalEvent->first_node("Event"); itr_activity_node; itr_activity_node = itr_activity_node->next_sibling())
    {
        string activity_description = itr_activity_node->first_attribute("desctiption")->value();

        currentState.GetLegalEvents().push_back(activity_description);

        cout<<"Desctiption = "<<activity_description<<endl;
    }

    for(xml_node<> * itrNode = root_node -> first_node("Sequence"); itrNode; itrNode = itrNode->next_sibling())
    {
        vector<string> activity_vector;
        string state = itrNode->first_attribute("sequence_name")->value();
        cout<< "\nSequence = "<< state;
        cout<<endl;

        for(xml_node<> *itr_activity_node = itrNode->first_node("Event"); itr_activity_node; itr_activity_node = itr_activity_node->next_sibling())
        {
            string activity_description = itr_activity_node->first_attribute("desctiption")->value();

            activity_vector.push_back(activity_description);

            cout<<"Desctiption = "<<activity_description<<endl;

        }
        machineStateMap[state] = activity_vector;
        currentState.GetEventRunner().push_back(-1);
        cout<<endl;
    }


    return machineStateMap;
}


void Machine::RegisterEvent(Event eventDescription)
{
    StateInterface* state = &currentState.ValidateState(eventDescription);
    SetState(*state);
    currentState.Invoke();
}

Machine::Machine() : currentState()
{   
    currentState.SetEventSequences(ReadMachineStateFromXML());  
    SetState(InitialMachine::getInstance());
}

void Machine::SetState(StateInterface& nextState)
{
    currentState.SetState(nextState);
}