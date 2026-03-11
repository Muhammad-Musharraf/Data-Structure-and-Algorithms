#include <iostream>
using namespace std;
int Queue[5], n=5 , x , y , front=-1,rear=-1;

void insert()
{
    if(rear==n-1){
        cout<<"Queue is Full"<<endl;
    }
    else{
        if(front==-1){
            front=0;
        }
        cout<<"Queue of Element are Insert: ";
        cin>>x;
        rear++;
        Queue[rear]=x;
    }
}


void Delete()
{
    if(front==-1){
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        cout<<"Element Deleted from Queue is "<<Queue[front]<<endl;
        if(front==rear){
            front=-1;
            rear=-1;
        }
        front++;
    }
}

void Display()
{
    if(front==-1){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Queue Element are:"<<endl;
        for(int i=front;i<=rear;i++)
        {
            cout<<Queue [i] <<endl;

        }   
    
    
    }

}
int Peek()
{
     if(front==-1){
        return 0;
    }
    else{
        return Queue[front];
    }

}


int main(){
    insert();
    insert();
    insert();
    insert();
    insert();
    Display();
    //insert();
    // Delete();
    // Delete();
    // Delete();
    // Delete();
    // Delete();
    // Delete();
    y=Peek();
    if(y==0) {
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Front Element of the queue is "<<y <<endl;
    }
    








    return 0;
}
