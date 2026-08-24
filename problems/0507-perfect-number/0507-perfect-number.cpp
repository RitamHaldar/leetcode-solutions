class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num==0 || num==1) return false;
        int sum=0;
        for(int i=1;i<sqrt(num);i++){
            if (num%i==0) sum+=i;
        }
        for (int i=sqrt(num);i>1;i--){
            if (num%i==0) sum+=num/i;
        }
        return num==sum;
    }
};