class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k==1) return nums;
        deque<int> q;
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            while(q.size()>0 && nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
            int j=i-k+1;
            while(q.front()<j) q.pop_front();
            if(i>=k-1) ans.push_back(nums[q.front()]);
        }
        return ans;

    }
};
