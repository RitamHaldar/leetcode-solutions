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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==NULL || head->next->next==NULL) return {-1,-1};
        ListNode *p1=head;
        ListNode *p2=head->next;
        ListNode *p3=head->next->next;
        int firstidx=-1;
        int secondidx=-1;
        int idx=1;
        int minfirstidx=-1;
        int minsecondidx=-1;
        int mindis=INT_MAX;
        while(p3!=NULL){
            if(p2->val>p1->val && p2->val>p3->val || p2->val<p1->val && p2->val<p3->val){
                if(firstidx==-1) firstidx=idx;
                else secondidx=idx;
                if(minsecondidx==-1) minsecondidx=idx;
                else {
                    minfirstidx=minsecondidx;
                    minsecondidx=idx;
                    mindis=min(mindis,minsecondidx-minfirstidx);
                }
            }
            p1=p1->next;
            p2=p2->next;
            p3=p3->next;
            idx++;
        }
        if(firstidx==-1 || secondidx==-1) return {-1,-1};
        return {mindis,secondidx-firstidx};

    }
};
