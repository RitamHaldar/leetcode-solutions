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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) return head;
        ListNode *temp=head;
        int len=1;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        temp=head;
        ListNode *t1;
        ListNode *t2;
        int idx=1;
        int i=len-k;
        while(temp!=NULL){
            if (idx==k) t1=temp;
            if (idx==i) t2=temp;
            temp=temp->next;
            idx++;
        }
        i=t1->val;
        t1->val=t2->val;
        t2->val=i;
        return head;
    }
};
