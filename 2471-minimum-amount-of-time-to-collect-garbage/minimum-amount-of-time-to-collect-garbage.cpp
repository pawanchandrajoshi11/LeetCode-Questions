class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int countG=0, countP=0, countM=0;
        int lastG=0, lastP=0, lastM=0;
        int nt = travel.size();
        vector<long long>presum(nt+1);
        presum.push_back(0);
        int ans = 0;
        
        //counting all the prefix sum
        int sum = 0;
        for(int i=1; i<=travel.size(); i++){
            presum[i] = presum[i-1] + travel[i-1]; 
        }

        //traversing in the garbage array
        for(int i=0; i<garbage.size(); i++){

            string str = garbage[i];
            for(auto s: str){
                if(s == 'G'){
                    countG++;
                    lastG=i;
                }
                if(s == 'P'){
                    countP++;
                    lastP=i;
                }
                if(s == 'M'){
                    countM++;
                    lastM=i;
                }
            }
        }

        if(countG) ans += (countG + presum[lastG]);
        if(countP) ans += (countP + presum[lastP]);
        if(countM) ans += (countM + presum[lastM]);

        return ans;
    }
};