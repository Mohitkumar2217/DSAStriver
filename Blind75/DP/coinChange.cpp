#include<bits/stdc++.h>
 
using namespace std;

class Solution {
    public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        for(int c : coins) {
            for(int i = c; i <= amount; i++) {
                dp[i] += dp[i - c];
            }
        }
        return dp[amount];
    }
};
int main() {
    vector<int> vac = {1, 2, 5};
    int n = 5;
    Solution s;
    cout << s.change(n, vac);
    return 0;
}