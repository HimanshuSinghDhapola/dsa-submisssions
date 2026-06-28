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

 // 2 pass solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int size=0;
        while(curr){
            size++;
            curr = curr->next;
        }
        curr = head;
        if(size == n){
            return head->next;
        }else{
            for(int i=1; i<size-n; i++){
                curr = curr->next;
            }
            curr->next = curr->next->next;
        }
        return head;
    }
};
