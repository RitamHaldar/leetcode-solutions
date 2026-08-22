class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size();
        int minidex=-1;
        int minrange=INT_MAX;
        for (int i=0;i<n;i++){
            int range=abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
            if (range<=drones[i][2] && range<minrange){
                minidex=i;
                minrange=range;
                    
            }
        }
        return minidex;
    }
};
