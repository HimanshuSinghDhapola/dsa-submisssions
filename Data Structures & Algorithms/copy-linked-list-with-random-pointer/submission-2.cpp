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

// Solution 2: Constant space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* curr = head;
        while(curr){
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = curr->next->next;
        }
        Node* newHead = head->next;
        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }else{
                curr->next->random = NULL;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node * newCurr = newHead;
        while(curr && newCurr){
            curr->next = curr->next ? curr->next->next : NULL;
            newCurr->next = newCurr->next ? newCurr->next->next : NULL;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;

    }
};
