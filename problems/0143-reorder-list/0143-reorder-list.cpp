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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *head2=slow->next;
        ListNode *temp=head2;
        ListNode *tail=NULL;
        while(temp!=NULL){
            ListNode* curr=temp->next;
            temp->next=tail;
            tail=temp;
            temp=curr;
        }
        slow->next=NULL;
        slow=head;
        while(slow!=NULL && tail!=NULL){
            ListNode *curr=slow->next;
            slow->next=tail;
            tail=tail->next;
            slow->next->next=curr;
            slow=curr;
        }
    }
};