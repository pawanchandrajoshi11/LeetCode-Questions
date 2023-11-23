class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        // INTUITION IS TO FIND THE SORTED HALF
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }

            //left sorted half
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    //eliminate the right half
                    high = mid-1;
                }else{
                    //eliminate the left half
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
        return -1;
    }
};