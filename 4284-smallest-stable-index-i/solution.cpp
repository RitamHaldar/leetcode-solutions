class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> stability(n,0);
        for (int i=0;i<n;i++){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for (int j=0;j<n;j++){
                if(j<i){
                    maxi=max(maxi,nums[j]);
                }else if(j==i){
                    maxi=max(maxi,nums[j]);
                    mini=min(mini,nums[j]);
                }
                else mini=min(mini,nums[j]);

            }
            stability[i]=maxi-mini;
        }
        int res=-1;
        for (int i=0;i<n;i++){
            if(stability[i]<=k){
                return i;
            }
        }
        return res;

    }
};
