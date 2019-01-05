/*****************************************************
*   BinarySearchTree.h
*
*   Dustin Meckley
*   ciss350
*   07/24/15
*/

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
#include <stddef.h>
#include <cstdlib>

using namespace std;

class BinarySearchTree
{
    // ----------------------------------------------------
    //                         Class Members:
    // ----------------------------------------------------
    private:
        struct Node
        {
           Node* left;
           Node* right;
           int data;

        };
        Node* root;

    // -----------------------------------------------------
    //                Private Class Methods: 
    // -----------------------------------------------------
        // Iterative Methods:
        // -------------------- 
        void clearTree(Node*);              // Used with clear()
        int nodeCounter(Node*);             // Used with getLength()
        void postorder(Node*);              // Used with print_postorder()
        void inorder(Node*);                // Used with print_inorder()
        void preorder(Node*);               // Used with print_preorder()
        void getNodeLevel(int, Node*);      // Utilizes the getNode()
        void displayMatch(int);             // Utilizes the getNode()


    public:
    // -----------------------------------------------------
    //                Public Class Methods: 
    // -----------------------------------------------------
        // Constructor and Destructor:
        // ---------------------------
        BinarySearchTree();                             
        ~BinarySearchTree();                            

        // Observer Methods:
        // --------------------
        bool isEmpty() const;                          
        bool isFull() const;  
        

        // Transformer Methods:
        // --------------------
        void addNode(int); 
        void getNode(int);                  // Utilizes the getNodeLevel() & displayMatch()
        int getLength();                    // Utilizes the nodeCounter()
        void removeNode(int);   
        void clear();                       // Utilizes the clearTree()            
        
        // Printing Methods:
        // --------------------
        void print_inorder();               // Utilizes the inorder()      
        void print_preorder();              // Utilizes the preorder()     
        void print_postorder();             // Utilizes the postorder()        
};

#endif