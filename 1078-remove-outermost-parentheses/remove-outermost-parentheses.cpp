class Solution {
public:
    string removeOuterParentheses(string s) {
        // TC: O(N)
        string str = "";
        int opened = 0;
        for(auto it: s){
            if(it == '('){
                if(opened > 0){
                    str += it;
                }
                opened++;
            }else{
                if(opened > 1){
                    str += it;
                }
                opened--;
            }
        }
        return str;
    }
};