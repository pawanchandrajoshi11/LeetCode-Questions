class Solution {
public:

//     Reverse whole string then reverse word by word - O(1) in Space Complexity

// Reverse the whole string.
// Then we iterate characters in string s, fill found word into s then reverse it, word by word.
// Let l keep the starting index of the current word, r keep the next index for filling the current word.
// Reverse the current word, which is s[l..r-1]
// Set space character for character s[r] if r < s.size()
// Finally, resize the string s to remove redundant chars.
// image

    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int L=0, R=0, n=s.size(), i=0;
        while(i<n){
            while(i<n && s[i] == ' ')   i++;
            while(i<n && s[i] != ' ')   s[R++] = s[i++];

            if(L < R){
                reverse(s.begin()+L, s.begin()+R);
                s[R]=' ';
                R++;
                L = R;
            }
            i++;
        }

        if(R > 0) s.resize(R-1);
        return s;
    }
};