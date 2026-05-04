#include<iostream>
using namespace std;

/********** DOUBLY CIRCULAR LINKED LIST **********/ 


// Node structure for Doubly Linked List
struct Node {
    int data;      // stores data
    Node* prev;    // pointer to previous node
    Node* next;    // pointer to next node
};

Node* head = NULL;


/*  INSERT AT START  */
void insertAtStart(int n) {
    Node* newNode = new Node();   // create new node
    newNode->data = n;            // assign data
    
    // If list is empty
    if (head == NULL)  // first node
    {
        
        newNode->next = newNode; // Point to itself to make it circular
        newNode->prev = newNode; // Point to itself to make it circular
        head = newNode;
    }
     else 
    {
        Node* last = head->prev; // Get the last node

        newNode->next = head; // New node points to current head
        newNode->prev = last; // New node's previous points to last node
        last->next = newNode; // Last node's next points to new node
        head->prev = newNode; // Current head's previous points to new node
        head = newNode;       // Update head to the new node
    }
}
  


/*  INSERT AT END  */
void insertAtEnd(int n) {
    Node* newNode = new Node();   // create new node
    newNode->data = n;            // assign data
    
    // If list is empty
    if (head == NULL)  // first node
    {
        
        newNode->next = newNode; // Point to itself to make it circular
        newNode->prev = newNode; // Point to itself to make it circular
        head = newNode;
    }
     else 
    {
        Node* last = head->prev; // Get the last node

        newNode->next = head; // New node points to current head
        newNode->prev = last; // New node's previous points to last node
        last->next = newNode; // Last node's next points to new node
        head->prev = newNode; // Current head's previous points to new node
    }
}

void insertAtPosition(int n,int pos)
{
    Node* newNode = new Node();   // create new node
    newNode->data = n;            // assign data
    
    if (pos==1)
    {
        insertAtStart(n);
        return;
    }
    Node*temp=head;
    int count=1;

    while (count<pos-1 && temp->next!=head)
    {
        temp=temp->next;
        count++;
    }
    if (temp->next==head && count<pos-1) // position is out of bounds
    {
        cout<<"Invalid position"<<endl;
        return;
    }

    Node* NextNode = temp->next; // Store the next node
    newNode->next=NextNode; // New node's next points to temp's next
    newNode->prev= temp;       // New node's previous points to temp
    NextNode->prev = newNode; // Temp's next's previous points to new node
    temp->next= newNode;       // Temp's next points to new node

}
void DeleteAtstart()
{
     if (head == NULL) 
    {
        cout << "The list is empty, nothing to delete" << endl;
        return;
    }
    Node* temp = head;

    if (temp->next == head) // Only one node in the list
    {
       
        delete temp;
        head = NULL;
        return;
    }
     else 
    {   Node* temp = head;
        Node* last = head->prev; // Get the last node
        head = head->next; // Move head to the next node
        last->next = head; // Update the last node to point to the new head
        delete temp; // Delete the old head
    }

     

}

void DeleteAtEnd() {
    if (head == NULL) 
    {
        cout << "The list is empty, nothing to delete" << endl;
        return;
    }
    Node* temp = head;

    if (temp->next == head) // Only one node in the list
    {
        delete temp;
        head = NULL;
        return;
    }
    else 
    {   Node* temp = head->prev; // Get the last node
        Node* secondlast = temp->prev; // Get the second last node
        secondlast->next = head;   // Update the second last node to point to head
        head->prev = secondlast;   // Update head's previous to point to second last node
        delete temp;   // Delete the last node
    }

}  


void DeleteAtPosition(int pos) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete" << endl;
        return;
    }

    if (pos == 1) {
        DeleteAtstart();
        return;
    }

    Node* temp = head;
    
    int count = 1;
    while (count < pos && temp->next != head) 
    {
       
        temp = temp->next;
        count++;
    }

    if (count!=pos) // Position is out of bounds
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    Node* prevNode = temp->prev; // Get the previous node
    Node* nextNode = temp->next; // Get the next node
    prevNode->next = nextNode; // Update the previous node to point to the next node
    nextNode->prev = prevNode; // Update the next node to point to the previous node
    delete temp; // Delete the node at the specified position

    if (temp == head) // If the deleted node is head, update head
    {
        head = nextNode;
    }
}


void Search(int key) 
{
    if (head == NULL) {
        cout << "The list is empty, element not found" << endl;
        return;
    }

    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << "Element " << key << " not found" << endl;
}






void print()
{
    if (head==NULL)
    {
        cout<<"the list is Empty nothing to print"<<endl;
        return;
    }
    Node*temp=head;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    } while (temp!=head);
    cout<<"HEAD"<<endl;
    
}



int main()
{
    insertAtStart(5);
    insertAtStart(4);
    insertAtStart(3);
    insertAtStart(2);
    insertAtStart(1);
    // insertAtEnd(6);
    // insertAtEnd(7);
    // insertAtPosition(8,4); // Insert 8 at position 4
    // insertAtPosition(7,10);  // Insert 7 at position 10 (out of bounds)
    // DeleteAtstart();
    // DeleteAtEnd();
    // DeleteAtPosition(3); // Delete node at position 3
    // DeleteAtPosition(10); // Delete node at position 10 (out of bounds)

    Search(4); // Search for element 4
    Search(10); // Search for element 10 (not found)
    print();
    return 0;
}