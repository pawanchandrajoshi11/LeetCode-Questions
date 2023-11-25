class Solution {
public:
    bool isPossible(vector<int> &bloomDay, int day, int m, int k){
        int count=0;
        int nBloom = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }else{
                nBloom += (int)count/(int)k;
                count = 0; //very important
            }
        }
        nBloom += count/k;
        if(nBloom >= m){
            return true;
        }            
        
        return false;
    }

    int findMin(vector<int> &arr){
        int mini = INT_MAX;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] < mini){
                mini = arr[i];
            }
        }
        return mini;
    }

    int findMax(vector<int> &arr){
        int maxi = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > maxi){
                maxi = arr[i];
            }
        }
        return maxi;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // OPTIMAL APPROACH USING BINARY SEARCH 
        long long totalBouquetsFlowers = (long long)m * (long long)k;
        if(totalBouquetsFlowers > bloomDay.size()){
            return -1;
        }

        int low = findMin(bloomDay);
        int high = findMax(bloomDay);
        int ans = -1;

        while(low <= high){
            int mid = low+(high-low)/2;
            if(isPossible(bloomDay, mid, m, k) == true){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        return ans;



        //BRUTE -> ITERATIVE APPROACH, TC: O(maxi-min+1) * N; = TLE on big test cases
        // int mini = findMin(bloomDay);
        // int maxi = findMax(bloomDay);
        // for(int i=mini; i<=maxi; i++){
        //     if(isPossible(bloomDay, i, m, k) == true){
        //         return i;
        //     }
        // }
        // return -1;
    }
};