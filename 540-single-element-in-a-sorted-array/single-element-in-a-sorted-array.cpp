class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // using XOR operator
        int Xor = 0;
        for(int i=0; i<nums.size(); i++){
            Xor = Xor ^ nums[i];
        }
        return Xor;
    }
};