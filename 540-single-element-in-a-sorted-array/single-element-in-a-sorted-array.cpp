class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // APPROACH - 1 -> O(log N) using binary search
        int n = nums.size();
        if(n == 1){
            // only one element is present in array
            return nums[0];
        }

        if(nums[0] != nums[1]){
            // for the first element
            return nums[0];
        }

        if(nums[n-1] != nums[n-2]){
            // for the last element
            return nums[n-1];
        }

        int low = 1, high = n-2;
        while(low <= high){
            int mid = low+(high-low)/2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

            // we are in left half
            if((mid%2 == 1 && nums[mid] == nums[mid-1]) || 
            (mid%2 == 0 && nums[mid] == nums[mid+1])){
                low = mid+1;
            }else
            {
                //we are in right half
                high = mid-1;
            }
        }
        return -1;



        // APPROACH - 2 -> O(n)
        // using XOR operator
        // int Xor = 0;
        // for(int i=0; i<nums.size(); i++){
        //     Xor = Xor ^ nums[i];
        // }
        // return Xor;



        // APPROACH - 3 -> O(n)
        // using normal iteration
        // int n = nums.size();
        // if(n==1)    return nums[0];

        // for(int i=0; i<n; i++){
        //     if(i==0){
        //         //first element
        //         if(nums[i] != nums[i+1]){
        //             return nums[i];
        //         }
        //     }else if(i == n-1){
        //         //last element
        //         if(nums[i] != nums[i-1]){
        //             return nums[i];
        //         }
        //     }else{
        //         //other element
        //         if(nums[i] != nums[i+1] && nums[i] != nums[i-1]){
        //             return nums[i];
        //         }
        //     }
        // }
        return -1;
    }
};