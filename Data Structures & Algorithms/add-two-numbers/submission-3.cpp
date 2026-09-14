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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // add each number, store output as the sum % 10, and the carry
        // as the carry
        int carry = 0;
        ListNode* first = l1;
        ListNode* second = l2;
        // temporary initialization for the output. will return output->next at the end,
        // using output as the anchor for the list that curr creates
        ListNode* output = new ListNode(0);
        ListNode* curr = output;
        // store the result in the first
        while (first || second) {
            int left = first ? first->val : 0;
            int right = second ? second->val : 0;
            int sum = left + right + carry; 
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            carry = sum / 10;
            if (first) first = first->next;
            if (second) second = second->next;
        }
        // append the carry to the end, return output as result
        if (carry != 0) {
            curr->next = new ListNode(carry);
        }
        return output->next;
    }
};
