#include<bits/stdc++.h>
 
using namespace std;

class Solution {
    public:
    bool containDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
            if(mp[num] >= 2) {
                return num;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> vac = {1,2,3,1};
    cout << s.containDuplicate(vac);
    return 0;
}