/* double Linklist:
A Doubly Linked List is a linked list in which each node has two pointers:

1) Previous pointer (prev) → points to the previous node
2) Next pointer (next) → points to the next node

This allows traversal in both directions.

-----> A doubly linked list is a linked list in which each node contains data,a pointer to the 
previous node, and a pointer to the next node.

*/
#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;      // stores data
    Node* prev;    // pointer to previous node
    Node* next;    // pointer to next node
};

// Head pointer
Node* head = NULL;

/* INSERT AT END */
void insert(int n) {
    Node* newNode = new Node();   // create new node
    newNode->data = n;            // assign data
    newNode->next = head;         // next pointer
    newNode->prev = NULL;         // previous pointer
    

    // If list is empty
    if (head != NULL) {
        head-> prev = newNode;       // new node becomes head
        
    }
    head = newNode;
}
void insert_At_End(int n)
{
    Node*newNode =new Node;
    newNode->data=n;
    newNode->next=NULL;
    newNode->prev=NULL;
    if (head==NULL)
    {
        head=newNode;
    } 
    else
    {
        Node*temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        temp->prev=temp;

        

    }
    

}
void print()
{  
    cout<<"Data element in a double linklist are: "<<endl;
    Node *temp =head;

    while (temp!=NULL)
        {
        cout<<temp->data<<endl;
        temp=temp->next;
        }
        

}
void delete_At_Begining()
{
    if (head==NULL)
    {
        cout<<"the list is Empty nothing delete"<<endl;
        return;
    }
    Node*temp =head;
    head=head->next;
    if (head!=NULL)
    {
        head->prev=NULL;
    }
    delete temp;   

}

void delete_At_End()
{ 
    if (head==NULL)
    {
        cout<<"the list is Empty nothing delete"<<endl;
        return;
    }

    Node*temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    if (temp->prev!=NULL)
    {
        temp->prev->next=NULL;
    }
    else
    {
        head=NULL;
            
    }
    delete temp;

}
void DeleteAtPosition(int pos)
{
    if(head == NULL)
    {
        cout << "List is Empty Nothing to Delete";
        return;
    }

    Node* temp = head;

    // Delete first node
    if(pos == 1)
    {
        head = head->next;
        if(head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
        return;
    }

    // Move to desired position
    for(int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Position " << pos << " Does Not Exist in the List";
        return;
    }

    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    if(temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    delete temp;
}

void traverse_Forward()
{ 
    Node*temp=head;
    while (temp != NULL)
    {
       cout<<temp->data<<" ";
       temp=temp->next;
    }
    
    


}
void traverse_BackForward()
{   
    // Move to last Node
    Node*temp=head;
    while (temp->next != NULL){
        temp=temp->next;
    }

    // traverse backward
    while (temp!=NULL)
    {
        
       cout<<temp->data<<" ";
       temp=temp->prev;
    }
    
    


}


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
    cout << "Element not found"<<endl;
}


int main()
{
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    //print();

    DeleteAtPosition(4);
    print();
    // insert_At_End(6);
    // delete_At_Begining();
    // delete_At_End();


    
    //traverse_Forward();
    // traverse_BackForward();
    //search(1);

    return 0;
}
