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
    // Phase 1: Reverse 'times' nodes starting from head
    void reverse(ListNode* head, int times) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (times--) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
    }

    ListNode* swapPairs(ListNode* head) {
        // Phase 2: Handle the empty list
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* left = head;
        ListNode* right;
        ListNode* prevLeft = NULL;
        ListNode* res = NULL;

        int size = 2;

        while (true) {
            // Phase 3: Find the second node of the current pair
            right = left;

            for (int i = 0; i < size - 1; i++) {
                if (right == NULL) {
                    break;
                }
                right = right->next;
            }

            // Phase 4: Reverse the pair if both nodes exist
            if (right != NULL) {
                ListNode* nextLeft = right->next;

                reverse(left, size);

                // Phase 5: Connect the previous pair to the current reversed pair
                if (prevLeft != NULL) {
                    prevLeft->next = right;
                }

                // The original left node becomes the tail after reversal
                prevLeft = left;

                // Store the new head of the linked list
                if (res == NULL) {
                    res = right;
                }

                // Move to the next pair
                left = nextLeft;
            } 
            else {
                // Phase 6: Connect any remaining unpaired node
                if (prevLeft != NULL) {
                    prevLeft->next = left;
                }

                // If no pair was reversed, retain the original head
                if (res == NULL) {
                    res = left;
                }

                break;
            }
        }

        // Phase 7: Return the new head
        return res;
    }
};