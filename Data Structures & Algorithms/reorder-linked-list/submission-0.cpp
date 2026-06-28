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
private:
    ListNode* reverseLinkedList(ListNode *node){
        if(!node || !node->next){
            return node;
        }
        ListNode *newHead = reverseLinkedList(node->next);
        node->next->next = node;
        node->next = NULL;
        return newHead;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverseLinkedList(slow);
        ListNode* curr = head;
        while(rev->next){
            ListNode *tempCurr = curr->next;
            ListNode *tempRev = rev->next;
            curr->next = rev;
            rev->next = tempCurr;
            curr = tempCurr;
            rev = tempRev;
        }
    }
};
