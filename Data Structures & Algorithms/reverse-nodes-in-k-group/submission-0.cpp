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
    ListNode* reverseLL(ListNode* head){
        if(!head->next) return head;
        ListNode* revHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return revHead;
    }
    ListNode* getKthNode(ListNode* head, int k){
        k--;
        while(head && k>0){
            head = head->next;
            k--;
        }
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prevLast = NULL;
        while(curr){
            ListNode* kthNode = getKthNode(curr, k);
            if(!kthNode){
                if(prevLast) prevLast->next = curr;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(curr);
            if(curr == head){
                head = kthNode;
            }else{
                prevLast->next = kthNode;
            }
            prevLast = curr;
            curr = nextNode;
        }      
        return head;
    }
};
