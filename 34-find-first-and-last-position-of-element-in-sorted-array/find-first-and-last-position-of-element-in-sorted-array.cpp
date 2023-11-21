class Solution {
public:
    int firstOccurance(vector<int> &nums,int n, int target){
        int low=0, high=n-1;
        int first = -1;
        while(low <= high){
            int mid = low+(high-low)/2;

            if(nums[mid] == target){
                first = mid;
                high = mid - 1; // as it is already present, in order to find the first occurance we will look into the left half.
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return first;
    }

    int lastOccurance(vector<int> &nums, int n, int target){
        int low=0, high=n-1;
        int last = -1;
        while(low <= high){
            int mid = low+(high-low)/2;

            if(nums[mid] == target){
                last = mid;
                low = mid + 1; // as it is already present, in order to find the last occurance we will look into the right half.
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // OPTIMAL APPROACH USING LOWER AND UPPER BOUND
        int n=nums.size();
        int first = firstOccurance(nums, n, target);
        if(first == -1){
            return {-1,-1};
        }

        int last = lastOccurance(nums, n, target);

        return {first, last};



        
        // // BETTER SOLN
        // int first = -1, last = -1;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] == target){
        //         if(first == -1){
        //             first = i;
        //         }
        //         last = i;
        //     }
        // }

        // vector<int> ans;

        // if(first == -1){
        //     ans.push_back(-1);
        //     ans.push_back(-1);
        //     return ans;
        // }
        
        // ans.push_back(first);
        // ans.push_back(last);
        // return ans;
    }
};