class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;

            //if the seach space is already sorted, then low index will always be pointing towards the smallest element
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;
            }

            //else find the sorted half first
            //left sorted half
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;    //search in the other half now
            }else{
                //right sorted half
                ans = min(ans, nums[mid]);
                high = mid-1;   //search in the other half now
            }
        }

        return ans;
    }
};