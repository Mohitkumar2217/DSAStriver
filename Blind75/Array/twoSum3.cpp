#include<bits/stdc++.h>
 
using namespace std;

class Solution {
    public:
    vector<vector<int>> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<vector<int>> vac;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(target - nums[i])) {
                vac.push_back({mp[target - nums[i]], i});
            }
            mp[nums[i]] = i;
        }
        return vac;
    }
};

int main() {
    vector<int> vac = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<vector<int>> v = s.twoSum(vac, target);
    for(auto vc : v) {
        cout << vc[0] << " " << vc[1] << ", ";
    }
    return 0;
}