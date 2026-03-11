/*
Binary Search Algorithm:-


> Divide the search space into two halves by finding the middle index "mid". 
> Compare the middle of the search space with the key. 
> If the key is found at middle, the process is terminated.
> If the key is not found at middle, choose which half will be used as the next search space.

- If the key is smaller than the middle, then the left side is used for next search.
- If the key is larger than the middle, then the right side is used for next search.

>This process is continued until the key is found or the total search space is exhausted.



*/

#include <iostream>
using namespace std;


int main() {
    int num[11] = {10,20,30,40,45,50,60,77,77,80,90};
    int n = 11;
    int to_search;

    cout << "Enter the number: ";
    cin >> to_search;

    // Find first occurrence
    int l = 0, r = n - 1, mid;
    int first = -1;

    while (l <= r) {
        mid = (l + r) / 2;
        if (num[mid] == to_search) {
            first = mid;
            r = mid - 1;   // move left
        }
        else if (to_search > num[mid]) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    // Find last occurrence
    l = 0;
    r = n - 1;
    int last = -1;

    while (l <= r) {
        mid = (l + r) / 2;
        if (num[mid] == to_search) {
            last = mid;
            l = mid + 1;   // move right
        }
        else if (to_search > num[mid]) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    if (first != -1) {
        cout << "Value found " << (last - first + 1) << " times\n";
        cout << "First index: " << first << endl;
        cout << "Last index: " << last << endl;
    } else {
        cout << "Value not found\n";
    }

    return 0;
}


