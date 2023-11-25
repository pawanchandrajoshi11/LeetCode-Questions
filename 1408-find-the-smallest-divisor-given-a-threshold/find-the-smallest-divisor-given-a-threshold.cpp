class Solution {
public:
    int findDivSum(vector<int> &nums,int mid, int threshold){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += ceil((double)nums[i]/(double)mid);
        }
        if(sum <= threshold){
            return mid;
        }
        return -1;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        // USING BINARY SEARCH
         int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        int low=1, high=maxi;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(findDivSum(nums, mid, threshold) == -1){
                low = mid+1;
            }else{
                high = mid-1;
                ans = mid;
            }
        }
        return ans;



        //BRUTE: TC:O(maxi * N), SC: O(1), will give TIME LIMIT EXCEEDED
        // int maxi = INT_MIN;
        // for(int i=0; i<nums.size(); i++){
        //     maxi = max(maxi, nums[i]);
        // }

        // for(int d=1; d<=maxi; d++){
        //     int sum = 0; 
        //     for(int i=0; i<nums.size(); i++){
        //         sum += ceil((double)nums[i]/(double)d); //beware of this thing, int/int will give int and truncates the point part, hence ceil function will not have any effect on the intergers
        //     }
        //     if(sum <= threshold){
        //         return d;
        //     }
        // }
        // return -1;
    }
};