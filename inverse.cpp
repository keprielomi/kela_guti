#include <iostream>
using namespace std;

class Matrix3x3 {
private:
    double mat[3][3];
    double minorMat[3][3];
    double cofactorMat[3][3];
    double transposeMat[3][3];
    double inverseMat[3][3];

    // Determinant of 2x2
    double det2x2(double a, double b, double c, double d) {
        return a*d - b*c;
    }

    // Compute determinant of 3x3
    double det3x3() {
        return mat[0][0]*(mat[1][1]*mat[2][2]-mat[1][2]*mat[2][1])
             - mat[0][1]*(mat[1][0]*mat[2][2]-mat[1][2]*mat[2][0])
             + mat[0][2]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0]);
    }

public:
    // Read matrix
    void readMatrix() {
        cout << "Enter elements of 3x3 matrix:\n";
        for (int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout << "A["<<i<<"]["<<j<<"]: ";
                cin >> mat[i][j];
            }
        }
    }

    // Display matrix
    void displayMatrix() {
        cout << "\nMatrix:\n";
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    // Compute minor matrix
    void computeMinor() {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                double sub[2][2];
                int p=0,q=0;
                for(int r=0;r<3;r++){
                    for(int c=0;c<3;c++){
                        if(r!=i && c!=j){
                            sub[p][q++] = mat[r][c];
                            if(q==2){q=0;p++;}
                        }
                    }
                }
                minorMat[i][j] = det2x2(sub[0][0], sub[0][1], sub[1][0], sub[1][1]);
            }
        }
    }

    void displayMinor() {
        cout << "\nMinor of the matrix:\n";
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                cout << minorMat[i][j] << " ";
            cout << endl;
        }
    }

    // Compute cofactor matrix
    void computeCofactor() {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cofactorMat[i][j] = ((i+j)%2==0 ? 1 : -1) * minorMat[i][j];
            }
        }
    }

    // Compute transpose (used for adjoint)
    void computeTranspose() {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                transposeMat[j][i] = cofactorMat[i][j];
    }

    void displayTranspose() {
        cout << "\nTranspose (Adjoint) of cofactor matrix:\n";
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                cout << transposeMat[i][j] << " ";
            cout << endl;
        }
    }

    // Compute inverse
    void computeInverse() {
        double det = det3x3();
        if(det == 0){
            cout << "\nInverse does not exist (determinant = 0).\n";
            return;
        }

        computeMinor();
        computeCofactor();
        computeTranspose(); // Adjoint

        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                inverseMat[i][j] = transposeMat[i][j] / det;

        cout << "\nInverse of the matrix:\n";
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                cout << inverseMat[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix3x3 A;
    A.readMatrix();
    A.displayMatrix();
    A.computeInverse();

    return 0;
}
