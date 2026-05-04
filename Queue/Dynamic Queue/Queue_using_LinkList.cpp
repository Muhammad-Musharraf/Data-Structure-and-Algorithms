#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
Node* front=NULL;
Node* rear=NULL;

void insert(int x)
{
    Node*newNode = new Node();
    newNode->data=x;
    newNode->next=NULL;
    if (rear==NULL)
    {
        front= rear = newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }   

}

void Delete()
{
    if (front==NULL)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    Node*temp=front;
    cout<<"Element deleted from Queue is: "<<front->data<<endl;
    front=front->next;
    if (front==NULL)
    {
        rear=NULL;
    }
    delete temp;

}
int peak()
{
    if (front==NULL)
    {
        cout<<"Queue is Empty"<<endl;
        return -1;
    }
    return front->data;
}


void display()
{
    if (front==NULL)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }

    cout<<"Queue Element are: "<<endl;

    Node* temp=front;

    while (temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    


}

int main()
{
    insert(22);
    insert(54);
    insert(77);
    display();

    int y=peak();
    if (y==-1)
    {
        cout<<"Queue is Empty"<<endl;
    }

    else
    {
        cout<<"The front element is : "<<y<<endl;
        
    }

    Delete();



    return 0;
}