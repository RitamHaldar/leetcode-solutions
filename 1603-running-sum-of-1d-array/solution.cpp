class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prevsum=0;
        for (int i=0;i<nums.size();i++){
            prevsum+=nums[i];
            nums[i]=prevsum;
        }
        return nums;
    }
};
