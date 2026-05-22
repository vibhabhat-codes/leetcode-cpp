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

    int getLength(ListNode* head) {

        int len = 0;

        while(head != NULL) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = getLength(headA);
        int lenB = getLength(headB);

        int diff = abs(lenA - lenB);

        // Move longer list ahead
        if(lenA > lenB) {

            while(diff--) {
                headA = headA->next;
            }
        }
        else {

            while(diff--) {
                headB = headB->next;
            }
        }

        // Traverse together
        while(headA != NULL && headB != NULL) {

            // Same node found
            if(headA == headB) {
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};