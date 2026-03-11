/*

Bubble Sort is the simplest sorting algorithm that works by repeatedly
swapping the adjacent elements if they are in the wrong order.This algorithm 
is not efficient for large data sets as its average and worst-case time 
complexity are quite high.


*/



#include <iostream>
using namespace std;

void bubblesort(int arr[],int n)
{
    bool isswap=false;
    
    for(int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isswap=true;
            }
        }
        
    }
    if(!isswap){
            cout<<"Sort Already exist\n";
        }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
     
    
}

int main() {
    int n=5;
    int arr[]={2,1,4,3,5};
    bubblesort(arr,n);
    printArray(arr,n);
    

    return 0;
}