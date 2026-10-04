#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int maxSum = INT_MIN;

    int calculateMaxPath(TreeNode* node) {
        if (!node) return 0; 
        int leftGain = max(0, calculateMaxPath(node->left));
        int rightGain = max(0, calculateMaxPath(node->right)); 
        int currentPathSum = node->val + leftGain + rightGain; 
        maxSum = max(maxSum, currentPathSum); 
        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        calculateMaxPath(root);
        return maxSum;
    }
};

int main() { 
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << " (Expected: 42)\n";

    return 0;
}