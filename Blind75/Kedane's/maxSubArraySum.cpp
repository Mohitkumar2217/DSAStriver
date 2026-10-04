#include <bits/stdc++.h>

using namespace std;  

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsofar = nums[0];
        int currsum = nums[0];

        for (size_t i = 1; i < nums.size(); i++) { 
            currsum = max(nums[i], currsum + nums[i]);
            maxsofar = max(maxsofar, currsum);
        }

        return maxsofar;
    }
};

int main()
{
    Solution s;
    vector<int> vac = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(vac);
    return 0;
}