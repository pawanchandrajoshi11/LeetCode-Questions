class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        // ans = (largest * secondLargest) - (smallest * secondSmallest)
        // TC: O(N)
        int a = INT_MIN;    // largest
        int b = INT_MIN;    // second largest
        int c = INT_MAX;    // smallest
        int d = INT_MAX;    // second smallest
        for(int i=0; i<nums.size(); i++){

            // finding largest and second largest
            if(nums[i] > a){
                b = a;
                a = nums[i];
            }else if(nums[i] > b){
                b = nums[i];
            }

            // finding smallest and second smallest
            if(nums[i] < c){
                d = c;
                c = nums[i];
            }else if(nums[i] < d){
                d = nums[i];
            }
        }
        return (a*b)-(c*d);



        // APPROACH 2 -> TC: O(N logN)
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // int a = nums[n-1];
        // int b = nums[n-2];
        // int c = nums[0];
        // int d = nums[1];

        // long long first = a * b;
        // long long second = c * d;

        // return first - second;
    }
};