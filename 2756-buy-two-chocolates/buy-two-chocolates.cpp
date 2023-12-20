class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first = INT_MAX, second = INT_MAX;
        
        for(auto it: prices){
            if(it < first){
                second = first;
                first = it;
            }else if(it < second){
                second = it;
            }
        }
        // cout<<first<<second;
        int ans = money - first - second;
        if(ans >= 0){
            return ans;
        }
        return money;
    }
};