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
   //BinaryNode<int>* curPtr = tree1Ptr->getRoot();

   cout << "Tree 1 Preorder: Should be 10 -10 -15 20 40\n";
   tree1Ptr->preOrder(display);   
   cout << "\nTree 1 Inorder: Should be -10 -15 10 20 40\n";
   tree1Ptr->inOrder(display);  
   cout << "\nTree 1 Postorder: Should be -10 -15 20 40 10\n";
   tree1Ptr->postOrder(display);
   cout  << endl;   
   
   tree1Ptr->clear();
      cout << "Tree 1 Preorder: Should be 10 -10 -15 20 40\n";
   tree1Ptr->preOrder(display);   
   cout << "\nTree 1 Inorder: Should be -10 -15 10 20 40\n";
   tree1Ptr->inOrder(display);  
   cout << "\nTree 1 Postorder: Should be -10 -15 20 40 10\n";
   tree1Ptr->postOrder(display);
   cout  << endl;   
cout << "SIZE OF TREE: " << tree1Ptr->size() << endl;
 


/*
   // Part 2: Inserting data in random order
   BinarySearchTree<string> tree2;
   
   tree2.insert("40");
   tree2.insert("20");
   tree2.insert("10");
   tree2.insert("60");
   tree2.insert("50");
   tree2.insert("70");
   tree2.insert("30");
   tree2.insert("80");
  
   //       40
   //     /     \
   //    20     60
   //   /  \   /  \
   //  10  30 50  70
   //               \
   //               80

   cout << "Tree 2 Preorder: Should be 40 20 10 30 60 50 70 80\n";
   tree2.preOrder(display);  
   cout << "Tree 2 Inorder: Should be 10 20 30 40 50 60 70 80\n";
   tree2.inOrder(display);   
   cout << "Tree 2 Postorder: Should be 10 30 20 50 80 70 60 40\n";
   tree2.postOrder(display);
   cout  << endl;       

   cout << "Remove the node 70 that has only a right child: ";
   success = tree2.remove("70");
   check(success);
   //        40
   //     /     \
   //    20     60
   //   /  \   /  \
   //  10  30 50  80
   
   cout << "Tree 2 Inorder: Should be 10 20 30 40 50 60 80\n";
   tree2.inOrder(display);   
   cout  << endl;      

   cout << "Remove the node 60 that has two children: ";
   success = tree2.remove("60");
   check(success);
   //        40
   //     /     \
   //    20     80
   //   /  \   /
   //  10  30 50
   
   cout << "Tree 2 Inorder: Should be 10 20 30 40 50 80\n";
   tree2.inOrder(display);   
   cout  << endl; 

   cout << "Remove the leaf 10: ";
   success = tree2.remove("10");
   check(success);
   //        40
   //     /     \
   //    20     80
   //      \   /
   //      30 50
   
   cout << "Tree 2 Inorder: Should be 20 30 40 50 80\n";
   tree2.inOrder(display);   
   cout  << endl;     

   cout << "Remove the root 40: ";
   success = tree2.remove("40");
   check(success);
   //      50
   //     /  \
   //    20   80
   //      \
   //      30
   
   cout << "Tree 2 Inorder: Should be 20 30 50 80\n";
   tree2.inOrder(display);   
   cout  << endl; 

   string returnedString;
   cout << "Searching for node 80 returns " << tree2.getEntry("80", returnedString) << endl;
   cout << "Searching for node 40 returns " << tree2.getEntry("40", returnedString) << endl;
*/

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