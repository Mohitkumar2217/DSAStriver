#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        
        int len = 0;
        int start = 0;

        for(int i = 0; i < s.size(); ) {
            int right = i;
            int left = i;
            while(right < s.size() - 1 && s[left] == s[right + 1]) { 
                right++;  
            }
            i = right + 1;
            while(left > 0 && right < s.size() - 1 && s[left - 1] == s[right + 1]) { 
                left--;
                right++;
            }
            int currlen = right - left + 1; 
            if(currlen > len) {
                start = left;
                len = currlen;
            }
        }
        return s.substr(start, len);
    }
};

int main() {
    Solution sol;

    string s1 = "babad";
    string s2 = "cbbd";
    string s3 = "a";
    string s4 = "ac";

    cout << "Input: \"" << s1 << "\" -> Longest Palindrome: \"" << sol.longestPalindrome(s1) << "\"\n";
    cout << "Input: \"" << s2 << "\" -> Longest Palindrome: \"" << sol.longestPalindrome(s2) << "\"\n";
    cout << "Input: \"" << s3 << "\" -> Longest Palindrome: \"" << sol.longestPalindrome(s3) << "\"\n";
    cout << "Input: \"" << s4 << "\" -> Longest Palindrome: \"" << sol.longestPalindrome(s4) << "\"\n";

    return 0;
}