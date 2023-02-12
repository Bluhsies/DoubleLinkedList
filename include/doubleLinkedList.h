#pragma once

/*! \class Double Linked List
    \brief A double linked list data structure
*/

#include <string>
#include <memory>

#include "doubleLinkedListNode.h"

using namespace std;

//! This is the templated class for the DoubleLinkedList. In this file, you will find the functions which are used to perform the operations for the DoubleLinkedList. These could range from adding a first node, deleting a node from the back or viewing the data of the current node, etc.
template <class G>
class DoubleLinkedList
{
private :

	//! This defines that the size of the DoubleLinkedList will be an unsigned integer and therefore, means that it can be of any size, depending on how many nodes have been added.
	unsigned int ui_size;
	
	//! These are the three shared pointers which represent the back, front and current elements of the list. 
	shared_ptr<DoubleLinkedListNode<G>> sp_back;
	shared_ptr<DoubleLinkedListNode<G>> sp_front;
	shared_ptr<DoubleLinkedListNode<G>> sp_current;
	
	//! These are three weak pointers which can be used to monitor the associated shared pointers above. Each one is assigned in the default constructor on what to watch.
	weak_ptr<DoubleLinkedListNode<G>> wp_front;
	weak_ptr<DoubleLinkedListNode<G>> wp_back;
	weak_ptr<DoubleLinkedListNode<G>> wp_current;
	

public :

	//! This is the default constructor, where private parameters are set. For example, wp_back is assigned to be equal to sp_back, so that it can watch it.
	DoubleLinkedList();
	//! This is the default deconstructor. This contains some implementation to prevent memory leaks at the end of the programme being run.
	~DoubleLinkedList();
	//! This will allow the user to push a piece of information to the back of the list or, if no nodes are currently in the list, it will implement the first one.
	void pushToBack(G newElement); 
	//! This will allow the user to push a piece of information to the front of the list or, if no nodes are currently in the list, it will implement the first one.
	void pushToFront(G newElement);
	//! This will allow the user to push a piece of information behind the current node. It will also provide a message if this points to NULL to say this cannot be done.
	void pushBehindCurrent(G newElement);
	//! This will allow the user to push a piece of information infront of the current node. It will also provide a message if this points to NULL to say this cannot be done.
	void pushFrontCurrent(G newElement);
	//! This will allow the user to pop the data at the front of the list.
	G popFront();
	//! This will allow the user to pop the data at the back of the list.
	G popBack();
	//! This will allow the user to get the data which is currently at the front of the list.
	void getFrontData();
	//! This will allow the user to get the data which is currently at the back of the list.
	void getBackData();
	//! This will allow the user to get the data where the current node is pointing too.
	void getCurrentData();
	//! This will allow the user to move the current node forward, one node at a time.
	void moveCurrentForward();
	//! This will allow the user to move the current node backward, one node at a time.
	void moveCurrentBack();
	//! This will advise if the list is empty.
	bool empty(); 
	//! This will print the size of the current list to the screen as an integer.
	int getSize();

};

//! Default constructor for the DoubleLinkedList.h file. This contains set parameters for sp_front, sp_back, sp_current, associated weak pointers for the smart pointers and for size to be set to 0.
template <class G>
DoubleLinkedList<G>::DoubleLinkedList() 
{
	sp_front = nullptr; 
	sp_back = nullptr; 
	sp_current = nullptr;
	
	ui_size = 0; 

	wp_front = sp_front;
	wp_back = sp_back;
	wp_current = sp_current;
}

//! This is the deconstructor. This contains code which will remove memory leaks that can occur due to the dependency chain created via the DoubleLinkedList. This can be called at the end of the main to remove the leaks. (This functionality is currently commented out)
template <class G>
DoubleLinkedList<G>::~DoubleLinkedList()
{

	/*std::cout << "Remove memory leaks" << std::endl;

	shared_ptr<DoubleLinkedListNode<G>> temporary;
	while (back != NULL)
	{
		temporary = back->getPrevious();

		back->getNext() = nullptr;
		back->getPrevious() = nullptr;
		back = temporary;



	}*/
}


