#include<bits/stdc++.h> 
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n) {
            if(n % 2) count++;
            n /= 2;
        }
        return count;
    }
};
 
int main() {
    Solution s;  
    cout << s.hammingWeight(23);
    return 0;
}