#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        vector<int> lastSeen(256, -1);
        int maxlen = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            unsigned char ch = s[right];
             
            if (lastSeen[ch] >= left) {
                left = lastSeen[ch] + 1;
            }
            
            lastSeen[ch] = right;
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};

int main() {
    Solution sol;

    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";

    cout << "Input: \"" << s1 << "\" -> Length: " << sol.lengthOfLongestSubstring(s1) << "\n";
    cout << "Input: \"" << s2 << "\" -> Length: " << sol.lengthOfLongestSubstring(s2) << "\n";
    cout << "Input: \"" << s3 << "\" -> Length: " << sol.lengthOfLongestSubstring(s3) << "\n";

    return 0;
}