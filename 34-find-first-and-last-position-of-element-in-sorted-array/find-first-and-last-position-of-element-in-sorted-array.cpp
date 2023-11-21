class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // BETTER SOLN
        int first = -1, last = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                if(first == -1){
                    first = i;
                }
                last = i;
            }
        }

        vector<int> ans;

        if(first == -1){
            ans.push_back(-1);
            ans.push_back(-1);

            return ans;
        }
        
        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};