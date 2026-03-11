/*

In Linear Search, we iterate over all the elements of the array and check if it the current element
is equal to the target element. If we find any element to be equal to the target element, then return 
the index of the current element. Otherwise, if no element is equal to the target element, then
return -1 as the element is not found. Linear search is also known as sequential search.


*/

#include <iostream>
using namespace std;

int main() {
    int num[6] = {10, 20, 23, 35, 40,23};
    int x;
    bool found = false;

    cout << "Enter the number you want to search: ";
    cin >> x;

    for (int i = 0; i < 6; i++) {
        if (num[i] == x) {
            cout << "Value found at index " << i << "\n";
            found = true;
            
        }
    }

    if (!found) {
        cout << "Value not found";
    }

    return 0;
}




   


