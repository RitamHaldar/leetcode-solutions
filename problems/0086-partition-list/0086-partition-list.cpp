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
    ListNode* partition(ListNode* head, int x) {
        ListNode *a=new ListNode(100);
        ListNode *b=new ListNode(100);
        ListNode *high=a;
        ListNode *low=b;
        ListNode *temp=head;
        while(temp!=NULL){
            if(temp->val>=x){
                a->next=temp;
                a=a->next;
                temp=temp->next;
            }
            else{
                b->next=temp;
                b=b->next;
                temp=temp->next;
            }
        }
        a->next=NULL;
        b->next=NULL;
        temp=b;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=high->next;
        return low->next;
    }
};