/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp=head;
        ListNode *temp2=head;
        bool flag=false;
        while (temp2!=NULL && temp2->next!=NULL){
            temp2=temp2->next->next;
            temp=temp->next;
            if (temp==temp2) {
                flag=true;
                break;
            }
        }
        if (!flag) return NULL;
        while (head->next!=NULL){
            if(head==temp) break;
            head=head->next;
            temp=temp->next;
            
        }
        return head;
    }
};