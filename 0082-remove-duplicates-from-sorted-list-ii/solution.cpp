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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *temp = head;
        ListNode *prev = NULL;

        while (temp != NULL) {
            int v = temp->val;
            ListNode *t = temp->next;

            while (t != NULL && t->val == v) {
                t = t->next;
            }

            if (t != temp->next) {
            if (prev) prev->next = t;
            else head = t;

            temp = t;
            }
        else {
            prev = temp;
            temp = temp->next;
        }
        }

        return head;
    }
};
