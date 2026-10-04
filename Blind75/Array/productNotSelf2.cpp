#include<bits/stdc++.h>
  
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1); 
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
 
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> vac = {1,2,3,4};
    vac = s.productExceptSelf(vac);
    for(int i = 0; i < vac.size(); i++) {
        cout << vac[i] << " ";
    }
    return 0;
}