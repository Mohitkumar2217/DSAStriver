#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        // Frequency table for character requirements
        vector<int> freq(128, 0);
        for (char c : t) {
            freq[c]++;
        }

        int count = t.length(); // Total characters needed from t
        int left = 0, right = 0;
        int minLen = INT_MAX, minLeft = 0;

        while (right < s.length()) {
            // If character in s is required, decrement needed count
            if (freq[s[right]] > 0) {
                count--;
            }
            freq[s[right]]--;
            right++;

            // Contract left boundary when all target characters are satisfied
            while (count == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minLeft = left;
                }

                freq[s[left]]++;
                // If freq becomes positive, we lost a required character from window
                if (freq[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

int main() {
    Solution sol;

    string s1 = "ADOBECODEBANC", t1 = "ABC";
    string s2 = "a", t2 = "a";
    string s3 = "a", t3 = "aa";

    cout << "s: \"" << s1 << "\", t: \"" << t1 << "\" -> " << sol.minWindow(s1, t1) << "\n";
    cout << "s: \"" << s2 << "\", t: \"" << t2 << "\" -> " << sol.minWindow(s2, t2) << "\n";
    cout << "s: \"" << s3 << "\", t: \"" << t3 << "\" -> " << sol.minWindow(s3, t3) << "\n";

    return 0;
}