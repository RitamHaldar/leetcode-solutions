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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(true){
            if(temp==NULL) break;
            len++;
            temp=temp->next;
        }
        len=len-n;
        temp=head;
        for (int i=1;i<len;i++){
            temp=temp->next;
        }
        if(temp->next==NULL || len==0) return head->next;
        temp->next=temp->next->next;
        return head;
    }
};
