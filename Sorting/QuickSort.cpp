/*
QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and 
partitions the given array around the picked pivot by placing the pivot in its correct position in the
sorted array. 



There are mainly three steps in the algorithm:

1) Choose a Pivot: Select an element from the array as the pivot.The choice of pivot can vary 
(e.g., first element, last element, random element, or median).

2) Partition the Array: Re arrange the array around the pivot. After partitioning, all elements smaller than the 
pivot will be on its left, and all elements greater than the pivot will be on its right.


3) Recursively Call: Recursively apply the same process to the two partitioned sub-arrays.

4) Base Case: The recursion stops when there is only one element left in the sub-array, as a single element
is already sorted.


*/

#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> & arr, int st,int end){
    int idx=st-1 , pivot=arr[end];

    for(int j=st;j<end;j++){
        if(arr[j] <= pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }

    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
    
}

void Quick_sort(vector<int> & arr, int st,int end){
    if(st<end){
        int piv_indx=partition(arr,st,end);
        Quick_sort(arr,st,piv_indx-1);// left
        Quick_sort(arr,piv_indx+1,end); // right
    }

}
int main()
{  
    vector<int> arr ={5,2,6,4,1,3};
    Quick_sort(arr,0,arr.size()-1);

    for (int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;
    
    



    return 0;
}
