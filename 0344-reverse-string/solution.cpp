class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        vector<char> res;
        for(int i=n-1;i>=0;i--){
            res.push_back(s[i]);
        }
        s=res;
    }
};
