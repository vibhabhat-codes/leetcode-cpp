/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: detect cycle
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {

                // Step 2: find start of cycle
                ListNode* entry = head;

                while(entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }

                return entry;
            }
        }

        return NULL;
    }
};