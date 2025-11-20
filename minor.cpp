#include <iostream>
using namespace std;

class Matrix3x3 {
private:
    double mat[3][3];
    double minorMat[3][3];

    double det2x2(double a, double b, double c, double d) {
        return a * d - b * c;
    }

public:
    void readMatrix() {
        cout << "Enter elements of 3x3 matrix:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "A[" << i << "][" << j << "]: ";
                cin >> mat[i][j];
            }
        }
    }

    void displayMatrix() {
        cout << "\nMatrix:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
    void computeMinor() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                double sub[2][2];
                int p = 0, q = 0;
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        if (r != i && c != j) {
                            sub[p][q++] = mat[r][c];
                            if (q == 2) { q = 0; p++; }
                        }
                    }
                }
                minorMat[i][j] = det2x2(sub[0][0], sub[0][1], sub[1][0], sub[1][1]);
            }
        }
    }
    void displayMinor() {
        cout << "\nMinor of the matrix:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << minorMat[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix3x3 A;
    A.readMatrix();    
    A.displayMatrix();   
    A.computeMinor();   
    A.displayMinor();    

    return 0;
}
