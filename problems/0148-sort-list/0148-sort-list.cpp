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
    ListNode* mergeList(ListNode *a,ListNode *b){
        ListNode *c=new ListNode(100);
        ListNode *temp=c;
        while(a && b){
            if(a->val<=b->val){
                temp->next=a;
                a=a->next;
                temp=temp->next;

            }
            else{
                temp->next=b;
                b=b->next;
                temp=temp->next;
            }
        }
        if (!a) temp->next=b;
        else if(!b) temp->next=a;
        return c->next;
        
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* a=head;
        ListNode* b=slow->next;
        slow->next=NULL;
        a=sortList(a);
        b=sortList(b);
        ListNode* c=mergeList(a,b);
        return c;
    }
};