#include<bits/stdc++.h>
 
using namespace std;

class Solution {
    public:
    bool twoSum(vector<int>& nums, int target) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            if(st.count(target - nums[i])) {
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> vac = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    cout << (bool)s.twoSum(vac, target);
    return 0;
}