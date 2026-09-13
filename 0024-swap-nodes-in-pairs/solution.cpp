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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
          return head;

        ListNode* newHead = head->next;

        ListNode* temp1 = head;
        ListNode* temp2 = head->next;

        while (temp1 && temp2) {
            ListNode* next = temp2->next;

            temp2->next = temp1;

            if (!next || !next->next) {
                temp1->next = next;
                break;
            }

            temp1->next = next->next;

            temp1 = next;
            temp2 = next->next;
        }

         return newHead;
    }
};
