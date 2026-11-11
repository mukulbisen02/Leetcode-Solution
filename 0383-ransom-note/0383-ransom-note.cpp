class Solution {
public:
    bool fun(unordered_map<char, int> need, unordered_map<char, int> have) {
        for (auto i : need) {
            int c = i.first;
            int fNeed = i.second;

            int fHave = have[c];

            if (fHave < fNeed)
                return false;
        }
        return true;
    }
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> need;
        for (int i = 0; i < ransomNote.size(); i++) 
            need[ransomNote[i]]++;
        

        unordered_map<char, int> have;
        for (int i = 0; i < magazine.size(); i++) 
            have[magazine[i]]++;

        return fun(need, have);
    }
};