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
    ListNode* merge2SortedLinkedList(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val){
            l1->next = merge2SortedLinkedList(l1->next, l2);
            return l1;
        }else{
            l2->next = merge2SortedLinkedList(l1, l2->next);
            return l2;
        }
    }
    
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*> &lists){
        if(start>end){
            return NULL;
        }
        if(start == end){
            return lists[start];
        }
        int mid = start + (end-start)/2;
        ListNode* l1 = partitionAndMerge(start, mid, lists);
        ListNode* l2 = partitionAndMerge(mid+1, end, lists);
        return merge2SortedLinkedList(l1, l2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        return size==0 ? NULL : partitionAndMerge(0, size-1, lists);
    }
};
