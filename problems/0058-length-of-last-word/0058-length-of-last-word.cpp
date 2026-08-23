class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        bool flag=false;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                ans++;
                flag=true;
            }
            else if(flag==false){
                continue;
            }
            else{
                break;
            }
        }
        return ans;
        
    }
};