class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        int sum=0;
        while(num>=10){
            sum=0;
            while(num>0){
                int temp=num%10;
                sum+=temp;
                num=num/10;
            }
            num=sum;
        }
        return sum;
    }
};