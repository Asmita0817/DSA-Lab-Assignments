#include <iostream>
#include <algorithm> // for std::binary_search, std::lower_bound, std::upper_bound
using namespace std;

/*
---------------------------------------------------------
Method 1: Iterative Binary Search
---------------------------------------------------------
- Uses a while loop to repeatedly divide the array into halves
- Time Complexity: O(log n)
*/
int binarySearchIterative(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

/*
---------------------------------------------------------
Method 2: Recursive Binary Search
---------------------------------------------------------
- Function calls itself on a smaller portion of the array
- Time Complexity: O(log n)
*/
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, right, key);
    else
        return binarySearchRecursive(arr, left, mid - 1, key);
}

/*
---------------------------------------------------------
Method 3: Using STL binary_search()
---------------------------------------------------------
- Returns true if the element is present, false otherwise
- Time Complexity: O(log n)
*/
bool binarySearchSTL(int arr[], int n, int key) {
    return binary_search(arr, arr + n, key);
}

/*
---------------------------------------------------------
Method 4: Using lower_bound() and upper_bound()
---------------------------------------------------------
- lower_bound() returns the pointer to the first element 
  that is >= key
- If *iterator == key, element exists, else not found
- Time Complexity: O(log n)
*/
int binarySearchLowerBound(int arr[], int n, int key) {
    auto it = lower_bound(arr, arr + n, key);
    if (it != arr + n && *it == key) 
        return it - arr; // index
    else 
        return -1; // not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    cout << "\n--- Binary Search Implementations ---\n";

    // Method 1: Iterative
    int idx1 = binarySearchIterative(arr, n, key);
    if (idx1 != -1)
        cout << "Method 1 (Iterative): Found at index " << idx1 << "\n";
    else
        cout << "Method 1 (Iterative): Not found\n";

    // Method 2: Recursive
    int idx2 = binarySearchRecursive(arr, 0, n - 1, key);
    if (idx2 != -1)
        cout << "Method 2 (Recursive): Found at index " << idx2 << "\n";
    else
        cout << "Method 2 (Recursive): Not found\n";

    // Method 3: STL binary_search
    if (binarySearchSTL(arr, n, key))
        cout << "Method 3 (STL binary_search): Found\n";
    else
        cout << "Method 3 (STL binary_search): Not found\n";

    // Method 4: STL lower_bound
    int idx4 = binarySearchLowerBound(arr, n, key);
    if (idx4 != -1)
        cout << "Method 4 (STL lower_bound): Found at index " << idx4 << "\n";
    else
        cout << "Method 4 (STL lower_bound): Not found\n";

    return 0;
}
