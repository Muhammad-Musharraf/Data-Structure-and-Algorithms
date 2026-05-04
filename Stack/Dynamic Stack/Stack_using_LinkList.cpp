#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
Node*top=NULL;
void Push(int x)
{
    Node*newNode=new Node();
    newNode->data=x;
    newNode->next=top;
    top=newNode;
    cout<< x <<" pushed in stack"<<endl;

}
void Pop()
{
    if (top==NULL)
    {
        cout<<"the stack is Empty Nothing To Delete"<<endl;
        return;
    }
    Node *temp=top;
    cout<<"the Poped Element is: "<<temp->data<<endl;
    top=top->next;
    delete temp;

}
int peak()
{
    if (top==NULL)
    {
        cout<<"the stack is Empty Nothing To Delete"<<endl;
        return -1;
    }
    return top->data;
}
void display()
{
    if (top==NULL)
    {
        cout<<"the stack is Empty Nothing To Delete"<<endl;
        return;
    }
    cout<<"Stacked Element are:"<<endl;
    Node*temp=top;
    while (temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
        
    }
    


}



int main()
{
    Push(45);
    Push(55);
    Push(67);
    Push(88);
    display();

    Pop();
    cout<<"The Top element of Stack is: "<< peak()<<endl;
    display();


    return 0;
}