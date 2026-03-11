#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Head pointer
Node* head = NULL;

/* INSERT AT END */
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* DISPLAY LIST */
void display() {
    Node* temp = head;
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/* SEARCH ELEMENT */
void search(int key) {
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
    cout << "Element not found\n";
}

/* DELETE ELEMENT */
void deleteNode(int key) {
    Node* temp = head;
    Node* prev = NULL;

    // If head node is to be deleted
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        delete temp;
        cout << "Node deleted\n";
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Element not found\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Node deleted\n";
}

/* MAIN FUNCTION */
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    cout << "Linked List: ";
    display();

    search(20);
    deleteNode(30);

    cout << "After deletion: ";
    display();

    return 0;
}
