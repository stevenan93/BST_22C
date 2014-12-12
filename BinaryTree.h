// Binary tree abstract base class
// Created by Frank M. Carrano and Tim Henry.
// Modified by:
 
#ifndef _BINARY_TREE
#define _BINARY_TREE

#include "BinaryNode.h"

template<class ItemType>
class BinaryTree
{
protected:
	BinaryNode<ItemType>* rootPtr;		// ptr to root node
	int count;							// number of nodes in tree

public:
	// "admin" functions
 	BinaryTree() {rootPtr = 0; count = 0;}
	BinaryTree(const BinaryTree<ItemType> & tree){ }
	virtual ~BinaryTree() { }
	BinaryTree & operator = (const BinaryTree & sourceTree);
   
	// common functions for all binary trees
 	bool isEmpty() const	{return rootPtr == NULL && count == 0;}
	int size() const	    {return count;}
	void clear()			{destroyTree(rootPtr); rootPtr = 0; count = 0;}
	void preOrder(void visit(ItemType &)) const;
	void inOrder(void visit(ItemType &)) const;
	void postOrder(void visit(ItemType &)) const;
	

	// abstract functions to be implemented by derived class
	virtual bool insert(const ItemType & newData) = 0; 
	virtual bool remove(const ItemType & data) = 0; 
	virtual bool getEntry(const ItemType & anEntry, ItemType & returnedItem) const = 0;

private:   
	// delete all nodes from the tree
	void destroyTree(BinaryNode<ItemType>* nodePtr);

	// copy from the tree rooted at nodePtr and returns a pointer to the copy
	BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* nodePtr);

	// internal traverse
	void _preOrder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _inOrder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _postOrder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
   
}; 

//////////////////////////////////////////////////////////////////////////
template<class ItemType>
void BinaryTree<ItemType>::preOrder(void visit(ItemType &)) const
{
	if(isEmpty())
	{
		std::cout << "Tree is empty\n";
		return;
	}
	_preOrder(visit, rootPtr);
	std::cout << '\n';
}

template<class ItemType>
void BinaryTree<ItemType>::inOrder(void visit(ItemType &)) const
{
	if(isEmpty())
	{
		std::cout << "Tree is empty\n";
		return;
	}
	_inOrder(visit, rootPtr);
	std::cout << '\n';
}

template<class ItemType>
void BinaryTree<ItemType>::postOrder(void visit(ItemType &)) const
{
	if(isEmpty())
	{
		std::cout << "Tree is empty\n";
		return;
	}
	_postOrder(visit, rootPtr);
	std::cout << '\n';
}

template<class ItemType>
BinaryNode<ItemType>* BinaryTree<ItemType>::copyTree(const BinaryNode<ItemType>* nodePtr) 
{
	BinaryNode<ItemType>* newNodePtr = 0;
    
   
    return newNodePtr;
}  

template<class ItemType>
void BinaryTree<ItemType>::destroyTree(BinaryNode<ItemType>* nodePtr)
{
	if(!nodePtr)
	{
		return;
	}
	else if(!nodePtr->getRightPtr() && !nodePtr->getLeftPtr())
	{
		delete nodePtr;
		return;
	}
	if(nodePtr->getRightPtr())
	{
		destroyTree(nodePtr->getRightPtr());
	}
	else if(nodePtr->getLeftPtr())
	{
		destroyTree(nodePtr->getLeftPtr());
	}
		
}  

template<class ItemType>
void BinaryTree<ItemType>::_preOrder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr)
	{
		ItemType item = nodePtr->getItem();
		visit(item);
		_preOrder(visit, nodePtr->getLeftPtr());
		_preOrder(visit, nodePtr->getRightPtr());
	} 
}  

template<class ItemType>
void BinaryTree<ItemType>::_inOrder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr)
	{
		ItemType item = nodePtr->getItem();
		_preOrder(visit, nodePtr->getLeftPtr());
		visit(item);
		_preOrder(visit, nodePtr->getRightPtr());
	} 
}  

template<class ItemType>
void BinaryTree<ItemType>::_postOrder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr)
	{
		ItemType item = nodePtr->getItem();
		_preOrder(visit, nodePtr->getLeftPtr());
		_preOrder(visit, nodePtr->getRightPtr());
		visit(item);
	} 
}  

template<class ItemType>
BinaryTree<ItemType> & BinaryTree<ItemType>::operator=(const BinaryTree<ItemType> & sourceTree)
{

}  


#endif

