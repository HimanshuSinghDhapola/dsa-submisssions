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

 // 2 pass solution with abstraction and no memory leak

class Solution {
private:
    int countNodes(ListNode* head){
        int count=0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=countNodes(head);

        ListNode* curr = head;

        if(size == n){
            ListNode *temp = head->next;
            delete(head);
            return temp;
        }
        int travelFront = size-n;
        ListNode* prev = NULL;
        while(travelFront--){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete(curr);

        return head;
    }
};
