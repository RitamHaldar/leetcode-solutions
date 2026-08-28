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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
    
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;      
            curr = nextTemp; 
        }
    
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode* part1 = new ListNode(0);
        ListNode* part2 = new ListNode(0);
        ListNode* part3 = new ListNode(0);
        ListNode* tail1 = part1;
        ListNode* tail2 = part2;
        ListNode* tail3 = part3;

        ListNode* curr = head;
        int pos = 1;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = NULL; 

            if (pos < left) {
                tail1->next = curr;
                tail1 = tail1->next;
            } else if (pos <= right) {
                tail2->next = curr;
                tail2 = tail2->next;
            } else {
                tail3->next = curr;
                tail3 = tail3->next;
            }

            curr = nextNode;
            pos++;
        }
        ListNode* reversedMiddle = reverseList(part2->next);
        tail1->next = reversedMiddle;
        ListNode* temp = part1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = part3->next;
        ListNode* newHead = part1->next;
        delete part1;
        delete part2;
        delete part3;

        return newHead;
    }
};
