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
    ListNode* mergeList(ListNode *a,ListNode *b){
        ListNode *c=new ListNode(100);
        ListNode *temp=c;
        while(a && b){
            if(a->val<=b->val){
                temp->next=a;
                a=a->next;
                temp=temp->next;

            }
            else{
                temp->next=b;
                b=b->next;
                temp=temp->next;
            }
        }
        if (!a) temp->next=b;
        else if(!b) temp->next=a;
        return c->next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        vector<ListNode*>& templist=lists;
        while(lists.size()>1){
            ListNode *a=lists[0];
            lists.erase(lists.begin());
            ListNode *b=lists[0];
            lists.erase(lists.begin());
            ListNode *res=mergeList(a,b);
            lists.push_back(res);
        }
        return lists[0];
    }
};
