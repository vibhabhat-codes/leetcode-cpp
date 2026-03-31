/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head) return NULL;

        // Step 1: copy nodes
        Node* curr = head;
        while(curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: set random pointers
        curr = head;
        while(curr) {
            if(curr->random)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        // Step 3: separate lists
        curr = head;
        Node* dummy = new Node(0);
        Node* copyTail = dummy;

        while(curr) {
            Node* copy = curr->next;

            copyTail->next = copy;
            copyTail = copy;

            curr->next = copy->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};