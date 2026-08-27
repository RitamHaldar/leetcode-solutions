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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0 || !head->next) return head;
        ListNode *temp=head;
        ListNode *temp2=head;
        int len=1;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(k==0) return head;
        for(int i=1;i<len-k;i++){
            temp2=temp2->next;
        }
        ListNode* newHead = temp2->next;
        temp2->next = NULL;
        temp->next = head;
        return newHead;
    }
};
