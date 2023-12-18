class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        // TC: O(N logN)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = nums[n-1];
        int b = nums[n-2];
        int c = nums[0];
        int d = nums[1];

        long long first = a * b;
        long long second = c * d;

        return first - second;
    }
};