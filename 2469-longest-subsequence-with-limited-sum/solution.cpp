class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int> result;
        sort(nums.begin(),nums.end());
        for (int k=0;k<m;k++){
            int count=0;
            int j=0,sum=0;
            while(j<n){
                sum+=nums[j];
                if (sum<=queries[k]){
                    count++;
                }
                else{
                    break;
                }
                j++;
            }
            result.push_back(count);
        }
        return result;
    }
};
