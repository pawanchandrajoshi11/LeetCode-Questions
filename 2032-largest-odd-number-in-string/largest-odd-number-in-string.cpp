class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        // FIRST RUN A LOOP FROM THE END OF THE STRING TO THE BEGINNING

        for(int i=n-1; i>=0; i--){
            // IF IT IS AN EVEN NUMBER
            if(num[i] % 2 == 0){
                num.pop_back();
                // this POP_BACK() will remove the last char from the string, decreasing its length by one
            }else{
                // ELSE WE KNOW THAT THE NUMBER IS ODD AND WE BREAK OUT OF THE LOOP
                break;
            }
        }
        return num;
    }
};