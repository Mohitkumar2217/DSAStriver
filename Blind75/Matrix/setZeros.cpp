#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row(matrix.size(), 0);
        vector<int> col(matrix[0].size(), 0);

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
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
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    sol.setZeroes(matrix);

    cout << "\nModified Matrix:\n";
    printMatrix(matrix);

    return 0;
}