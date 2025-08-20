#include <iostream>
using namespace std;


// Diagonal Matrix
class Diagonal {
    int *A;
    int n;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x) {
        if (i == j) A[i-1] = x;
    }
    int get(int i, int j) {
        if (i == j) return A[i-1];
        return 0;
    }
    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == j) cout << A[i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};


// Lower Triangular Matrix

class LowerTriangular {
    int *A;
    int n;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) A[i*(i-1)/2 + (j-1)] = x;
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i-1)/2 + (j-1)];
        return 0;
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (i >= j) cout << get(i,j) << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};

// Upper Triangular Matrix

class UpperTriangular {
    int *A;
    int n;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i <= j) A[n*(i-1) - (i-2)*(i-1)/2 + (j-i)] = x;
    }
    int get(int i, int j) {
        if (i <= j) return A[n*(i-1) - (i-2)*(i-1)/2 + (j-i)];
        return 0;
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (i <= j) cout << get(i,j) << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};


// Symmetric Matrix

class Symmetric {
    int *A;
    int n;
public:
    Symmetric(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) A[i*(i-1)/2 + (j-1)] = x;
        else A[j*(j-1)/2 + (i-1)] = x; // store lower triangular only
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i-1)/2 + (j-1)];
        else return A[j*(j-1)/2 + (i-1)];
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

// Main Function

int main() {
    cout << "Diagonal Matrix Example:\n";
    Diagonal d(3);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,9);
    d.display();

    cout << "\nLower Triangular Matrix Example:\n";
    LowerTriangular lt(3);
    lt.set(1,1,1); lt.set(2,1,2); lt.set(2,2,3);
    lt.set(3,1,4); lt.set(3,2,5); lt.set(3,3,6);
    lt.display();

    cout << "\nUpper Triangular Matrix Example:\n";
    UpperTriangular ut(3);
    ut.set(1,1,1); ut.set(1,2,2); ut.set(1,3,3);
    ut.set(2,2,4); ut.set(2,3,5); ut.set(3,3,6);
    ut.display();

    cout << "\nSymmetric Matrix Example:\n";
    Symmetric sm(3);
    sm.set(1,1,1); sm.set(2,1,2); sm.set(2,2,3);
    sm.set(3,1,4); sm.set(3,2,5); sm.set(3,3,6);
    sm.display();

    return 0;
}
