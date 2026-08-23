class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,flipcount=0;
        int len=INT_MIN,maxlen=INT_MIN;
        while(j<n){
            if (nums[j]==1) j++;
            else{
                if(flipcount<k){
                    flipcount++;
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
        return max(len,maxlen);
    }
};