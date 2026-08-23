class Solution {
public:
    int reverse(int x) {
        int temp=x;
        int power=INT_MAX;
        int sum=0;
        int t1;
        if(x>power||x<-power) return 0;
        if(temp>0){
            while(temp!=0){
                if((long int)sum*10>(long int)power) return 0;
                sum=sum*10+temp%10;
                temp=temp/10;
            }
        }
        if(temp<0){
            while(temp!=0){
                if(-(long int)sum*10>(long int)power) return 0;
                sum=sum*10+temp%10;
                temp=temp/10;
            
           
        }
        }
        return sum;
       
    }
};