#include<bits/stdc++.h>
 
using namespace std;

template<typename T>

class SegmentTree {
    private:
    vector<T> tree;
    vector<T> arr;
    int n;

    int left(int node) { return 2 * node + 1; }

    int right(int node) { return 2 * node + 2; }

    int mid(int l, int r) { return  l + (r - 1) / 2; }

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node] == arr[start];
            return;
        }

        int m = mid(start, end);

        build(left(node), start, m);
        build(right(node), m + 1, end);

        tree[node] = min(tree[left(node)], tree[right(node)]);
    }

    void update(int node, int start, int end, int idx, T val) {
        if(start == end) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }

        int m = mid(start, end);
        if(idx <= m) 
            update(left(node), start, m, idx, val);
        else 
            update(right(node), m + 1, end, idx, val);

        tree[node] = min(tree[left(node)], tree[right(node)]);
    }

    T query(int node, int start, int end, int l, int r) {
        if(r < start || end < l) 
            return INT_MAX;
        
        if(l <= start && end <= r) 
            return tree[node];

        int m = mid(start, end);

        T left_min = query(left(node), start, m, l, r);
        T right_min = query(right(node), m + 1, end, l, r);

        return min(left_min, right_min);
    }

    public:
    SegmentTree(const vector<T>& a) : arr(a), n(a.size()) {
        tree.resize(4 * n);
        build(0, 0, n - 1);
    } 

    void update(int idx, T val) {
        update(0, 0, n - 1, idx, val);
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> arr = { 1, 3, 2, 7, 9, 11 };
    SegmentTree<int> st(arr);

    cout << "Segment Tree for Minmum Range Queries: " << endl;
    cout << "Original Array: ";
    for( int num : arr ) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Minimum in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Minimum in range [0, 5]: " << st.query(0, 5) << endl;

    st.update(2, 1);
    cout << "After updating index 2 to 1:" << endl;
    cout << "Minimum in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Minimum in range [0, 5]: " << st.query(0, 5) << endl;
    return 0;
}