class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> mst(n);
        stack<int> st;
        mst[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while (st.size()>0 && heights[st.top()]>=heights[i]) st.pop();
            if(st.size()==0) mst[i]=n;
            else mst[i]=st.top();
            st.push(i);
        }
        vector<int> lst(n);
        stack<int> gt;
        lst[0]=-1;
        gt.push(0);
        for(int i=1;i<n;i++){
            while (gt.size()>0 && heights[gt.top()]>=heights[i]) gt.pop();
            if(gt.size()==0) lst[i]=-1;
            else lst[i]=gt.top();
            gt.push(i);
        }
        int maxarea=0;
        for (int i=0;i<n;i++){
            int area=heights[i]*(mst[i]-lst[i]-1);
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};
