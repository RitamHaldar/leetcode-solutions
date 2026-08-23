class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n= satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int count=0,idx=0,result=0;
        vector<int> res(n);
        for (int i=n-1;i>=0;i--){
            count+=satisfaction[i];
            if(count<0){
                idx=i+1;
                break;
            }
        }
        for (int i=idx;i<n;i++){
            result+=satisfaction[i]*(i-idx+1);
        }
        return result;
    }
};