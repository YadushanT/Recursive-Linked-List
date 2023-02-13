/* BME 122 - Assignment 1
 * Group Members: Raiyan Aaijaz, Yadushan Thurairasa 21005628, Mekhael Thaha, Ayaan Iqbal
 */

/*
Write a full C++ code and submit the CPP file.
Use ADT to make a vanilla linked list that have the following features:
- A structure for Node
- A class for linked list
- An integer data and a pointer in each node
- A method in the linked list class that uses recursion to insert a new node at the end of the list with a given integer value.
- A method to print out all the list.
- A main function that shows all the functionalities.
- Explain in a commend that what are the base case(s) and the recursion.
- Add appropriate comments to your code.
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef Node* NodePtr;

class linkedList
{
public:
    NodePtr head = new Node;  // Create the head node

    void insertNode(NodePtr &head); // Function to add node to the end of the list
    void printAll(NodePtr &head);   // Function to print out the list
};

//recursive base case: set head node data to num, head next pointer to NULL. Delete the temp pointer created since the user only want 1 node.
void linkedList::insertNode(NodePtr &head)
{
    int num;
    char value;

    cout << "Enter the number: ";
    cin >> num;

    head->data = num; // Set data of head node to num as inputted by user

    NodePtr temp = new Node; // Base case is adding a node after the head node
    temp->next = NULL;
    head->next = temp;

    cout << "Enter Y to add another number or enter N to exit: ";
    cin >> value;

    if (value == 'Y')
    {
        insertNode(temp); 
        // Recursion occurs when user wants to add a new number to the list
    }

    if (value == 'N')
    {
        head->next = NULL; //set the last node of the list to NULL
        delete temp; //delete the temp node and release memory back to free store
        return;
    }
}

void linkedList::printAll(NodePtr &head)
{
    NodePtr temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl; // When the temp node next is not NULL, output the data of the node
        temp = temp->next;
    }
}

int main()
{
    linkedList List; // Initializes object, Creates the head of your list

    List.insertNode(List.head);

    cout << "Here is your list:" << endl;
    List.printAll(List.head);
}