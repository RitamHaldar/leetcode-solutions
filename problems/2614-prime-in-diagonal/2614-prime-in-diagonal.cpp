class Solution {
public:
    bool prime(int n){
        if (n==0 || n==1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if (n%i==0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int largestprime=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            if (prime(nums[i][i])) largestprime=max(largestprime,nums[i][i]);
            if (prime(nums[i][n-i-1])) largestprime=max(largestprime,nums[i][n-i-1]);
        }
        return largestprime;
    }
};