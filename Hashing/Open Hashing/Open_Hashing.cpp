#include <iostream>
using namespace std;

const int size = 5;

struct Node{
    int data;
    Node* next;
};
Node table[size];

void insert(int key){
    int count = 0;
    int index = key % size;

    if(table[index].data == -1){
        table[index].data = key;
        table[index].next = NULL;
    }
    else{
        Node* temp = &table[index];

        while(temp->next != NULL){
            temp = temp->next;
        }

        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = NULL;

        temp->next = newNode;
    }
    ;
}

void display(){
    for(int i = 0; i < size; i++){
        if(table[i].data == -1){
            cout << i << ": " << "NULL" << endl;
        }
        else{
            Node* temp = &table[i];

            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL";
        }
        cout << endl;
    }
}


int main(){

    for(int i = 0; i < size; i++){
        table[i].data = -1;
        table[i].next = NULL;
    }
    
    insert(9); // 4
    insert(19); // 0
    insert(13); // 3
    insert(27); // 2
    insert(29); // 1
    insert(21); // 1
    
    display();

    // search(9);

    return 0;
}