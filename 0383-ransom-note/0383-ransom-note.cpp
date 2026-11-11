class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;

        for (int i = 0; i < magazine.size(); i++) {
            freq[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            freq[ransomNote[i]]--;

            if (freq[ransomNote[i]] < 0)
                return false;
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