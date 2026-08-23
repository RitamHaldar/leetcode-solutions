class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int window=0;
        int count=0;
        for (int i=0;i<k;i++){
            window+=arr[i];
        }
        if(window/k>=threshold) count++;
        int i=0,j=k;
        while(j<n){
            window-=arr[i];
            i++;
            window+=arr[j];
            j++;
            if (window/k>=threshold) count++;
        }
        return count;
    }
};
