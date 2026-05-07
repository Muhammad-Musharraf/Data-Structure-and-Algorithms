#include <iostream>
using namespace std;

// UP-heapify (after insert)
void upHeapify(int arr[], int i){
    int parent = (i - 1) / 2;
    if (i > 0 && arr[i] > arr[parent]){
        swap(arr[i], arr[parent]);
        upHeapify(arr, parent);
    }
}

void downHeapify(int arr[], int size, int i){
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;
    if(right < size && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        downHeapify(arr, size, largest);
    }
}

void insert(int arr[], int &size, int value){
    arr[size] = value;
    upHeapify(arr, size);
    size++;
}

void deleteRoot(int arr[], int &size){
    if(size == 0){
        cout << "Heap empty!" << endl;
        return;
    }
    cout << "Deleted: " << arr[0] << endl;
    arr[0] = arr[size - 1];
    size--;
    downHeapify(arr, size, 0);
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        downHeapify(arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        downHeapify(arr, i, 0);
    }
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){

    int arr[100];
    int arr2[] = {32, 45, 21, 56, 39, 9, 1, 3};
    int size = 0;
    
    insert(arr, size, 9);
    insert(arr, size, 35);
    insert(arr, size, 48);
    insert(arr, size, 15);
    insert(arr, size, 23);
    insert(arr, size, 95);

    display(arr, size);

    heapSort(arr2, (sizeof(arr2) / sizeof(arr2[0])));
    display(arr2, (sizeof(arr2) / sizeof(arr2[0])));

    // deleteRoot(arr, size);
    // display(arr, size);

    return 0;
}