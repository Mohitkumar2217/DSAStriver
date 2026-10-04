#include<bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currproduct = nums[0];
        int maxproduct = nums[0];
        int minproduct = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(maxproduct, minproduct);
            } 

            maxproduct = max(maxproduct * nums[i], nums[i]);
            minproduct = min(minproduct * nums[i], nums[i]); 

            currproduct = max(maxproduct, currproduct);
        }

        return currproduct;
    }
};

int main() {
    Solution s;
    vector<int> vac = {2,3,-2,4};
    cout << s.maxProduct(vac);
    return 0;
}