//! This function contains data to advise that sp_current = sp_current->getPrevious(), which allows the user to move the current pointer to the previous node and to become the new current node.
template <class G>
void DoubleLinkedList<G>::moveCurrentForward()
{

	sp_current = sp_current->getPrevious();

}

//! This function contains data to advise that sp_current = sp_current->getNext, which allows the user to move the current pointer to the next node and to become the new current node.
template <class G>
void DoubleLinkedList<G>::moveCurrentBack()
{


	sp_current = sp_current->getNext();


}

//! This function allows the user to push a new node and subsequently, new data, behind the current node. It will first check to see if a node already exists and is not pointing to a nullptr and print a message to the screen to advise this cannot be done, should this be correct.
//! If a node does exist, however, it will create a new node and set the memory addresses for the previous and next nodes of the new node, as well as making the previous back node's next node the new current node and the new current node's previous node the back.
//! It will only request for new memory in the event that a node can be added, via the if/else statement.
template <class G>
void DoubleLinkedList<G>::pushBehindCurrent(G newElement)
{

	

	if (sp_back == nullptr) std::cout << "Cannot add as initial entry, due to nullptr" << std::endl;

	else {
		shared_ptr<DoubleLinkedListNode<G>> sp_tmpB(new DoubleLinkedListNode<G>(newElement));

		sp_tmpB->setNext(sp_back);
		sp_tmpB->setPrevious(sp_current);

		sp_current->setNext(sp_tmpB);


		sp_back->setPrevious(sp_tmpB);
		sp_back->setNext(sp_current);




		ui_size++;
	}
}

//! This function allows the user to push a new node and subsequently, new data, infront of the current node. It will first check to see if a node already exists and is not pointing to a nullptr and print a message to the screen to advise this cannot be done, should this be correct.
//! If a node does exist, however, it will create a new node and set the memory addresses for the previous and next nodes of the new node, as well as making the next front node's next node the new current node and the new current node's next node the front.
//! It will only request for new memory in the event that a node can be added, via the if/else statement.
//! This function can only operate once, before it will override elements at the back of the linked list.
template <class G>
void DoubleLinkedList<G>::pushFrontCurrent(G newElement)
{

	

	if (sp_front == nullptr) std::cout << "Cannot add as initial entry, due to nullptr" << std::endl;

	else {

		shared_ptr<DoubleLinkedListNode<G>> sp_tmp(new DoubleLinkedListNode<G>(newElement));
		sp_tmp->setNext(sp_current);
		sp_tmp->setPrevious(sp_front);

		sp_current->setPrevious(sp_tmp);
		sp_front->setNext(sp_tmp);
		sp_front->setPrevious(sp_current);


		ui_size++;
	}
}

//! This function allows the user to push a new node and new data to the front of the linked list.
//! It will request for a new node to be created regardless of the outcome of the if/else statement, as this will either make the initial node if one does not exist or will push a new node to the front if at least one node exists already.
//! It will then increase the size of the list by one, via ui_size++.
template <class G>
void DoubleLinkedList<G>::pushToFront(G newElement)
{

	
	shared_ptr<DoubleLinkedListNode<G>> sp_frontNode(new DoubleLinkedListNode<G>(newElement));

	
	

	if (empty()) sp_front = sp_back = sp_current = sp_frontNode;
		
	else
	{

		sp_frontNode->setNext(sp_front);
		sp_frontNode->setPrevious(sp_frontNode);
		sp_front->setPrevious(sp_frontNode);
		sp_front = sp_frontNode;
		
	}

	
	ui_size++;	
}

