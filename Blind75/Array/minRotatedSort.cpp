#include<bits/stdc++.h>
#include <vector>
  
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) { 
                right = mid;
            } else { 
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
 
int main() {
    Solution s;
    vector<int> vac = {4,5,6,7,0,1,2};
    cout << s.findMin(vac);
    return 0;
}