class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=k;
        int window=0;
        for (int i =0;i<k;i++){
            window+=nums[i];
        }
        int maxsum=window;
        while(j<n){
            window-=nums[i];
            window+=nums[j];
            maxsum=max(maxsum,window);
            j++;
            i++;
        }
        return maxsum/double(k);
    }
};
