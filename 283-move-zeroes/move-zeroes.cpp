class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Optimal Approach - O(N)
        // first find the first zero and mark its index
        int j=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                j=i;
                break;
            }
        }

        // returning if the array doesn't have any zeros
        if(j == -1){
            return;
        }

        // moving zeros algo
        for(int i=j+1; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};