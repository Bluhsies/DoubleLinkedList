/**
@file main.cpp
*/


/*! \mainpage Lab Book 2
 *
 * Implementation of a Double Linked List.
 * This implementation has utilised Smart pointers and templated classes / functions to allow for any data to be used in the structure.
 */

// Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "doubleLinkedList.h"

int main() /** Entry point for the application */
{
	DoubleLinkedList<string> myList;


	myList.pushToBack("Fracture");
	myList.pushToFront("Hercules");
	myList.pushFrontCurrent("Success");
	myList.moveCurrentForward();
	myList.moveCurrentBack();
	myList.pushToFront("Frost");
	myList.pushToFront("Hiratio");
	myList.pushToFront("Blasphemy");
	myList.pushToFront("Jumpers");
	myList.pushToBack("Jumping");
	myList.pushToBack("Ghoul");
	myList.moveCurrentBack();
	myList.pushBehindCurrent("Helpers");
	myList.moveCurrentBack();
	myList.pushBehindCurrent("Joker");
	myList.moveCurrentBack();
	myList.pushBehindCurrent("Lemon");
	myList.pushToBack("Fire");
	myList.pushToBack("Orange");
	myList.pushToBack("Elementary");
	myList.pushToBack("Mystery");
	myList.popFront();
	myList.popBack();
	myList.getFrontData();	
	myList.getBackData();
	myList.getCurrentData();
	myList.getSize();


	/*DoubleLinkedList<int> myInt;

	myInt.pushToBack(1);
	myInt.pushToBack(33);
	myInt.pushToBack(4);
	myInt.pushToFront(2);
	myInt.pushToFront(87);

	myInt.getCurrentData();
	myInt.moveCurrentForward();
	myInt.getCurrentData();*/

	

	while (!myList.empty())
	{
		std::cout << myList.popFront() << std::endl;
	}

	

	if (myList.empty())
	{
		std::cout << "String is Empty" << std::endl;
	}

	/*while (!myInt.empty())
	{
		std::cout << myInt.popFront() << std::endl;
	}*/

	/*if (myInt.empty())
	{
		std::cout << "Int list is empty" << std::endl;
	}*/


	/*myList.~DoubleLinkedList();*/ // Used to clear the list and remove the memory leaks. (Commented out at this time, as the program does not full shut down after use but can be used to prevent memory leaks)
	
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");

	return 0;
}
