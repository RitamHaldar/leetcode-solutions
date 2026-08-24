class Solution {
public:
    void fillsieve(vector<bool>& sieve){
        int n=sieve.size();
        for (int i=2;i*i<=n;i++){
            if(sieve[i]){
                for (int j=i*2;j<=n;j+=i){
                    sieve[j]=0;
                }
            }
            
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int count=0;
        int max=-1;
        for(int i=0;i<nums.size();i++){
            if (nums[i]>max){
                max=nums[i];
            }
        }
        vector<bool> sieve(max+1,1);
        vector<int> primes;
        sieve[0]=0;
        sieve[1]=0;
        fillsieve(sieve);
        for (int i=1;i<=max;i++){
            if (sieve[i]==1) primes.push_back(i);
        }
        
        vector<bool> factor(primes.size(),0);
        for (int i=0;i<nums.size();i++){
            int elem=nums[i];
            for (int j=0;j<primes.size();j++){
                if (primes[j]>elem) break;
                if (elem%primes[j]==0) factor[j]=1;
            }
        }
        for (int i=0;i<factor.size();i++){
            if (factor[i]==1) count++;
        }
        return count;

    }
};