/*
Insertion sort is a simple sorting algorithm that works by iteratively inserting each 
element of an unsorted list into its correct position in a sorted portion of the list.
It is like sorting playing cards in your hands. You split the cards into two groups: 
the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group
 and put it in the right place in the sorted group.



> Start with the second element as the first element is assumed to be sorted.
> Compare the second element with the first if the second is smaller then swap them.
> Move to the third element, compare it with the first two, and put it in its correct position
> Repeat until the entire array is sorted.

*/


#include <iostream>
using namespace std;
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++) {
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;// placing the curr el in its correct position.
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
    int arr[]={4,1,5,2,3};
    insertionsort(arr,n);
    printArray(arr,n);
    

    return 0;
}