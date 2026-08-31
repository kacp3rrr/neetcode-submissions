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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* merged;
        // empty checks, initialize the list with the smaller of the two values
        if (!(list1 || list2)) return nullptr;
        if (!list1) return list2;
        if (!list2) return list1;
        if (first->val <= second->val) {
            merged = first;
            first = first->next;
        } else {
            merged = second;
            second = second->next;
        }
        // store the head of the merged list for return later
        ListNode* merged_head = merged;
        // iterate until the pointers for both list reach the end
        // have seperrate completion logic if we finished one of the lists
        while (first && second) {
            if (first->val <= second->val) {
                merged->next = first;
                first = first->next;
                merged = merged->next;
            } else {
                merged->next = second;
                second = second->next;
                merged = merged->next;
            }
        }

        if (first) {
            while (first) {
                merged->next = first;
                first = first->next;
                merged = merged->next;
            }
        } if (second) {
            while (second) {
                merged->next = second;
                second = second->next;
                merged = merged->next;
            }
        }
        return merged_head;
    }
};
