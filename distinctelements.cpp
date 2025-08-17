#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> distinctElements; // stores only unique values

    for (int i = 0; i < n; i++) {
        distinctElements.insert(arr[i]);
    }

    cout << "Total number of distinct elements: " << distinctElements.size() << endl;

    return 0;
}
