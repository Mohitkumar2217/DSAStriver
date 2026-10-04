#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
 
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int temp = matrix[i][j]; 
                matrix[i][j] = matrix[n - 1 - j][i]; 
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]; 
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]; 
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};
 
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    sol.rotate(matrix);

    cout << "\nRotated Matrix (90 degrees clockwise):\n";
    printMatrix(matrix);

    return 0;
}