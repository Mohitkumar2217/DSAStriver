#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private: 
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
 
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } 
        return (static_cast<double>(maxHeap.top()) + minHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);
    cout << "Median after adding [1, 2]: " << mf.findMedian() << "\n"; // Output: 1.5

    mf.addNum(3);
    cout << "Median after adding 3: " << mf.findMedian() << "\n";      // Output: 2.0

    mf.addNum(8);
    mf.addNum(5);
    cout << "Median after adding [8, 5]: " << mf.findMedian() << "\n"; // Output: 3.0

    return 0;
}