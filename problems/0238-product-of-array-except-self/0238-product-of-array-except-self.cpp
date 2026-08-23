class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int k=n;
        vector<int> postprod(n);
        for (int i=0;i<n;i++){
            if(i==0) postprod[i]=1;
            else{
                postprod[i]=postprod[i-1]*nums[i-1];
            }
        }
        int p=nums[n-1];
        for (int i =n-2;i>=0;i--){
            postprod[i]*=p;
            p*=nums[i];
        }
        return postprod;

    }
};