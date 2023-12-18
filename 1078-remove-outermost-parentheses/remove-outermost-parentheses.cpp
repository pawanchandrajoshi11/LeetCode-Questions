class Solution {
public:
    string removeOuterParentheses(string s) {
        int j=0;
        string ans = "";
        for(auto it: s){
            if(it == ')'){
                j--;
            }
            
            if(j != 0){
                ans += it;
            }
            
            if(it == '('){
                j++;
            }
        }

        return ans;
    }
};