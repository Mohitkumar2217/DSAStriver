#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
 
        vector<int> dp(nums.size(), 1);
        int max_len = 1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(max_len, dp[i]);
        }

        return max_len;
    }
};

int main() {
    Solution s;
    vector<int> vac = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(vac) << endl;  
    return 0;
}