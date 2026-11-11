class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();

        int freq[26] = {0};                 //Fixed-size array
        // unordered_map<char, int>freq;    //Hash Map

        for (int i = 0; i < n; i++){
            freq[s[i] - 'a']++;     //Fixed-size array
            // freq[s[i]]++;        //Hash Map
        }

        for (int i = 0; i < n; i++){
            if (freq[s[i] - 'a'] == 1) return i;    //Fixed-size array
            // if (freq[s[i]] == 1) return i;       //Hash Map
        }
        return -1;
    }
};