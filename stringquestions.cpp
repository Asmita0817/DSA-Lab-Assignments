#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to concatenate two strings
void concatenateStrings() {
    string str1, str2;
    cout << "Enter first string: ";
    cin.ignore();
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    cout << "Concatenated String: " << str1 + str2 << endl;
}

// Function to reverse a string
void reverseString() {
    string str;
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, str);
    reverse(str.begin(), str.end());
    cout << "Reversed String: " << str << endl;
}

// Function to delete vowels from a string
void deleteVowels() {
    string str, result = "";
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, str);
    for (char ch : str) {
        char lower = tolower(ch);
        if (!(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'))
            result += ch;
    }
    cout << "String without vowels: " << result << endl;
}

// Function to sort strings in alphabetical order
void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();
    string arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, arr[i]);
    }
    sort(arr, arr + n);
    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

// Function to convert uppercase to lowercase
void upperToLower() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    if (isupper(ch))
        cout << "Lowercase: " << char(tolower(ch)) << endl;
    else
        cout << "The entered character is not uppercase.\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== STRING OPERATIONS MENU =====\n";
        cout << "1. Concatenate Strings\n";
        cout << "2. Reverse a String\n";
        cout << "3. Delete all Vowels from String\n";
        cout << "4. Sort Strings Alphabetically\n";
        cout << "5. Convert Uppercase to Lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: concatenateStrings(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStrings(); break;
            case 5: upperToLower(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
