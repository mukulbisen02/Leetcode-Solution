class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Approach 1
        int freq[26] = {0};                 //Fixed-size array
        // unordered_map<char,/ int> freq;  //Hash Map

        for (int i = 0; i < magazine.size(); i++) {
            freq[magazine[i] - 'a']++;  //Fixed-size array
            // freq[magazine[i]]++;     //Hash Map
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            freq[ransomNote[i] - 'a']--;    //Fixed-size array
            // freq[ransomNote[i]]--;       //Hash Map

            if (freq[ransomNote[i] - 'a'] < 0) return false;    //Fixed-size array
            // if (freq[ransomNote[i]] < 0) return false;       //Hash Map
        }
        return true;
    }

    // Approach 2
    // bool fun(unordered_map<char, int> need, unordered_map<char, int> have) {
    //     for (auto i : need) {
    //         int c = i.first;
    //         int fNeed = i.second;

    //         int fHave = have[c];

    //         if (fHave < fNeed)
    //             return false;
    //     }
    //     return true;
    // }
    // bool canConstruct(string ransomNote, string magazine) {
    //     unordered_map<char, int> need;
    //     for (int i = 0; i < ransomNote.size(); i++)
    //         need[ransomNote[i]]++;

    //     unordered_map<char, int> have;
    //     for (int i = 0; i < magazine.size(); i++)
    //         have[magazine[i]]++;

    //     return fun(need, have);
    // }
};