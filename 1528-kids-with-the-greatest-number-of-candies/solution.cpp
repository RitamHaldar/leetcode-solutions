class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxI=INT_MIN;
        vector<bool> res;
        for (int i=0;i<candies.size();i++){
            maxI=max(candies[i],maxI);
        }
        for (int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxI) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
