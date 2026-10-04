#include<bits/stdc++.h>
 
using namespace std;

class Solution {
    public:
    int buySell(vector<int>& nums) {
        int mincost = nums[0];
        int cost = 0;
        for(int i = 1; i < nums.size(); i++) {
            cost = max(cost, nums[i] - mincost);
            mincost = min(mincost, nums[i]);
        }
        return cost;
    }
};
int main() {
    Solution s;
    vector<int> vac = {7,1,5,3,6,4};
    cout << s.buySell(vac);
    return 0;
}