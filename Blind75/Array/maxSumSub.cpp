#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = nums[0];
        int minSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            sum += nums[i];
            maxSum = max({maxSum, sum, sum - minSum});
            minSum = min(minSum, sum);
        }
        return maxSum;
    }
};

int main()
{
    Solution s;
    vector<int> vac = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(vac);
    return 0;
}