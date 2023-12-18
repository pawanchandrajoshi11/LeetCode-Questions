class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size();
        int sp = p.size();

        if(sp > ss){
            return {};
        }

        vector<int> sfreq(26,0);
        vector<int> pfreq(26,0);


        // for first window
        for(int i=0; i<sp; i++){
            pfreq[p[i]-'a']++;
            sfreq[s[i]-'a']++;
        }

        vector<int> ans;

        // checking if first window is an anagram
        if(sfreq == pfreq){
            ans.push_back(0);
        }

        for(int i=sp; i<ss; i++){
            sfreq[s[i - sp]-'a']--;
            sfreq[s[i]-'a']++;

            if(sfreq == pfreq){
                ans.push_back(i-sp+1);
            }
        }
        return ans;
    }
};