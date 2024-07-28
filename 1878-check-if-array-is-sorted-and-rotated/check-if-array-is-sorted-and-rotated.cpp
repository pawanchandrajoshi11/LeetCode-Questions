class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int breakPoints = 0;
        for(int i=0; i<size; i++){
            if(nums[i] > nums[(i+1) % size]){ // % size to check for the last element with first element
                breakPoints++;
            }
        }
        return breakPoints <= 1;
    }
};