#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;

        for(int num : nums) mp[num]++;

        for(auto &p : mp) {
            pq.push({p.second, p.first});
        }
        vector<int> vac;
        while(k--) {
            vac.push_back(pq.top().second);
            pq.pop();
        }
        return vac;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i + 1 < result.size() ? ", " : "");
    }
    cout << "]\n";

    return 0;
}