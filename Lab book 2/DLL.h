#pragma once

/*! \file DLL.h
	\Double Linked List data structure
*/


#include <string>
#include <memory>
#include "DLLNode.h"
using namespace std;

/*! A template for the Double Linked List class */
template <class T>
class DLL
{
private:
	unsigned int size; //!< The DLL's size
	shared_ptr <DLLNode<T>> head;//!< A shared pointer that represents the top of the DLL
	shared_ptr <DLLNode<T>> tail;//!< A shared pointer that represents the bottom of the DLL
	shared_ptr <DLLNode<T>> curr;//!< A shared pointer that represents the current node in the DLL
	
public:
	DLL(); //! Default DLL constructor
	void pushTail(T newElement);//!constructor for pushing the newly entered node to the bottom
	void pushHead(T newElement);//!constructor for pushing the newly entered node to the top
	void pushACurr(T newElement);//!constructor to push a newly entered node after the current node
	void pushBCurr(T newElement);//!constructor for pushing a newly enterd node before the current node
	T popHead();//!function for popping the head off of the list
	T popTail();//!function for popping the tail off of the list
    bool empty();//!function to check if the list is empty
	void checkList();//!function to check the amount of nodes in the list
	void forwardCurr();//!function to point the "current" pointer to the next node in the list
	void backCurr();//!function to point the "current" pointer to the previous noide in the list
	
};

	template <class T>
	DLL<T>::DLL() //!<templated defined function
	{
		head = nullptr;
		tail = nullptr;//!<because there is nothing currently in the list I am pointing all the pointers to "nullptrs" which is nothing
		curr = nullptr;
		size = 0;//!<setting size to 0 as there is nothing in the list
	}

	template <class T>
	void DLL<T>::checkList() //!<templated defined function to check whats in the list
	{
		//!checks if the list is empty
		/*!
		\empty() is a function that checks if the list is empty
		\"if" only executes if the list is empty
		\"else" will execute if the other "if" statements parameters are not fulfilled
		*/
		if (empty())
		{
			cout << "nothing in the list!. Please add something." << endl;
	    }
		else 
		{
			cout << "head:" << head->getData() << endl;
			cout << "current:" << curr->getData() << endl;
			cout << "tail:" << tail->getData() << endl;
			cout << "size is: " << size << endl;
		}
	
	}

	template <class T>
	void DLL<T>::pushHead(T newElement)//!<templated defined function that will push a new node to the head of the list
	{
		//!creates and adds a new node to the head of the list
		/*!
		\the "shared_ptr<DLLNode<T>> nNode(new DLLNode<T>(newElement));" creates a new node with the elements of a DLL Node
		\if the list is empty I have made it so the head and tail point to the new node.
		\I have made it so the "curr" pointer points to the head of the list.
		\the next and previous of the newly created node point to a "nullptr" because there is nothing else in the list to point to
		\else ensures that if the list is not empty I can still create a new node
		\the new node sets the next node in the list to be the head at that given time
		\head then equals the newly created node
		\the previous points to nothing as it is at the top of the list and there is nothing before it
		\finally the size is incremented to keep track of the the newly added node
		*/
		shared_ptr<DLLNode<T>> nNode(new DLLNode<T>(newElement));
		if (empty())
		{
			head = nNode;
			tail = nNode;
			curr = head;
			nNode->setNext(nullptr);
			nNode->setPrev(nullptr);
		}
		else
		{
			nNode->setNext(head);
			head = nNode;
			head->setPrev(nullptr);
		}
		size++;

	}

	template <class T>
	void DLL<T>::pushTail(T newElement) //!<templated defined function that pushes the new node to the bottom of the list
	{
		
		/*! same as above but vice versa */
		
		shared_ptr<DLLNode<T>> nNode(new DLLNode<T>(newElement));
		if (empty())
		{
			head = nNode;
			tail = nNode;
			curr = tail;
			nNode->setNext(nullptr);
			nNode->setPrev(nullptr);
		}
		else
		{
			nNode->setPrev(tail);
			tail = nNode;
			tail->setNext(nullptr);
		}
		size++;

	}
	
	template <class T>
	T DLL<T>::popHead()//!<templated defined function that pops the head node off the list
	{   //!deletes/pops the head of the list
		/*!
		\"result" gets the head to return its data
		\"temp" creates a temporary pointer that points to the current head. makes it so I can delete temp thus deleting old head
		\"head" will then get the next node in the stack 
		\size will decrement as I am popping from the list
		*/
	    T result = head->getData();
		shared_ptr <DLLNode<T>> temp = head;
		head = head->getNext();
		head->setPrev(nullptr);
		size--;
		return result;
	}

	template <class T>
	T DLL<T>::popTail()
	{
		/*! same as above but vice versa*/
		T result = tail->getData();
		shared_ptr <DLLNode<T>> temp = tail->getPrev();
		temp->setNext(nullptr);
		tail = temp;
		size--;
		return result;
		
	}


	template <class T>
	void DLL<T>::pushACurr(T newElement)
	{//!pushes a new node next to the current
		/*!
		\I create 2 nodes, one node for the node that the user is creating and the other to be used as a temporary node
		*/
		shared_ptr<DLLNode<T>>nNode(new DLLNode<T>(newElement));
		shared_ptr<DLLNode<T>>temp = curr->getNext();
		if (empty())
		{
			cout << "no current to add next to!" << endl;
		}
		else
		{
			/*!
			\I check if the "curr" is equal to the tail
			\if it is i set the newly created nodes previous to the current. as we are inserting this new node next to the current in the list
			\the newly created nodes next is set to a nullptr as there is nothing there
			\the tail at the time sets its next to the location of the new node
			\then we set the tail pointer to point at the new node
			*/
			if (curr == tail)
			{
				nNode->setPrev(curr);
				nNode->setNext(nullptr);
				tail->setNext(nNode);
				tail = nNode;
				size++;
			}
			else if (curr == head)
			{
				nNode->setPrev(curr);
				nNode->setNext(temp);
				head->setNext(nNode);
				size++;
			}
			/*!
			\this takes effect if the current node is not the head or tail
			\set the new node to temp so it has something it can point to for now, fitting it into the list
			\temp sets its previous to the new node
			*/
			else
			{
				nNode->setPrev(curr);
				nNode->setNext(temp);
				curr->setNext(nNode);
				temp->setPrev(nNode);
				size++;
			}

		}
	}

	template <class T>
	void DLL<T>::pushBCurr(T newElement)
	{
		shared_ptr<DLLNode<T>>nNode(new DLLNode<T>(newElement));
		shared_ptr<DLLNode<T>>temp = curr->getPrev();
		if (empty())
		{
			cout << "no current to add previous to!" << endl;
		}
		else
		{
			if (curr == tail)
			{
				nNode->setPrev(temp);
				nNode->setNext(tail);
				curr->setPrev(nNode);
				size++;
			}
			else if (curr == head)
			{
				nNode->setPrev(temp);
				nNode->setNext(curr);
				head->setPrev(nNode);
				head = nNode;
				size++;
			}
			else if (curr != head, tail)
			{
				nNode->setPrev(temp);
				nNode->setNext(curr);
				curr->setPrev(nNode);
				temp->setNext(nNode);
				size++;
			}

		}
	}



	template <class T>
	void DLL<T>::forwardCurr()//!<templated defined function that allows the current to traverse through the list
	{//!moves the current to its next position in the list
		/*!
		\if the next node in the list is not a "nullptr" then it will move the current to its next position
		\if the currents next position would be the tail then it still moves to its next position and sets itself as the new tail
		*/
		if (curr->getNext() != nullptr)
		{
			curr = curr->getNext();
		}
		else if (curr->getNext() = tail)
		{
			curr = curr->getNext();
			curr = tail;

		}
	
	}
	template <class T>
	void DLL<T>::backCurr()
	{
		if (curr->getPrev() != nullptr)
		{
			curr = curr->getPrev();
		}
		else if (curr->getPrev() = head)
		{
			curr = curr->getPrev();
			curr = head;
		}
		
	}

	template <class T>
	bool DLL<T>::empty() //!< Returns whether or not the stack is empty
	{
		return size == 0;
	}
