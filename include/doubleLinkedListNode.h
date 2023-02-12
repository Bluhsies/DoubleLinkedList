#pragma once

/*! \class Double Linked List Node
	\brief A double linked list data structure
*/

#include <string>
#include <memory>

using namespace std;

//! This is the templated class for the DoubleLinkedListNode, which is used to store and view the data stored in the nodes, based on functions available in the DoubleLinkedList file.
template <class G>
class DoubleLinkedListNode
{

private:

	//! The parameter G is slightly different to normal parameters, as this uses the template to allow the user to input any type of data, such as a string, integer, double, float, etc. to the nodes.
	G data;
	//! These are the two shared pointers which are used for the set next and previous and get next and previous functions. These are used in the DoubleLinkedList file to add, reallocate and delete data through inheritance.
	shared_ptr<DoubleLinkedListNode<G>> sp_next;
	shared_ptr<DoubleLinkedListNode<G>> sp_previous;

public:

	//! This is the default constructor, which takes new data from the templated functions via G newData and assigns it to be data. This is mainly used in the getData function to return the data in the node.
	DoubleLinkedListNode(G newData);
	//! This is the deconstructor.
	~DoubleLinkedListNode();
	//! This function uses the template's ability to use any of the parameters such as integer, float, etc and return the data. Usually this is used to print the data to the screen or to assist with the pop functions, which helps to reassign the nodes.
	G getData();
	//! This function will return the data which is held in the next node. For example, if you are popping from the front, it will get the data held in the next node (not a nullptr) and assign the next node as the new front node.
	shared_ptr<DoubleLinkedListNode<G>>getNext();
	//! This function will return the data which is held in the previous node. As an example, this is used in the popBack function to assign the previous node as the new back node by getting the data from the previous node at the back.
	shared_ptr<DoubleLinkedListNode<G>>getPrevious();
	//! This function will allow the user to set the reference for the pointer of the next node. This does not store data, but allows the user to assign pointers.
	void setNext(shared_ptr<DoubleLinkedListNode<G>>& newNext);
	//! This function will allow the user to set the reference for the pointer of the previous node. This does not store data, but allows the user to assign pointers.
	void setPrevious(shared_ptr<DoubleLinkedListNode<G>>& newPrevious);

};

//! This is the default constructor. This will assign data to be newData, as well as sp_next and sp_previous to initially be null pointers.
template <class G>
DoubleLinkedListNode<G>::DoubleLinkedListNode(G newData) //!< Constructor
{
	data = newData;
	sp_next = nullptr;
	sp_previous = nullptr;
}

//! This is the deconstructor, represented by the ~ symbol infront of DoubleLinkedListNode.
template <class G>
DoubleLinkedListNode<G>::~DoubleLinkedListNode()
{

	std::cout << "Destructor" << std::endl;

}

//! This function will return the data from a node.
template <class G>
G DoubleLinkedListNode<G>::getData() 
{
	return data;
}

//! This function will return the location of the next node's memory address.
template <class G>
shared_ptr<DoubleLinkedListNode<G>> DoubleLinkedListNode<G>::getNext() 
{
	return sp_next;
}

//! This function will return the location of the previous node's memory address.
template <class G>
shared_ptr<DoubleLinkedListNode<G>> DoubleLinkedListNode<G>::getPrevious() 
{
	return sp_previous;
}

//! This function will set the shared pointer reference for the next node, by taking in a pointer for a node made in DoubleLinkedList.
template <class G>
void DoubleLinkedListNode<G>::setNext(shared_ptr<DoubleLinkedListNode>& newNext)
{
	sp_next = newNext;
}

//! This function will set the shared pointer reference for the previous node, by taking in a pointer for a node made in DoubleLinkedList.
template <class G>
void DoubleLinkedListNode<G>::setPrevious(shared_ptr<DoubleLinkedListNode>& newPrevious)
{
	sp_previous = newPrevious;
}