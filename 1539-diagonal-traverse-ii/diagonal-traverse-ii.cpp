class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mpp;  
        int maxKey = 0;

        // INSERTING INTO MAP, DIAGONAL ELEMENTS IN MATRIX HAVE SAME (i+j) sum
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){ // RUN LOOP FOR THE LENGTH OF PARTICULAR ROWS
                mpp[i+j].push_back(nums[i][j]);
                maxKey = max(maxKey, i+j);  // STORING MAX-KEY FOR LATER TRAVERSAL
            }
        }

        // DRY RUN IN ORDER TO GET THIS THING, MAKE A 4X4 MATRIX AND PRINT IT, YOU'LL GET IT YOURSELF.
        //HERE YOU'VE TO RUN A REVERSE LOOP INSIDE THE SECOND PART OF MAP IN ORDER TO PRINT THE REQUIRED OUTPUT.

        vector<int> ans;
        for(int i = 0; i <= maxKey; i++){
            for(auto x=mpp[i].rbegin(); x!= mpp[i].rend(); x++){
                ans.push_back(*x);

                // vector rbegin() and rend() methods return a reverse iterator pointing to the reverse location, hence I used * to get iterator value.
            }
        }
        return ans;
    }
};