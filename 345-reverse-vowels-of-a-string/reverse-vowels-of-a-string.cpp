class Solution {
public:
    string reverseVowels(string s) {
        string word = s;
        int start = 0;
        int end = s.length()-1;
        string vowels = "aeiouAEIOU";
        while(start < end){
            while(start < end && vowels.find(word[start]) == string::npos){
                start++;
            }


            //It is a constant static member value with the highest possible value for an element of type size_t.
// It actually means until the end of the string.
// as a return value, it is usually used to indicate no matches.
            while(start < end && vowels.find(word[end]) == string::npos){
                end--;
            }

            swap(word[start], word[end]);

            start++;
            end--;
        }
        return word;
    }
};