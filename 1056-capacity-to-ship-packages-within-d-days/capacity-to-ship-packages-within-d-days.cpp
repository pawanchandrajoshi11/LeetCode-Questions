class Solution {
public:
    int totalDays(vector<int> &weights, int capacity){
        int days = 1, load = 0;
        for(int i=0; i<weights.size(); i++){
            if(load + weights[i] > capacity){
                days++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // OPTIMAL USING BINARY SEARCH
        int maxi = INT_MIN;
        int sumOfWeights = 0;
        for(auto it: weights){
            maxi = max(maxi, it);
            sumOfWeights += it;
        }
        int low = maxi, high = sumOfWeights;
        int ans = -1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(totalDays(weights, mid) <= days){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};