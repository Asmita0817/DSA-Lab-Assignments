#include <iostream>
using namespace std;

#define MAX 100

struct SparseMatrix {
    int data[MAX][3]; // triplet form
    int rows, cols, nonZero;
};

// Function to read a sparse matrix
void readSparse(SparseMatrix &s) {
    cout << "Enter rows, cols, non-zero elements: ";
    cin >> s.rows >> s.cols >> s.nonZero;

    s.data[0][0] = s.rows;
    s.data[0][1] = s.cols;
    s.data[0][2] = s.nonZero;

    cout << "Enter row, col, value for each non-zero element:\n";
    for (int i = 1; i <= s.nonZero; i++) {
        cin >> s.data[i][0] >> s.data[i][1] >> s.data[i][2];
    }
}

// Function to display a sparse matrix
void displaySparse(SparseMatrix s) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= s.nonZero; i++) {
        cout << s.data[i][0] << "   " << s.data[i][1] << "   " << s.data[i][2] << "\n";
    }
}

// (a) Transpose of a Sparse Matrix
SparseMatrix transposeSparse(SparseMatrix s) {
    SparseMatrix t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.nonZero = s.nonZero;

    t.data[0][0] = t.rows;
    t.data[0][1] = t.cols;
    t.data[0][2] = t.nonZero;

    int k = 1;
    for (int col = 0; col < s.cols; col++) {
        for (int i = 1; i <= s.nonZero; i++) {
            if (s.data[i][1] == col) {
                t.data[k][0] = s.data[i][1];
                t.data[k][1] = s.data[i][0];
                t.data[k][2] = s.data[i][2];
                k++;
            }
        }
    }
    return t;
}

// (b) Addition of Two Sparse Matrices
SparseMatrix addSparse(SparseMatrix a, SparseMatrix b) {
    SparseMatrix sum;
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Matrices cannot be added!\n";
        sum.nonZero = 0;
        return sum;
    }

    sum.rows = a.rows;
    sum.cols = a.cols;

    int i = 1, j = 1, k = 1;
    while (i <= a.nonZero && j <= b.nonZero) {
        if (a.data[i][0] < b.data[j][0] ||
           (a.data[i][0] == b.data[j][0] && a.data[i][1] < b.data[j][1])) {
            sum.data[k][0] = a.data[i][0];
            sum.data[k][1] = a.data[i][1];
            sum.data[k][2] = a.data[i][2];
            i++; k++;
        } else if (b.data[j][0] < a.data[i][0] ||
                  (b.data[j][0] == a.data[i][0] && b.data[j][1] < a.data[i][1])) {
            sum.data[k][0] = b.data[j][0];
            sum.data[k][1] = b.data[j][1];
            sum.data[k][2] = b.data[j][2];
            j++; k++;
        } else { // Same position
            int val = a.data[i][2] + b.data[j][2];
            if (val != 0) {
                sum.data[k][0] = a.data[i][0];
                sum.data[k][1] = a.data[i][1];
                sum.data[k][2] = val;
                k++;
            }
            i++; j++;
        }
    }

    while (i <= a.nonZero) {
        sum.data[k][0] = a.data[i][0];
        sum.data[k][1] = a.data[i][1];
        sum.data[k][2] = a.data[i][2];
        i++; k++;
    }
    while (j <= b.nonZero) {
        sum.data[k][0] = b.data[j][0];
        sum.data[k][1] = b.data[j][1];
        sum.data[k][2] = b.data[j][2];
        j++; k++;
    }

    sum.nonZero = k - 1;
    sum.data[0][0] = sum.rows;
    sum.data[0][1] = sum.cols;
    sum.data[0][2] = sum.nonZero;
    return sum;
}

// (c) Multiplication of Two Sparse Matrices
SparseMatrix multiplySparse(SparseMatrix a, SparseMatrix b) {
    SparseMatrix prod;
    if (a.cols != b.rows) {
        cout << "Matrices cannot be multiplied!\n";
        prod.nonZero = 0;
        return prod;
    }

    SparseMatrix bT = transposeSparse(b);
    prod.rows = a.rows;
    prod.cols = b.cols;
    int k = 1;

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < bT.rows; j++) {
            int sum = 0;
            for (int x = 1; x <= a.nonZero; x++) {
                if (a.data[x][0] == i) {
                    for (int y = 1; y <= bT.nonZero; y++) {
                        if (bT.data[y][0] == j && a.data[x][1] == bT.data[y][1]) {
                            sum += a.data[x][2] * bT.data[y][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                prod.data[k][0] = i;
                prod.data[k][1] = j;
                prod.data[k][2] = sum;
                k++;
            }
        }
    }

    prod.nonZero = k - 1;
    prod.data[0][0] = prod.rows;
    prod.data[0][1] = prod.cols;
    prod.data[0][2] = prod.nonZero;
    return prod;
}

int main() {
    SparseMatrix A, B;

    cout << "Enter first matrix:\n";
    readSparse(A);
    cout << "Enter second matrix:\n";
    readSparse(B);

    cout << "\nFirst Matrix (Triplet form):\n";
    displaySparse(A);
    cout << "\nSecond Matrix (Triplet form):\n";
    displaySparse(B);

    // Transpose
    cout << "\nTranspose of First Matrix:\n";
    displaySparse(transposeSparse(A));

    // Addition
    cout << "\nAddition of Matrices:\n";
    displaySparse(addSparse(A, B));

    // Multiplication
    cout << "\nMultiplication of Matrices:\n";
    displaySparse(multiplySparse(A, B));

    return 0;
}
