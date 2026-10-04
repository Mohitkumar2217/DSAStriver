#include<bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) { 
            unsigned carry = (unsigned)(a & b) << 1; 
            a = a ^ b; 
            b = carry;
        }
        return a;
    }
};
int main() {
    Solution s;
    cout << s.getSum(2, 3);
    return 0;
}