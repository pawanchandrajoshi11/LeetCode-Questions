class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_map<string, int> mpp;
        for(auto it: paths){
            mpp[it[0]]++;   //starting city - inc its pointer by +1
            mpp[it[1]]--;   //ending city - dec its pointer by -1
        }

        // london, 0 -> 1 ->
        // nyc, 0 -> -1 -> 0
        // lima, 0 -> -1 -> 0
        // sao, 0 -> -1    --> at the end, what we observed it, our destination city will end up having -1 as its count.

        for(auto it: mpp){
            if(it.second == -1){
                return it.first;
            }
        }

        return "";
    }
};