#include<bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        int prod = 1;
        for(int num : nums) {
            prod *= num;
            maxProd = max(maxProd, prod);
            if(prod == 0) 
                prod = 1;
        }
        prod = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            maxProd = max(maxProd, prod);
            if(prod == 0) 
                prod = 1;
        }
        return maxProd == INT_MIN ? -1 : maxProd;
    }
};

int main() {
    Solution s;
    vector<int> vac = {2,3,-2,4};
    cout << s.maxProduct(vac);
    return 0;
}