/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // find list size
        ListNode* curr = head;
        int listSize = 0;
        while (curr) {
            curr = curr->next;
            ++listSize;
        }
        if (n == listSize) return head->next;
        // go to the nth node from the end, i.e node (size - n) in the list
        curr = head;
        ListNode* prev;
        while (listSize > n) {
            if (listSize - 1 == n) {
                prev = curr;
            }
            curr = curr->next;
            --listSize;
        }
        // restitch and return
        prev->next = curr->next;
        return head;
    }
};
