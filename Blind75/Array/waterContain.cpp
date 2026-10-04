#include<bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {  
        int left = 0;
        int right = height.size() - 1;
        int maxi = min(height[left], height[right]) * (right - left);
        while(left < right) {
            maxi = max(maxi, min(height[left], height[right]) * (right - left));
            if(height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        } 
        return maxi;
    }
}; 
int main() {
    Solution s;
    vector<int> vac = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(vac);
    return 0;
}