#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
    Solution sol;

    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";

    cout << boolalpha;
    cout << "s: \"" << s1 << "\", t: \"" << t1 << "\" -> " << sol.isAnagram(s1, t1) << "\n";
    cout << "s: \"" << s2 << "\", t: \"" << t2 << "\" -> " << sol.isAnagram(s2, t2) << "\n";

    return 0;
}