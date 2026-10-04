#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() { 
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;  

    Solution sol;
    cout << boolalpha;
    cout << "Has cycle (cyclic list): " << sol.hasCycle(head) << "\n";
 
    node4->next = nullptr;
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
 
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << "Has cycle (acyclic list): " << sol.hasCycle(head2) << "\n";

    while (head2) {
        ListNode* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}