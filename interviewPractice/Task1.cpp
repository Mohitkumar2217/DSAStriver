#include <bits/stdc++.h>
using namespace std;

// O(1) for adding
// O(1) for deleting
// O(1) for random number generater

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class Solution {
private:
    Node *head;
    Node *tail;
    unordered_map<int, Node*> mp;
    int size;

public: 
    Solution() {
        head = new Node(-1); 
        tail = new Node(-1);  
        head->next = tail;
        tail->prev = head;
        size = 0;
        srand(time(0));
    }

    void add(int num) {
        if (mp.find(num) != mp.end()) return;

        Node *temp = new Node(num);
        temp->prev = tail->prev;
        temp->next = tail;
        tail->prev->next = temp;
        tail->prev = temp;

        mp[num] = temp;
        size++;
    }

    void remove(int num) {
        if (mp.find(num) == mp.end()) return;

        Node *toDelete = mp[num]; 
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;

        mp.erase(num);
        delete toDelete;  
        size--;
    }

    int random() {
        if (size == 0) return -1; 

        int randomIndex = rand() % size;
        Node *curr = head->next;
        for (int i = 0; i < randomIndex; i++) {
            curr = curr->next;
        }

        return curr->data;
    }

    ~Solution() { 
        Node *curr = head;
        while (curr != nullptr) {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    Solution sol;
    sol.add(10);
    sol.add(20);
    sol.add(30);

    cout << "Random element: " << sol.random() << endl;

    sol.remove(20);
    cout << "Random element after removing 20: " << sol.random() << endl;

    return 0;
}