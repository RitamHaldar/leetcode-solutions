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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if (!list1 || !list2) return list1;
        ListNode *temp=list1;
        ListNode *temp2=list2;
        ListNode *t;
        int count =0;
        while(temp!=NULL){
            if (count==a-1) {
                t=temp->next;
                temp->next=temp2;
                while(temp2->next!=NULL) temp2=temp2->next;
                while(count!=b-1 && t->next!=NULL){
                    count++;
                    t=t->next;
                }
                temp2->next=t->next;
            }
            temp=temp->next;
            count++;
        }
        return list1;
    }
};
