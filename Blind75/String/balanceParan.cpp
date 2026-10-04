#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) { 
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
 
            else if (ch == ')') {
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
            }

            else if (ch == '}') {
                if (st.empty() || st.top() != '{') {
                    return false;
                }
                st.pop();
            }

            else if (ch == ']') {
                if (st.empty() || st.top() != '[') {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;

    string s1 = "()[]{}";
    string s2 = "(]";
    string s3 = "([)]";
    string s4 = "{[]}";

    cout << boolalpha;
    cout << "s: \"" << s1 << "\" -> " << sol.isValid(s1) << "\n";
    cout << "s: \"" << s2 << "\" -> " << sol.isValid(s2) << "\n";
    cout << "s: \"" << s3 << "\" -> " << sol.isValid(s3) << "\n";
    cout << "s: \"" << s4 << "\" -> " << sol.isValid(s4) << "\n";

    return 0;
}