class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {

        // SECOND OPTIMAL APPROACH -TC: O(N)
        int count = 1;
        int prev = arr[0];
        int quarter = arr.size()/4;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] == prev){
                count++;
            }else{
                count = 1;
            }

            if(count > quarter){
                return arr[i];
            }

            prev = arr[i];
        }
        return prev;
    }
};