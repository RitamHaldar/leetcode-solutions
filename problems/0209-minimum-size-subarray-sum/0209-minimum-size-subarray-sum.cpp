class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int i=0,j=0;
        int length=0;
        int minlen=INT_MAX;
        while (j<n){
            sum+=nums[j];
            if(sum>=target){
                while(sum>=target){
                    sum-=nums[i];
                    length=j-i+1;
                    minlen=min(length,minlen);
                    i++;
                    }
            }
            j++;
        }
        return min(minlen,length);
    }
};