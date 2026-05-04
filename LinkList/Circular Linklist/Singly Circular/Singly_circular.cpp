#include <iostream>
using namespace std;

/********** SINGLE CIRCULAR LINKED LIST **********/ 



// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

/*  INSERT AT START  */
void insertAtStart(int n) 
{
    Node* newNode = new Node();
    newNode->data = n;
    newNode->next = head;

    if (head==NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

}
/*  INSERT AT END  */
void insertAtEnd(int n) 
{
    Node* newNode = new Node();
    newNode->data = n;
    newNode->next = head;

    if (head==NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

}

void insertAtPosition(int pos, int n) {
    Node* newNode = new Node();
    newNode->data = n;

    if (pos == 1) {
        insertAtStart(n);
        return;
    }

    Node* temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head && count < pos - 1) // Position is out of bounds
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtStart() {
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
    else {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next; // Move head to the next node
        last->next = head; // Update the last node to point to the new head
        delete temp; // Delete the old head
    }

    

} 

void deleteAtEnd() {
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
    else {
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head; // Update the second last node to point to head
        delete temp; // Delete the last node
    }

}  

void deleteAtPosition(int pos) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete" << endl;
        return;
    }

    if (pos == 1) {
        deleteAtStart();
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    int count = 1;
    while (count < pos && temp->next != head) 
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp->next == head && count < pos) // Position is out of bounds
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    prev->next = temp->next; // Update the previous node to skip the deleted node   
    delete temp; // Delete the node at the specified position
}


void Search(int key) {
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



void print() {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } 
    while (temp != head);
    cout << "HEAD" << endl;
}
  


int main(){

    insertAtStart(4);
    insertAtStart(3);
    insertAtStart(2);
    insertAtStart(1);
    insertAtEnd(5);
    insertAtPosition(4, 8);
    deleteAtStart();
    deleteAtEnd();
    deleteAtPosition(3);
    deleteAtPosition(4); // Invalid position
    Search(10); //  Element not found
    Search(3); // Element found at position 2

    print();
   
   


    return 0;
}
