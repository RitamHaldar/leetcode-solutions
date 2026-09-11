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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp=new ListNode(100);
        ListNode *temph=temp;
        string num1="";
        string num2="";
        while(l1!=NULL){
            num1+=to_string(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            num2+=to_string(l2->val);
            l2=l2->next;
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string sum = "";
        while (i >= 0 || j >= 0 || carry) {
            int x = (i >= 0) ? num1[i] - '0' : 0;
            int y = (j >= 0) ? num2[j] - '0' : 0;
            int s = x + y + carry;
            sum += to_string(s % 10);
            carry = s / 10;
            i--;
            j--;
        }
        for (int i = 0; i < sum.size(); i++) {
            ListNode *t = new ListNode(sum[i] - '0');
            temph->next = t;
            temph = temph->next;
        }
        return temp->next;
    }
};
