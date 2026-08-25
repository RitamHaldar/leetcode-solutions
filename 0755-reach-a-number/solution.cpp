class Solution {
public:
    int reachNumber(int target) {
        int sum=0;
        int n=0;
        target=abs(target);
        while(sum<target || (target-sum)%2!=0){
            n++;
            sum+=n;
        }
        return n;
    }
};
