#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        if (matrix.empty()) return ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) { 
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;
 
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
 
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
 
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
 
void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "Matrix 1 Spiral Order:\n";
    vector<int> result1 = sol.spiralOrder(matrix1);
    printVector(result1);

    cout << "\nMatrix 2 Spiral Order:\n";
    vector<int> result2 = sol.spiralOrder(matrix2);
    printVector(result2);

    return 0;
}