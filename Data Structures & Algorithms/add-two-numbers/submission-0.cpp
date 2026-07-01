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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* ans = new ListNode();
        ListNode *curr = ans;
        int carry = 0;
        while(curr1 || curr2 || carry){
            int sum = carry;
            if(curr1){
                sum += curr1->val;
                curr1 = curr1->next;
            }
            if(curr2){
                sum += curr2->val;
                curr2 = curr2->next;
            }

            carry = sum / 10;
            int nodeVal = sum % 10;
            curr->next = new ListNode(nodeVal);
            curr = curr->next;
        }
        ListNode* temp = ans;
        ans = ans->next;
        delete(temp);
        return ans;
    }
};
