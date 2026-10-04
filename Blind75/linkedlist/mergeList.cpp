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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Stack-allocated dummy node avoids unnecessary heap allocation
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Splice nodes together in-place instead of creating new ones
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes in one step
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << "\n";
}

// Helper function to free allocated memory
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Construct List 1: 1 -> 2 -> 4
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));

    // Construct List 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(merged);

    // Free memory of merged list
    freeList(merged);

    return 0;
}