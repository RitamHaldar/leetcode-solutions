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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k,NULL);
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        int split=n%k,j=0,size=n/k;
        temp=head;
        while(temp!=NULL){
            ListNode* temp1=new ListNode(100);
            ListNode* temp2=temp1;
            int count =size;
            if(split>0) count++;
            split--;
            for(int i=1;i<=count;i++){
                if(temp!=NULL){
                    temp2->next=temp;
                    temp=temp->next;
                    temp2=temp2->next;
                }
            }
            temp2->next=NULL;
            res[j]=temp1->next;
            j++;
        }
        return res;
    }
};
