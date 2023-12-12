class Solution {
public:
    int maxProduct(vector<int>& nums) {

        //OPTIMAL: FIND THE BIGGEST AND SECOND BIGGEST NUMBER
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > largest){
                secondLargest = largest;
                largest = nums[i];
            }else if(nums[i] > secondLargest){
                secondLargest = nums[i];
            }
        }
        int product = (largest-1) * (secondLargest-1);
        return product;

        // int maxi = INT_MIN;
        // for(int i=0; i<nums.size()-1; i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         int a = nums[i]-1;
        //         int b = nums[j]-1;
        //         int temp = a * b;
        //         maxi = max(maxi, temp);
        //     }
        // }
        // return maxi;
    }
};