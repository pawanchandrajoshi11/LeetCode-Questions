class Solution {
public:
    int maxScore(string s) {
        int leftZeros = 0, rightOnes = 0;
        for(auto it: s){
            if(it == '1'){
                rightOnes++;
            }
        }

        int score = 0;

        // "s.length()-1" because we want to have two sides, left one and right one. So right one will have a minimum of 1 element in it. That's why we have to leave one element for it.
        for(int i=0; i<s.length()-1; i++){
            if(s[i] == '0'){
                leftZeros++;
            }else{
                // s[i] == '1'
                rightOnes--;
            }

            score = max(score, leftZeros + rightOnes);
        }

        return score;
    }
};