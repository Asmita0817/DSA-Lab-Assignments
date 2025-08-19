#include <iostream>
using namespace std;

#define MAX 100

// Triplet form: row, col, value
struct Sparse {
    int row, col, val;
};

// Transpose
void transpose(Sparse a[], Sparse b[]) {
    int n = a[0].val; // number of non-zeros
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;

    int k = 1;
    for (int c = 0; c < a[0].col; c++) {
        for (int i = 1; i <= n; i++) {
            if (a[i].col == c) {
                b[k].row = a[i].col;
                b[k].col = a[i].row;
                b[k].val = a[i].val;
                k++;
            }
        }
    }
}

// Addition
void add(Sparse a[], Sparse b[], Sparse c[]) {
    int i=1, j=1, k=1;
    c[0].row = a[0].row;
    c[0].col = a[0].col;
    while (i<=a[0].val && j<=b[0].val) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        }
        else if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }
    while (i <= a[0].val) c[k++] = a[i++];
    while (j <= b[0].val) c[k++] = b[j++];
    c[0].val = k-1;
}

// Multiplication (basic)
void multiply(Sparse a[], Sparse b[], Sparse c[]) {
    int m = a[0].row, n = a[0].col;
    int p = b[0].row, q = b[0].col;
    if (n != p) {
        cout << "Matrix multiplication not possible!" << endl;
        return;
    }

    int k = 1;
    c[0].row = m; c[0].col = q;

    for (int i=1; i<=a[0].val; i++) {
        for (int j=1; j<=b[0].val; j++) {
            if (a[i].col == b[j].row) {
                c[k].row = a[i].row;
                c[k].col = b[j].col;
                c[k].val = a[i].val * b[j].val;
                k++;
            }
        }
    }
    c[0].val = k-1;
}
