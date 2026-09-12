class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map <int,int>count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            if(count[nums[i]]>1) return nums[i];
        }
        return 0;
    }
};
