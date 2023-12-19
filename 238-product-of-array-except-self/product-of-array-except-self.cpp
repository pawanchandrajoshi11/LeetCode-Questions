class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // do a dry run first, this questions is not that hard XD
        // result[i] = multiply all on left * multiply all on right
        vector<int> res(nums.size());
        res[0] = 1;
        for(int i=1; i<nums.size(); i++){
            res[i] = res[i-1] * nums[i-1];
        }

        int right=1;
        for(int i=nums.size()-1; i>=0; i--){
            res[i] = res[i] * right;
            right = right * nums[i];
        }

        return res;
    }
};