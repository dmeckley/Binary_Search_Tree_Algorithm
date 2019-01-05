/*****************************************************
*	main.cpp
*
*	Dustin Meckley
*	ciss350
*	7/24/15
*/

#include "BinarySearchTree.h"

/*****************************************************
*	main()
*
*	Test Driver for execution of program.
*****************************************************/
int main()
{
	// BinarySearchTree Object Instance
    BinarySearchTree tree;
    // Local Variable Declarations
    int choice, addInput, removeInput, searchInput;

    // Menu to be displayed for the users choice selection.
    while(1)
    {
    	// Menu for the user.
    	cout << endl << endl;
        cout << " Binary Search Tree Operations " << endl;
        cout << " ----------------------------- " << endl;
        cout << "  1. Add Node " << endl;
        cout << "  2. Remove Node " << endl;
        cout << "  3. Get Node " << endl;
        cout << "  4. Get Length " << endl;
        cout << "  5. Is Full? " << endl;
        cout << "  6. Clear Node " << endl;
        cout << "  7. Is Empty? " << endl;
        cout << "  8. In-Order Traversal " << endl;
        cout << "  9. Pre-Order Traversal " << endl;
        cout << " 10. Post-Order Traversal " << endl;
        cout << " 11. Exit " << endl;
        cout << " Enter your choice : ";
        cin >> choice;

       	// Execution based off of the users choice selection.
       	switch(choice)
       	{			// Add Node
           	case 1 : 
           			cout << endl;
           			cout << "       Add Node     " << endl;
           			cout << " -------------------" << endl;
           			cout << " Enter Number to be inserted : ";
                    cin >> addInput;
                    tree.addNode(addInput);
                    break;
                    
                    // Remove Node.
           	case 2 : 
           			cout << endl;
                    cout << "     Remove Node    " << endl;
                    cout << " -------------------" << endl;
           			cout << " Enter data to be deleted : ";
                    cin >> removeInput;
                    tree.removeNode(removeInput);
                    break;
                    
                    // Get Node.
           	case 3 : 
           			cout << endl;
                    cout << "       Get Node     " << endl;
                    cout << " -------------------" << endl;
           			cout << " Enter data to be found : ";
                    cin >> searchInput;
                    tree.getNode(searchInput);
                    break;

                    // Get Length.
           	case 4 : 
           			cout << endl;
                    cout << "       Get Length     " << endl;
                    cout << " -------------------" << endl;
                    cout << "tree.getLength = " << tree.getLength() << endl;
                    break;

                    // IsFull
           	case 5 : 
           			cout << endl;
                    cout << "       Is Full?     " << endl;
                    cout << " -------------------" << endl;
                    cout << "tree.isFull = " << tree.isFull() << endl;
                    break;

             		// Clear Node.
           	case 6 : 
           			cout << endl;
                    cout << "     Clear Node     " << endl;
                    cout << " -------------------" << endl;
                    tree.clear();
                    cout << "{ }" << endl;
                    break;

                    // IsEmpty
           	case 7 : 
           			cout << endl;
                    cout << "      Is Empty?     " << endl;
                    cout << " -------------------" << endl;
                    cout << "tree.isEmpty = " << tree.isEmpty() << endl;
                    break;

                    // Inorder Traversal
           	case 8 : 
           			cout << endl;
                    cout << " In-Order Traversal " << endl;
                    cout << " -------------------" << endl;
                    cout << "{";
                    tree.print_inorder();
                    cout << "}";
                    break;

                    // Preorder Traversal
           	case 9 : 
           			cout << endl;
                    cout << " Pre-Order Traversal " << endl;
                    cout << " -------------------" << endl;
                    cout << "{";
                    tree.print_preorder();
                    cout << "}";
                    break;

                    // Postorder Traversal
           	case 10 :
           			cout << endl;
                    cout << " Post-Order Traversal " << endl;
                    cout << " --------------------" << endl;
                    cout << "{";
                    tree.print_postorder();
                    cout << "}";
                   	break;

                    // Exit Execution of the application
           	case 11 : 
           			return 0;       
       }
    }
}