//! This function allows the user to push a new node and new data to the back of the linked list.
//! It will request for a new node to be created regardless of the outcome of the if/else statement, as this will either make the initial node if one does not exist or will push a new node to the back if at least one node exists already.
//! It will then increase the size of the list by one, via ui_size++.
template <class G>
void DoubleLinkedList<G>::pushToBack(G newElement)
{
	// Need to test a condition to see if a new node needs to be added to the bottom.

	shared_ptr<DoubleLinkedListNode<G>> sp_backNode(new DoubleLinkedListNode<G>(newElement));

	if (empty()) sp_front = sp_back = sp_current = sp_backNode;
			
	else
	{
		sp_backNode->setNext(sp_backNode);
		sp_backNode->setPrevious(sp_back);
		sp_back->setNext(sp_backNode);
		sp_back = sp_backNode;
			
	}

	ui_size++;
}

//! This function allows the user to remove the first element in the linked list. It will get the data which is currently held in the front node and then move the front pointer to the next node in the list and set the next node as the new front.
//! It will then decrease the size of the list by one using ui_size-- and return the data from the front node.
//! I have also included the use of weak pointers within this function, to show if the shared pointers linked to the front, back and current expire when something is popped from the list. (These are currently commented out to reduce the amount of information in the list when it is printed to screen.)
template <class G>
G DoubleLinkedList<G>::popFront()
{
	
	G result = sp_front->getData();
	sp_front = sp_front->getNext();
	ui_size--;

	/*if (wp_front.expired())
	{
		std::cout << "Expired" << std::endl;

	}

	if (wp_back.expired())
	{
		std::cout << "Expired 2" << std::endl;

	}

	if (wp_current.expired())
	{
		std::cout << "Expired 3" << std::endl;

	}*/

	return result;

}

//! This function allows the user to remove the last element in the linked list. It will get the data which is currently held in the back node and then move the back pointer to the previous node in the list and set the previous node as the new back.
//! It will then decrease the size of the list by one, via ui_size-- and return the data from the back node.
template<class G>
G DoubleLinkedList<G>::popBack()
{
	

	G result = sp_back->getData();
	sp_back = sp_back->getPrevious();
	ui_size--;

	

	return result;

}

//! This function will allow the user to print to the screen the data which is currently held in the node at the front of the list.
//! This also contains an if statement to check if the shared pointer sp_front has fallen out of scope, by printing Expired to the screen.
template<class G>
void DoubleLinkedList<G>::getFrontData()
{

	

	std::cout << "Front data is: " << sp_front->getData() << std::endl;

	if (wp_front.expired())
	{
		std::cout << "Expired" << std::endl;

	}


}

//! This function will allow the user to print to the screen the data which is currently held in the node at the back of the list.
//! This also contains an if statement to check if the shared pointer sp_back has fallen out of scope, by printing Expired 2 to the screen.
template<class G>
void DoubleLinkedList<G>::getBackData()
{



	std::cout << "Back data is: " << sp_back->getData() << std::endl;

	

	if (wp_back.expired())
	{
		std::cout << "Expired 2" << std::endl;

	}

	

}

//! This function will allow the user to print to the screen the data which is currently held in the current node.
//! This also contains an if statement to check if the shared pointer sp_current has fallen out of scope, by printing Expired 3 to the screen.
template<class G>
void DoubleLinkedList<G>::getCurrentData()
{



	std::cout << "Current data is: " << sp_current->getData() << std::endl;

	

	if (wp_current.expired())
	{
		std::cout << "Expired 3" << std::endl;

	}

}

//! This function will allow the user to print the size of the DoubleLinkedList to the screen and return the data.
//! This is printed as an integer, to give a numerical view of the list's size.
template<class G>
int DoubleLinkedList<G>::getSize()
{

	std::cout << "List size is: " << ui_size << std::endl;

	return ui_size;
}

//! This function will allow the user to check and see if the list is empty. I have used this in a while loop in the main, to print a message to the screen to advise that the list is empty.
template <class G>
bool DoubleLinkedList<G>::empty()
{


	return ui_size == 0;


}
