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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move until fast reaches the end
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // move slow by 1
            fast = fast->next->next; // move fast by 2
        }

        return slow; // slow is at the middle
    }
};