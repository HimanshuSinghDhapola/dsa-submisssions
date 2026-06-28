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

// One pass approach
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        int moveForward = n;
        while(moveForward--){
            fast = fast->next;
        }
        
        ListNode* curr = head;
        if(!fast){
            ListNode *temp = curr->next;
            delete(curr);
            return temp;
        }
        while(fast->next){
            curr = curr->next;
            fast = fast->next;
        }
        ListNode *temp = curr->next;
        curr->next = curr->next->next;
        delete(temp);
        return head;
    }
};
