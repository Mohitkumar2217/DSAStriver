#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) { 
        ListNode *pre = nullptr, *curr = head;
        while(curr) {
            ListNode *newCurr = curr->next;
            curr->next = pre;
            pre = curr;
            curr = newCurr;
        }
        return pre;
    }
};
 
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << "\n";
}
 
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() { 
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);
 
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);
 
    freeList(reversedHead);

    return 0;
}