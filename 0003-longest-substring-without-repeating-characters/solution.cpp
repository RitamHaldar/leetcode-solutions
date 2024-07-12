class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c=0; // to track the index of the first element of the sub str
        unordered_set<char> ch;
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            if(ch.count(s[i])==0){
                ch.insert(s[i]);
                maxlen=max(maxlen,i-c+1);
            }
            else{
                while(ch.count(s[i])){
                    ch.erase(s[c]);
                    c++;
                }
                ch.insert(s[i]);
            }
        }
        return maxlen;
    }
};
