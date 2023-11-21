class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int ans=nums.size();

        // using binary search's lower bound algorithm
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= target){    // this might be my ans
                ans = mid;
                high = mid-1;   // but look for more smaller index on left
            }else{
                low = mid+1;    // look in the right
            }
        }
        return ans;
    }
};