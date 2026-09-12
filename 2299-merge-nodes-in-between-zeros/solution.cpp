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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp=head;
        ListNode *res=new ListNode(100);
        ListNode *t2=res;
        while (temp!=NULL){
            if(temp->val==0){
                temp=temp->next;
                int sum=0;
                while(temp!=NULL && temp->val!=0){
                    sum+=temp->val;
                    temp=temp->next;
                }
                if(sum!=0){
                    ListNode *t=new ListNode(sum);
                t2->next=t;
                t2=t2->next;
                }
            }
        }
        return res->next;
    }
};
