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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Phase 1: Handle edge cases
        if (head == NULL || left == right) {
            return head;
        }

        ListNode* temp = head;
        ListNode* before = NULL;
        int pos = 1;

        // Phase 2: Reach the left position
        // Keep track of the node just before the sublist.
        while (pos < left) {
            before = temp;
            temp = temp->next;
            pos++;
        }

        // Phase 3: Reverse the sublist from left to right
        ListNode* curr = temp;
        ListNode* prev = NULL;

        int times = right - left + 1;

        while (times--) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // Phase 4: Connect the reversed sublist to the remaining list
        // temp is now the last node of the reversed sublist.
        temp->next = curr;

        // Phase 5: Connect the previous part to the reversed sublist
        if (before != NULL) {
            before->next = prev;
            return head;
        }

        // If left == 1, prev is the new head of the list.
        return prev;
    }
};