// main test driver for BST
// Created by Frank M. Carrano and Tim Henry.
// modified by 


#include <iostream>
#include <string>

#include "BinarySearchTree.h"  // BST ADT 
#include "BinaryNode.h"
using namespace std;

// display function to pass to BST traverse functions
/*
void display(string & anItem)
{
   cout << "Displaying item - " << anItem << endl;
}  
*/
void check(bool success)
{
   if (success)
      cout << "Done." << endl;
   else
      cout << " Entry not in tree." << endl;
}  

void display(int & i)
{
	cout << i << ' ';
}

void depthTraversals(int choice, BinarySearchTree<int>* treePtr)
{
	switch(choice)
	{
		case 0:
		{
			treePtr->preOrder(display);
			break;
		}
		case 1:
		{
			treePtr->inOrder(display);
			break;
		}
		case 2:
		{
			treePtr->postOrder(display);
			break;
		}
		default:
			cout << "Error in depthTraversals\n";
			break;
	
	}
}

int main()
{
	//bool success;

	// Part 1: inserting data in order:
   BinarySearchTree<int>* tree1Ptr = new BinarySearchTree<int>();
   
   tree1Ptr->insert(10);	
   tree1Ptr->insert(20);
   tree1Ptr->insert(40);
   tree1Ptr->insert(-10);
   tree1Ptr->insert(-15);
   cout << "SIZE OF TREE: " << tree1Ptr->size() << endl;
	
   int search;
   if(tree1Ptr->getEntry(0, search))
   {
        cout << "FOUND\n";
   }
   else
   {
		cout << "NOT FOUND\n";
   }


	

/*
   // Part 3: Copying trees
   cout << "\nTesting copy constructor: \n";
   cout << "\nOriginal tree1: \n";
   cout << "Tree 1 Inorder: Should be 10 20 30 40 50\n";
   tree1Ptr->inOrder(display); 
   BinarySearchTree<string> tree1Copy(*tree1Ptr);
   cout << "Copy of Tree 1 Inorder: Should be 10 20 30 40 50\n";
   tree1Copy.inOrder(display);  
   cout  << endl;

   cout << "\nTesting overloaded assignment operator: \n";
   cout << "\nAfter assigning Tree 1 to Tree 2, we have: \n";
   tree2 = *tree1Ptr;
    
   cout << "Tree 2 Inorder: Should be 10 20 30 40 50\n";
   tree2.inOrder(display);  
   cout  << endl;    
   
   cout << "Change Tree 2 by removing 10" << endl;
   tree2.remove("10");
   
   cout << "Tree 2 Inorder: Should be 20 30 40 50\n";
   tree2.inOrder(display);   
   cout << "Tree 1 Inorder: Should be 10 20 30 40 50\n";
   tree1Ptr->inOrder(display); 
   cout  << endl; 

   delete tree1Ptr;
*/
   return 0;
}  