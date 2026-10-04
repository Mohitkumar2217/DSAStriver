#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(auto &vac : intervals) {
            if(ans.empty() || ans.back()[1] < vac[0]) {
                ans.push_back(vac);
            }
            else {
                ans.back()[1] = max(ans.back()[1], vac[1]);
            }
        }
        return ans;
    }
};

void printIntervals(const vector<vector<int>>& intervals) {
    cout << "[";
    for (size_t i = 0; i < intervals.size(); ++i) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]"
             << (i + 1 < intervals.size() ? "," : "");
    }
    cout << "]\n";
}

int main() {
    Solution sol;
 
    vector<vector<int>> intervals1 = {{1, 3}, {2, 5}, {6, 9}}; 
    cout << "Test 1 Result: ";
    printIntervals(intervals1);  
 
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {4, 8}, {6, 7}, {8, 10}, {12, 16}}; 
    cout << "Test 2 Result: ";
    printIntervals(intervals2); 

    return 0;
}