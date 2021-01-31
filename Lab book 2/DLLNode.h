/*! \file DLLNode.h
* Header file contains the variables and functions of a DLL node
*/

#pragma once
#include <string>
#include <memory>

using namespace std;

template<class T>//!<template for class T
class DLLNode
{
private:

	T data; //!<variable for the data of a node
	shared_ptr<DLLNode<T>> prev; //!< pointer to the previous node in the list
	shared_ptr<DLLNode<T>> next;//!< pointer to the next node in the list
	

public:
	DLLNode(T newData, shared_ptr<DLLNode<T>> newPrev, shared_ptr<DLLNode<T>> newNext); //! Constructor that takes data, a pointer for the previous node, and a pointer for the next node
	DLLNode(T newData); //!constructor that uses the data
	T getData(); //! returns the data variable for the node its called for
	shared_ptr<DLLNode<T>> getPrev(); //!returns the previous nodes memory address
	shared_ptr<DLLNode<T>> getNext(); //!returns the next nodes memory address
	~DLLNode(); //!destructs the node
	void setPrev(shared_ptr<DLLNode<T>> prevNode); //!allows new nodes to point to another node previous to them in the list
	void setNext(shared_ptr<DLLNode<T>> nextNode);//!allows new nodes to point to another node next to them in the list

};

template <class T>
DLLNode <T>::DLLNode(T newData, shared_ptr <DLLNode<T>> newNext, shared_ptr <DLLNode<T>> newPrev)
{
	data = newData;//!< Sets the data's information as equal to the newData variable
	next = newNext;//!< Sets the previous node's memory address to be the same as the newPrev pointer
	prev = newPrev;//!< Sets the next node's memory address to be the same as the newNext pointer
}

template <class T>
DLLNode<T>::DLLNode(T newData)
{
	data = newData;
	next = nullptr;//!< Sets the next node's memory address as a null pointer
	prev = nullptr;//!< Sets the previous node's memory address as a null pointer

}

template <class T>
DLLNode<T>::~DLLNode()//!<defined function that destructs the node
{
	std::cout << "destructor" << std::endl;
}

template <class T>
T DLLNode<T>::getData() //!<returns data variable
{
	return data;
}

template <class T>
shared_ptr <DLLNode <T>> DLLNode<T>::getNext()//!< Returns the next node's memory address
{
	return next;
}

template <class T>
void DLLNode<T>::setNext(shared_ptr <DLLNode<T>> newNext)
{
	next = newNext;
}

template <class T>
shared_ptr <DLLNode<T>> DLLNode<T>::getPrev()
{
	return prev;
}
 
template <class T>
void DLLNode<T>::setPrev(shared_ptr <DLLNode<T>> newPrev)
{
	prev = newPrev;
}

