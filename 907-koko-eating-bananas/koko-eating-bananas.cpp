class Solution {
public:
    double calcTime(vector<int> &piles, int hourlyEat){
        double totalH = 0;
        for(int i=0; i<piles.size(); i++){
            totalH += ceil((double)piles[i]/(double)hourlyEat);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        //OPTIMISED APPROACH - O(logN + N) using binary search
        int n=piles.size();
        sort(piles.begin(), piles.end());
        int maxEle = piles[n-1];
        int low=1, high=maxEle;
        while(low <= high){
            int mid = low+(high-low)/2;

            double reqTime = calcTime(piles, mid);
            if(reqTime <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;


        // BRUTE APPROACH - O(max(piles) * n) - TIME LIMIT EXCEEDED
        // sort(piles.begin(), piles.end());
        // int n = piles.size();
        // int max = piles[n-1];
        // for(int i=1; i<= max; i++){
        //     int reqTime = calcTime(piles, i);

        //     if(reqTime <= h){
        //         return i;
        //     }
        // }
        // return -1;
    }
};