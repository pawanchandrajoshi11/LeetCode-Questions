class Solution {
public:
    double calcTime(vector<int> &piles, int hourlyEat){
        double totalH = 0;
        for(int i=0; i< piles.size(); i++){
            totalH += ceil((double)piles[i]/(double)hourlyEat);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }

        int low=1, high=maxi;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(calcTime(piles, mid) <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};