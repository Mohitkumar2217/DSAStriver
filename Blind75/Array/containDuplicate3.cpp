#include<bits/stdc++.h>
 
using namespace std;

class Solution {
    public:
    vector<int> containDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> vac;
        for(int num : nums) {
            mp[num]++; 
        }
        for(auto &p : mp) {
            if(p.second >=2) vac.push_back(p.first);
        }
        return vac;
    }
};

int main() {
    Solution s;
    vector<int> vac = {1,2,3,1,6,3,2,4,5};
    vac = s.containDuplicate(vac);
    for(int num : vac) {
        cout << num << " ";
    }
    return 0;
}