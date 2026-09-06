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
    void reorderList(ListNode* head) {
        // 1. traverse the list to get the size
        int listSize = 0;
        ListNode* curr = head;
        while (curr) {
            ++listSize;
            curr = curr->next;
        }
        // 2. reverse the list from the middle to the end
        curr = head;
        // store the element before mid, to cut off the two lists using fast pointer
        ListNode* beforeMid = curr;
        while (curr->next && curr->next->next) {
            beforeMid = beforeMid->next;
            curr = curr->next->next;
        }
        // cut off list, reverse right half
        curr = beforeMid->next; 
        beforeMid->next = nullptr;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // 3. insert the linked list from the middle onwards in between each element in the original list
        // for the sake of not initializing useless variables, prev is the head of the right-half linked list
        curr = head;
        while (curr && prev) {
            // next nodes in the left and right half
            ListNode* nextLeft = curr->next;
            ListNode* nextRight = prev->next;
            curr->next = prev;
            prev->next = nextLeft;
            curr = nextLeft;
            prev = nextRight;
        }
    }
};
