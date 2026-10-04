#include<bits/stdc++.h>
 
using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(target - nums[i])) {
                return {mp[target - nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> vac = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> v = s.twoSum(vac, target);
    cout << v[0] << " " << v[1];
    return 0;
}