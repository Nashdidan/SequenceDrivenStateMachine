

Install rapidxml library before using:
	- go to Resources directory
	- write on terminal : sudo apt install librapidxml-dev -y
	
For Compile:
	in Src directory - 
	g++ -Wall -g -std=c++17  -o ../Bin/a.out State.cpp ExampleStates.cpp Machine.cpp RunTest.cpp Event.cpp TerminalEventListener.cpp

Xml file writing instractions:

	<LegalEvents> - The evetn known by the machine
		<Event description = > Add the event name
	
	<Sequence sequence_Name> - Add new sequence
		<Event description> - list of events needs to invoke the sequence
	
	For Example : use machine_state_test.xml file
	
State Machine:

	InitialMachine  - state that ivoked when machine is ready to recieve events from the user
	WaitingForEvent - invoked when one or more of the sequences recieved its wanted event
	SequenceEnded - invoked when sequence event is complete prints sequence_name in terminal
	Ignore - initialize the sequences when no sequence event recieved that matches the wanted sequences and invoked when inknown sequence recieved
	
	Each state is decribed in StateInterface.h
	
Special Events:

	Any - recieves any event
	End - exits the event listener
	
Bin directory:
	includes .out files
	
Resources directory:
	icludes external resources used by the programm
	
Bin directory:
	includes all .h .hpp .cpp files
	

╔══╗─╔╗──────╔═══╗
╚╣╠╝─║║──────║╔═╗║
─║║╔═╝╠══╦═╗─║║─║╠═╗
─║║║╔╗║╔╗║╔╗╗║║─║║╔╝
╔╣╠╣╚╝║╔╗║║║║║╚═╝║║
╚══╩══╩╝╚╩╝╚╝╚═══╩╝
