class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> res(n,0);
        stack<int> st;
        res[n-1]=0;
        st.push(heights[n-1]);
        for (int i=n-2;i>=0;i--){
            int count = 0;
            while (st.size()>0 && heights[i]>st.top()){
                count++;
                st.pop();
            }
            if(st.size()!=0) count++;
            res[i]=count;
            st.push(heights[i]);
        }
        return res;
    }
};
