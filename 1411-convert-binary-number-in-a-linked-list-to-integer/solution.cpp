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
    int getDecimalValue(ListNode* head) {
        if(!head) return 0;
        string res="";
        ListNode *temp=head;
        while(temp!=NULL){
            res+=to_string(temp->val);
            temp=temp->next;
        }
        return stoi(res,nullptr,2);
    }
};
