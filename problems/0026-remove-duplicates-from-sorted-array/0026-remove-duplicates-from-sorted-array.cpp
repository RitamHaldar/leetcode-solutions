class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int j=0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        set<int>::iterator itr1;
        for(itr1= s.begin();itr1!=s.end();itr1++){
            nums[j]=*itr1;
            j++;
        }
        return s.size();
    }
};