#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buySell(const vector<int>& nums) {
        if (nums.empty()) return {-1, -1};

        int min_cost = nums[0];
        int min_cost_idx = 0;
        int max_profit = 0;
        int buy_idx = -1;
        int sell_idx = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - min_cost > max_profit) {
                max_profit = nums[i] - min_cost;
                sell_idx = i;
                buy_idx = min_cost_idx;
            }
            
            if (nums[i] < min_cost) {
                min_cost = nums[i];
                min_cost_idx = i;
            }
        }

        return {buy_idx, sell_idx};
    }
};

int main() {
    Solution s;
    vector<int> vac = {7, 1, 5, 3, 6, 4};
    vector<int> v = s.buySell(vac);
    
    cout << "Buy Index: " << v[0] << ", Sell Index: " << v[1] << endl;  
    return 0;
}