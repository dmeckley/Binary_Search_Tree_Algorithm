/*****************************************************
*   BinarySearchTree.cpp
*
*   Dustin Meckley
*   ciss350
*   7/24/15
*/

#ifndef BINARYSEARCHTREE_CPP_
#define BINARYSEARCHTREE_CPP_

#include "BinarySearchTree.h"

/*****************************************************
*   BinarySearchTree()  
*
*   Constructor for BinarySearchTree class.
*/
BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

/***************************************************** 
*   ~BinarySearchTree()  
*
*   Destructor for BinarySearchTree class.
*/
BinarySearchTree::~BinarySearchTree()
{
    clear();
}

/*****************************************************
*   BinarySearchTree()
*
*   BinarySearchTree isEmpty Function Method
*/
bool BinarySearchTree::isEmpty() const 
{ 
    return root == NULL; 
}

/*****************************************************
*   BinarySearchTree()
*
*   BinarySearchTree isFull Function Method
*/
bool BinarySearchTree::isFull() const 
{
    // Returns true if list is full  
    Node* ptr;
    ptr = new Node();
    if (ptr == NULL)
        return true;
    else
    {
        delete ptr;
        return false;
    }
}

/*****************************************************
*   BinarySearchTree()
*
*   BinarySearchTree addNode Function Method
*/
void BinarySearchTree::addNode(int value)
{
    Node* temp = new Node;
    Node* parent;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    parent = NULL;
    
    // is this a new tree?
    if(isEmpty()) 
        root = temp;
    else
    {
        //Note: ALL insertions are as leaf nodes
        Node* curr;
        curr = root;
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(temp->data > curr->data) 
                curr = curr->right;
            else 
                curr = curr->left;
        }

        if(temp->data < parent->data)
           parent->left = temp;
        else
           parent->right = temp;
    }
}

/*****************************************************
*   BinarySearchTree()
*
*   BinarySearchTree remove Function Method
*/
void BinarySearchTree::removeNode(int value)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout << " This Tree is empty! " << endl;
        return;
    }
    
    Node* curr;
    Node* parent;
    curr = root;
    
    while(curr != NULL)
    {
         if(curr->data == value)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(value > curr->data) 
                curr = curr->right;
             else 
                curr = curr->left;
         }
    }
    if(!found)
	{
        cout << " Data not found! " << endl;
        return;
    }

    // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| 
       (curr->left != NULL && curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
                parent->left = curr->right;
                delete curr;
           }
           else
           {
                parent->right = curr->right;
                delete curr;
           }
       }
       // left child present, no right child
       else 
       {
          if(parent->left == curr)
           {
                parent->left = curr->left;
                delete curr;
           }
           else
           {
                parent->right = curr->left;
                delete curr;
           }
        }
        return;
    }

	//We're looking at a leaf node
	if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) 
            parent->left = NULL;
        else 
            parent->right = NULL;
		delete curr;
		return;
    }

    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        Node* check;
        check = curr->right;
        if((check->left == NULL) && (check->right == NULL))
        {
            curr = check;
            delete check;
            curr->right = NULL;
        }
        // right child has children
        else 
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element
            if((curr->right)->left != NULL)
            {
                Node* leftCurr;
                Node* leftCurrPtr;
                leftCurrPtr = curr->right;
                leftCurr = (curr->right)->left;
                while(leftCurr->left != NULL)
                {
                   leftCurrPtr = leftCurr;
                   leftCurr = leftCurr->left;
                }
		        curr->data = leftCurr->data;
                delete leftCurr;
                leftCurrPtr->left = NULL;
           }
           else
           {
               Node* temp;
               temp = curr->right;
               curr->data = temp->data;
	           curr->right = temp->right;
               delete temp;
           }
        }
		 return;
    }
}

/*****************************************************
*   BinarySearchTree()
*
*   BinarySearchTree getNode Function Method
*/
void BinarySearchTree::getNode(int value) 
{                                       // sValue is for search value to be found.
    getNodeLevel(value, root);        // pass in the search value and the root value
}
void BinarySearchTree::getNodeLevel(int value, Node* parent)
{
    if (root != NULL)
    {
        if (root->data == value)
        {
            displayMatch(value);
        }
        else
        {
            if (value < parent->data && parent->left != NULL)
            {
                parent->left->data == value ?
                    displayMatch(value) :
                    getNodeLevel(value, parent->left);
            }
            else if (value > parent->data && parent->right != NULL)
            {
                parent->right->data == value ?
                    displayMatch(value) :
                    getNodeLevel(value, parent->right);
            }
            else
            {
                cout << "The node " << value << 
                " is not within the binary tree strucure!\n";
            }
        }
    }   
}
void BinarySearchTree::displayMatch(int value)
{
                            
        cout << "\nThe value " << value << 
        " is within the binary tree strucure!\n";
}

/*****************************************************
*   BinarySearchTree()
*
*   BinarySearchTree clear Function Method
*/
void BinarySearchTree::clear()
{
    clearTree(root);
}
void BinarySearchTree::clearTree(Node* root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            clearTree(root->left);
        }
        else if (root->right != NULL)
        {
            clearTree(root->right);
        }
        cout << "Delete Node Value: " << root->data << endl; 
        delete root;
    }
} 

/*****************************************************
*   BinarySearchTree()
*
*   BinarySearchTree getLength Function Method
*/
int BinarySearchTree::getLength() 
{
    return nodeCounter(root);
}
int BinarySearchTree::nodeCounter(Node* tree)
{
    if(tree == NULL)
        return 0;
    else 
        return nodeCounter(tree->left) + nodeCounter(tree->right) + 1;
}

/*****************************************************
*   BinarySearchTree()
*
*   BinarySearchTree print_inorder Function Method
*/
void BinarySearchTree::print_inorder()
{
    inorder(root);
}
void BinarySearchTree::inorder(Node* ptr)
{
    if(ptr != NULL)
    {
        if(ptr->left) 
            inorder(ptr->left);
        cout << " " << ptr->data << ",";
        if(ptr->right) 
            inorder(ptr->right);
    }
    else return;
}

/*****************************************************
*   BinarySearchTree()
*
*   BinarySearchTree print_preorder Function Method
*/
void BinarySearchTree::print_preorder()
{
    preorder(root);
}
void BinarySearchTree::preorder(Node* ptr)
{
    if(ptr != NULL)
    {
        cout << " " << ptr->data << ",";
        if(ptr->left) 
            preorder(ptr->left);
        if(ptr->right) 
            preorder(ptr->right);
    }
    else return;
}

/*****************************************************
*   BinarySearchTree()
*
*   BinarySearchTree print_postorder Function Method
*/
void BinarySearchTree::print_postorder()
{
    postorder(root);
}
void BinarySearchTree::postorder(Node* ptr)
{
    if(ptr != NULL)
    {
        if(ptr->left) 
            postorder(ptr->left);
        if(ptr->right) 
            postorder(ptr->right);
        cout << " " << ptr->data << ",";
    }
    else return;
}

#endif