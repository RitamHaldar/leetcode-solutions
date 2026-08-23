class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,deleted=0;
        int len=INT_MIN,maxlen=INT_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(deleted<1){
                    deleted++;
                    j++;
                }
                else{
                    len=j-i;
                    maxlen=max(len,maxlen);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
            len=j-i;
            maxlen=max(len,maxlen);
        }
        return maxlen-1;
    }
};