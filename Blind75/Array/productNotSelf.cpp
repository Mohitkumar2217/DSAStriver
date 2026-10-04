#include<bits/stdc++.h>
 
using namespace std;
class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        int zero_count = 0;
        int zero_index = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero_count++;
                zero_index = i;
            } else {
                product *= nums[i];
            }
        }
        
        vector<int> ans(n, 0);
        
        if (zero_count > 1) {
            return ans;  
        } 
        if (zero_count == 1) {
            ans[zero_index] = product;
            return ans;
        }
        
        for (int i = 0; i < n; i++) {
            ans[i] = product / nums[i];
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