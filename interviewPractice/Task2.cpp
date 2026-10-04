#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mp;  

public:
    RandomizedSet() { 
        srand(time(0));
    }

    bool add(int val) {
        if (mp.find(val) != mp.end()) {
            return false;  
        }
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;  
        }
 
        int idx = mp[val];
        int lastVal = nums.back();
 
        nums[idx] = lastVal;
        mp[lastVal] = idx;
 
        nums.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

int main() {
    RandomizedSet st;
    st.add(10);
    st.add(20);
    st.add(30);
    cout << "Random element: " << st.getRandom() << "\n";
    st.remove(20);
    cout << "Random element after removal: " << st.getRandom() << "\n";
    return 0;
}