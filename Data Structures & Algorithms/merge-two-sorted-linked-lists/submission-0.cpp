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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2){
            return list1;
        }
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode *curr1 = list1, *curr2 = list2;
        ListNode * ans = new ListNode();
        ListNode *currAns = ans;
        while(curr1 && curr2){
            int val1 = curr1->val;
            int val2 = curr2->val;
            if(val1 <= val2){
                currAns->next = new ListNode(val1);
                curr1 = curr1->next;
            }else{
                currAns->next = new ListNode(val2);
                curr2 = curr2->next;
            }
            currAns = currAns->next;
        }
        while(curr1){
            currAns->next = new ListNode(curr1->val);
            curr1 = curr1->next;
            currAns = currAns->next;
        }
        while(curr2){
            currAns->next = new ListNode(curr2->val);
            curr2 = curr2->next;
            currAns = currAns->next;
        }
        return ans->next;
    }
};
