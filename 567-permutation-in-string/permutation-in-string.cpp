class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // perform a dry run and first visit 'find all anagram in a string leetcode question'
        int ss1 = s1.size();
        int ss2 = s2.size();

        vector<int> ss1freq(26,0);
        vector<int> ss2freq(26,0);

        bool flag = false;

        if(ss1 > ss2){
            // size of s1 is greater than that of s2, therefore s2 won't be able of contain any permutation of s1
            return flag;
        }

        // for first window of size equals size of s1
        for(int i=0; i<ss1; i++){
            ss1freq[s1[i]-'a']++;
            ss2freq[s2[i]-'a']++;
        }

        if(ss1freq == ss2freq){
            flag = true;
            return flag;
        }

        // for remaining string with window size ss1
        for(int i=ss1; i<ss2; i++){
            ss2freq[s2[i-ss1]-'a']--;
            ss2freq[s2[i]-'a']++;

            if(ss1freq == ss2freq){
                flag = true;
                break;
            }
        }

        return flag;
    }
};