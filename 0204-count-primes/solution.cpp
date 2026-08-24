class Solution {
public:
    void fillsieve(vector<bool>& sieve){
        int n=sieve.size();
        for (int i=4;i*i<=n;i+=2){
            sieve[i]=0;
        }
        for (int i=3;i*i<=n;i+=2){
            if(sieve[i]){
                for (int j=i*i;j<=n;j+=i*2){
                    sieve[j]=0;
                }
            }
            
        }
    }
    int countPrimes(int n) {
        if (n<=2) return 0;
        int count=0;
        vector<bool> sieve(n,1);
        fillsieve(sieve);
        sieve[0]=0;
        sieve[1]=0;
        count=1;
        for (int i=3;i<n;i+=2){
            if (sieve[i]==1) count++;
        }
        return count;
    }
};
