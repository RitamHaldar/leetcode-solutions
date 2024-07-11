class Solution {
public:
    int divide(long int dividend, long int divisor) {
        bool neg=false;
        if(dividend<0&&divisor<0){
            dividend=-dividend;
            divisor=-divisor;
            neg=false;
        }
        else if(dividend<0){
            dividend=-dividend;
            neg=true;
        }
        else if(divisor<0){
            divisor=-divisor;
            neg=true;
        }
        long int i=1,sum=divisor;
        while(sum<=dividend){
            sum+=divisor;
            i++;
        }
        if(neg){
            return-(i-1);
        }
        return i-1;
    }
};