class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k<=1) return 0;
        int productscount=0;
        int product=1;
        int i=0,j=0;
        int n= nums.size();
        while(j<n){
            product*=nums[j];
            while(product>=k){
                productscount+=j-i;
                product/=nums[i];
                i++;
            }
            j++;
        
        }
        while(i<n){
            productscount+=j-i;
            i++;
        }
        return productscount;
    }
};
