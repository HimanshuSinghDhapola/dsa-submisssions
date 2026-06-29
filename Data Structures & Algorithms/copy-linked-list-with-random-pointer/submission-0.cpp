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

// Solution1: Space: O(N) Time: O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        Node* newHead = NULL;
        Node* prev = NULL;
        unordered_map<Node*, Node*> mpp;
        while(curr){
            Node* temp = new Node(curr->val);
            mpp[curr] = temp;
            if(!prev){
                newHead = temp;
                prev = newHead;
            }else{
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }
        curr = head;
        Node * newCurr = newHead;

        while(curr && newCurr){
            newCurr->random = mpp[curr->random];
            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};
