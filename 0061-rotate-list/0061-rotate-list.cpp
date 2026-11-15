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
    ListNode* rotateRight(ListNode* head, int k) {
        // Phase 1: Handle the empty list
        if (head == NULL)
            return head;

        // Phase 2: Find the length and last node
        ListNode* last = head;
        int n = 1;

        while (last->next != NULL) {
            n++;
            last = last->next;
        }

        // Phase 3: Calculate effective rotations
        k = k % n;

        if (k == 0)
            return head;

        // Phase 4: Find the new last node (n-k position)
        ListNode* temp = head;
        int count = 1;

        while (temp != NULL) {
            if (count == n - k)
                break;

            count++;
            temp = temp->next;
        }

        // Phase 5: Connect the original last node to the head
        last->next = head;

        // Phase 6: Set the new head and break the circular link
        ListNode* res = temp->next;
        temp->next = NULL;

        // Phase 7: Return the new head
        return res;
    }
};