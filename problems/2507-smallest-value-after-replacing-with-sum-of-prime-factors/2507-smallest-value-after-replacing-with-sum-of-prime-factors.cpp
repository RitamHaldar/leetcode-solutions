class Solution {
public:
    bool prime(int num){
        if (num==0 || num==1) return false;
        for (int i=2;i*i<=num;i++){
            if (num%i==0) return false;
        }
        return true;
    }
    int smallestValue(int n) {
        if (prime(n)) return n;
        int sum=0;
        for (int i=1;i<sqrt(n);i++){
            if (n%i==0 && prime(i)){
                int temp=n;
                while(temp%i==0){
                    temp=temp/i;
                    sum+=i;
                }
            }
        }
        for (int i=sqrt(n);i>=1;i--){
            if (n%i==0 && prime(n/i)){
                int temp=n;
                while(temp%(n/i)==0){
                    temp/=(n/i);
                    sum+=(n/i);
                }
            }
        }
        if(n==sum) return n;
        return smallestValue(sum);
    }
};