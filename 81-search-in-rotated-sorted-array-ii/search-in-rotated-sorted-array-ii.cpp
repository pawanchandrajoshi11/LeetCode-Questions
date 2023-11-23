class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int isFound = false;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target) {
                isFound = true;
                break;
            }

            // edge case soln, [3,1,2,3,3,3,3,3,3], here we cannot tell which half is sorted hence have to did this
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low+1;
                high = high-1;
                continue;
            }

            //find the sorted half now
            if(nums[low] <= nums[mid]){
                //left sorted half
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                }else{
                    //although the left half is sorted but the element we are looking for is not present in that half, hence we've to trim our search space
                    low = mid+1;
                }

            }else{
                //right sorted half
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return isFound;
    }
};