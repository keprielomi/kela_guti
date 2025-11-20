#include <iostream>
using namespace std;

class Matrix {
private:
    int mat[10][10];
    int rows, cols;

public:
    void readMatrix() {
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "A[" << i << "][" << j << "]: ";
                cin >> mat[i][j];
            }
        }
    }

    void displayMatrix() {
        cout << "\nMatrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    // transpose
    void displayTranspose() {
        int T[10][10];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                T[j][i] = mat[i][j];

        cout << "\nTranspose of the matrix:\n";
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++){
                cout << T[i][j] << "\t ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix A;
    A.readMatrix();       
    A.displayMatrix();     
    A.displayTranspose();

    return 0;
}
