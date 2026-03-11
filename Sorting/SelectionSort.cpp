/*


Selection Sort is a comparison-based sorting algorithm. It sorts by 
repeatedly selecting the smallest (or largest) element from the unsorted 
portion and swapping it with the first unsorted element.


*/

#include <iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int smallestidx=i;
        for (int j=i+1;j<n;j++){// unsorted part sorting
            if(arr[j]<arr[smallestidx]){
                smallestidx=j;
               
                
            }
        }
        swap(arr[i], arr[smallestidx]);

        
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
    selectionsort(arr,n);
    printArray(arr,n);
    

    return 0;
}