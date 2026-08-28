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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
        return true;
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        temp=head;
        ListNode* tail=NULL;
        for (int i=0;i<len/2;i++){
            ListNode* curr=temp->next;
            temp->next=tail;
            tail=temp;
            temp=curr;
        }
        if (len % 2 != 0)
        temp = temp->next;
        while (tail != NULL && temp != NULL) {
            if (tail->val != temp->val)
                return false;

            tail = tail->next;
            temp = temp->next;
        }

    return true;
    }
};
