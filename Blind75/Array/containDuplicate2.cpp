#include<bits/stdc++.h>
 
using namespace std;

class Solution {
    public:
    bool containDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int num : nums) { 
            if(st.count(num)) {
                return num;
            }
            st.insert(num);
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