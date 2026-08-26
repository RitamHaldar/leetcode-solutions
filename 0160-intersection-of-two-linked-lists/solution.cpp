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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA=headA;
        ListNode *tempB=headB;
        int lenA=0,lenB=0;
        while(tempA->next!=NULL){
            lenA++;
            tempA=tempA->next;
        }
        while(tempB->next!=NULL){
            lenB++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        int diff;
        if(lenA>lenB){
            diff=lenA-lenB;
            for (int i=0;i<diff;i++){
                tempA=tempA->next;
            }
        }
        if(lenB>lenA){
            diff=lenB-lenA;
            for (int i=0;i<diff;i++){
                tempB=tempB->next;
            }
        }
        while(tempA!=NULL){
            if(tempA==tempB) return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};
