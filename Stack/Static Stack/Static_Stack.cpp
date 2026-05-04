#include<iostream>
using namespace std;
int stack [5], n=5, top=-1;
 
void push(int x){
    if(top==n-1)
    cout<<"Stack is Full";
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top==-1){
        cout<<"Stack is Full";
    }
    else{
        cout<<"The Poped elements are: "<<stack[top]<<endl;
        top--;
    }
}
int peek(){
    return stack[top];
}
void display(){
    if(top>=0){
        cout<<"Stack element are:"<<endl;
        for(int i=top; i>=0; i--){
            cout<<stack[i]<<endl;
        }
    }
    else
    {
        cout<<"Stack is Full";
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    int y=peek();
    cout<<"The Top Element of the Stack is: "<<y<<endl;
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    // display();

    
  
  
  
  
  

    return 0;
}
