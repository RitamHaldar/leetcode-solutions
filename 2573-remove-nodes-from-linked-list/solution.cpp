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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> st;
        ListNode* curr = head;
        while (curr != NULL) {
            while (!st.empty() && st.back()->val < curr->val) {
                st.pop_back();
            }
            st.push_back(curr);
            curr = curr->next;
        }
        for (int i = 0; i < st.size() - 1; i++) {
            st[i]->next = st[i + 1];
        }
        st.back()->next = NULL;
        return st[0];
    }
};
