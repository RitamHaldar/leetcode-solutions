class Solution {
public:
    bool prime(int num){
        if (num<=1) return false;
        for (int i=2;i<=sqrt(num);i++){
            if (num%i==0) return false;
        }
        return true;
    }
    int gd(int num){
        for (int i=2;i<=sqrt(num);i++){
            if (num%i==0) return num/i;
        }
        return 1;
    }
    int minSteps(int n) {
        if (prime(n)) return n;
        int count=0;
        int mx=0;
        while(n>1){
            mx=gd(n);
            count+=n/mx;
            n=mx;
        }
        return count;
    }
};