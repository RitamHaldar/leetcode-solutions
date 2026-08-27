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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        if(!head) return res;
        int firstr=0,firstc=0,lastr=m-1,lastc=n-1;
        while(firstr<=lastr && firstc<=lastc){
            for (int j=firstc;j<=lastc;j++){
                if(!head) break;
                res[firstr][j]=head->val;
                head=head->next;
            }
            firstr++;
            if(firstr>lastr) break;
            for(int i=firstr;i<=lastr;i++){
                if(!head) break;
                res[i][lastc]=head->val;
                head=head->next;
            }
            lastc--;
            if(firstc>lastc) break;
            for(int j=lastc;j>=firstc;j--){
                if(!head) break;
                res[lastr][j]=head->val;
                head=head->next;
            }
            lastr--;
            if(firstr>lastr) break;
            for (int i=lastr;i>=firstr;i--){
                if(!head) break;
                res[i][firstc]=head->val;
                head=head->next;
            }
            firstc++;
            if(firstc>lastc) break;
        }
        return res;
    }
};