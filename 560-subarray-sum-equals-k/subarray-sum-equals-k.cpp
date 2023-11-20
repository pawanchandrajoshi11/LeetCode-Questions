class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //optimised approach - TC->O(N), SC->O(N)
        unordered_map<int, int> mpp;        //<newsum, frequency of this new sum>mpp
        int presum=0; 
        int count=0;
        for(int i=0; i<nums.size(); i++){
            
            //counting the sum of every element
            presum += nums[i];
            //this will work for the first sum == k
            if(presum == k){       
                count++;
            }

            //for remaining, first find the remainder 
            int rem = presum - k;

            //update the {sum: freq} inside hashmap, as whenever will find a new sum == k, we will look for whether the remainder is present or not, if present -> we will look for how many subarray ie. freq were present inside hashmap, this will give us an idea that till now these many subarrays had this same sum. and we will add that in our count. 
            // eg: [1,2,3,-3,1,1,1,4,2,-3]

            if(mpp.find(rem) != mpp.end()){
                count += mpp[rem];
            }

            //inc the frequency of previous same sum present
            mpp[presum]++;
        }

        return count;



        // //better approach - O(N2)
        // int count = 0;
        // for(int i=0; i<nums.size(); i++){
        //     int sum = 0;
        //     for(int j=i; j<nums.size(); j++){
        //         sum +=nums[j]; 
        //         if(sum == k){
        //         count++;
        //     }
        //     }
        // }
        // return count;


        // //brute approach - O(N3)
        // int count = 0;
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i; j<nums.size(); j++){
        //         int sum = 0;
        //         for(int k=i; k<=j; k++){
        //             sum += nums[k];
        //         }
        //         if(sum == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
    }
};