#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int rev = 0;
        while(x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return (x == rev || x == rev / 10);
    }
};

int main() {
    Solution sol;

    int n1 = 121;
    int n2 = -121;
    int n3 = 10;
    int n4 = 12321;

    cout << boolalpha;
    cout << "x: " << n1 << " -> " << sol.isPalindrome(n1) << "\n";
    cout << "x: " << n2 << " -> " << sol.isPalindrome(n2) << "\n";
    cout << "x: " << n3 << " -> " << sol.isPalindrome(n3) << "\n";
    cout << "x: " << n4 << " -> " << sol.isPalindrome(n4) << "\n";

    return 0;
}