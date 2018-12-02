#include <iostream>
#include <iomanip>

using namespace std;

bool invertible = true;

void getMatrix(double matrix[5][5]) {
    for (int i=0; i<5; i++) {
        cout << "Masukkan matrix baris ke-" << i+1 << " : ";
        for (int j=0; j<5; j++) {
            cin >> matrix[i][j];
        }
    }
}

void inverseMatrix(double inverse[5][5], double matrix[5][5]) {

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            inverse[i][j] = (i==j)? 1 : 0;
        }
    }

    for (int i=0; i<5 && invertible; i++) {
        if (matrix[i][i] == 0) {
            invertible = false;
            for (int j=i+1; j < 5 && i < 4; j++) {
                if (matrix[j][i] != 0) {
                    for (int k=0; k<5; k++) {
                        double temp = matrix[j][k];
                        matrix[j][k] = matrix[i][k];
                        matrix[i][k] = temp;

                        temp = inverse[j][k];
                        inverse[j][k] = inverse[i][k];
                        inverse[i][k] = temp;
                    }
                    invertible = true;
                    break;
                }
            }
        }

        if (matrix[i][i] != 1) {

            if (invertible) {
                double temp = matrix[i][i];
                for (int j=0; j<5; j++) {
                    matrix[i][j] /= temp;
                    inverse[i][j] /= temp;
                }
            }
        }

        if (i < 4 && invertible) {
            for (int j=i+1; j<5; j++) {
                double pengurang = matrix[j][i];
                // cout << "Pengurang : " << pengurang << endl;
                for (int k=0; k<5; k++) {
                    matrix[j][k] -= pengurang*matrix[i][k];
                    inverse[j][k] -= pengurang*inverse[i][k];
                    // cout << matrix[j][k] << "\t";
                }
                // cout << endl;
            }
        }
    }

    for (int i=4; i>=0 && invertible; i--) {
        if (i > 0) {
            for (int j=i-1; j>=0; j--) {
                double pengurang = matrix[j][i];
                for (int k=4; k>=0; k--) {
                    matrix[j][k] -= pengurang*matrix[i][k];
                    inverse[j][k] -= pengurang*inverse[i][k];
                }
            }
        }
    }
}

int main() {
    double matrix[5][5], inverse[5][5];
    getMatrix(matrix);
    
    cout << endl << "===<Matrix>===" << endl;

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }

    inverseMatrix(inverse, matrix);

    cout << endl << "===<Identitas>===" << endl;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl << "===<Inverse>===" << endl;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cout << setw(15) << inverse[i][j];
        }
        cout << endl;
    }

    cout << endl << "Invertible : " << invertible << endl;
    
}