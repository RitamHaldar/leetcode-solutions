class Solution {
public:
    bool isPalindrome(long int x) {
        long int y=x,sum=0;
        if(x<0) return false;
        while (y!=0){
            int ld=y%10;
            sum=(sum*10)+ld;
            y/=10;
        }
        if(sum==x)return true;
        else return false;
    }
};
