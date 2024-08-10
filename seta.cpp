#include <iostream>
#include <vector>

using namespace std;

int determinant(vector<vector<int>> matrix, int n) {
    int det = 0;
    if (n == 1) {
        return matrix[0][0];
    }

    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    vector<vector<int>> minor(n - 1, vector<int>(n - 1));
    int sign = 1;

    for (int f = 0; f < n; f++) {
        int mi = 0;
        for (int i = 1; i < n; i++) {
            int mj = 0;
            for (int j = 0; j < n; j++) {
                if (j == f) continue;
                minor[mi][mj++] = matrix[i][j];
            }
            mi++;
        }
        det += sign * matrix[0][f] * determinant(minor, n - 1);
        sign = -sign;
    }

    return det;
}

int main() {
    int n;

    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int det = determinant(matrix, n);
    cout << "The determinant of the matrix is: " << det << endl;

    return 0;
}

