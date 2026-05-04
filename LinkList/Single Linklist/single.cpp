#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Head pointer
Node* head = NULL;

/* INSERT AT START */
void insertAtStart(int n)
{
    Node* newNode = new Node();
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}

/* INSERT AT END */
void insertAtEnd(int n) 
{
    Node* newNode = new Node();
    newNode->data = n;
    newNode->next = NULL;

    if (head == NULL) 
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
/* Insert at Any Position  */
void insertAtPosition(int n, int pos) 
{
    Node* newNode = new Node();
    newNode->data = n;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Invalid position" << endl;
        delete newNode; // Clean up memory
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


/* SEARCH ELEMENT */
void search(int key) 
{
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found"<<endl;

}



/* DELETE Node*/
void deleteNode(int key) {
    Node* temp = head;
    Node* prev = NULL;

    // If head node is to be deleted
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        delete temp;
        cout << "Node deleted"<<endl;
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Element not found"<<endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Node deleted"<<endl;
}



/* DISPLAY LIST */
void display()
{
    Node* temp = head;
    if (head == NULL) {
        cout << "List is empty, nothing to display" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    
}



/* MAIN FUNCTION */
int main()
{
    insertAtStart(5);
    insertAtStart(4);
    insertAtStart(3);
    insertAtStart(2);
    insertAtStart(1);

    cout << "Linked List after inserting at start: ";
    display();

    insertAtEnd(8);
    cout << "Linked List after inserting at end: ";
    display();

    cout<<"Searching for element 3:"<<endl;
    search(3);
    cout<<"Searching for element 10: "<<endl;
    search(10); // element not found

    cout<<"Deleting element 8: "<<endl;
    deleteNode(8); // delete element 8

    cout<<"Inserting element 9 at position 3: "<<endl;
    insertAtPosition(9, 3); // insert element 9 at position 3

    cout << "Linked List after all operations: ";
    display();
    return 0;
}
