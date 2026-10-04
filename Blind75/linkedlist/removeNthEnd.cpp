#include <iostream>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
         
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
         
        if (!fast) {
            ListNode* newHead = head->next;
            delete head;  
            return newHead;
        }
         
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
         
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        return head;
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
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2;

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    cout << "List after removing " << n << "th node from end: ";
    printList(head);

    freeList(head);
    return 0;
}