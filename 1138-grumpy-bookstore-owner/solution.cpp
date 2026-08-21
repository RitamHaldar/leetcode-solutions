class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k=minutes;
        int n=customers.size();
        int previousloss=0;
        for (int i=0;i<n;i++){
            if(grumpy[i]==1) previousloss+=customers[i];
        }
        int maxloss=previousloss;
        int i=1;
        int j=k;
        int maxindex=0;
        while(j<n){
            int currentloss=previousloss;
            if(grumpy[j]==1) currentloss+=customers[j];
            if(grumpy[i-1]==1) currentloss-=customers[i-1];
            if(maxloss<currentloss){
                maxloss=currentloss;
                maxindex=i;
            }
            previousloss=currentloss;
            i++;
            j++;
        }
        for (int i=maxindex;i<maxindex+k;i++){
            grumpy[i]=0;
        }
        int sum=0;
        for (int i=0;i<n;i++){
            if(grumpy[i]==0) sum+=customers[i];
        }
        return sum;

    }
};
