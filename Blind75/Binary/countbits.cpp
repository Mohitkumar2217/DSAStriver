#include<bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for(int i = 0; i <= n; i++) ans[i] = ans[i >> 1] + (i & 1); 
        return ans;
    }
};
 
int main() {
    Solution s;
    vector<int> vac = s.countBits(5);
    for(int num : vac) {
        cout << num << " ";
    }
    return 0;
}