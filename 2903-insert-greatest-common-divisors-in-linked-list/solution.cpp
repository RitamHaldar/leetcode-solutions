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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *fast=head->next;
        ListNode *slow=head;
        while(fast){
            ListNode *t=new ListNode(__gcd(slow->val,fast->val));
            slow->next=t;
            slow=slow->next;
            slow->next=fast;
            fast=fast->next;
            slow=slow->next;
        }
        return head;
    }
};
