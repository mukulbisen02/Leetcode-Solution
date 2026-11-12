class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> have;
        for (int i = 0; i < text.size(); i++) {
            have[text[i]]++;
        }

        string s = "balloon";
        unordered_map<char, int> need;
        for (int i = 0; i < s.size(); i++){
            need[s[i]]++;
        }
        // unordered_map<char, int> need;
        // need['b'] = 1;
        // need['a'] = 1;
        // need['l'] = 2;
        // need['o'] = 2;
        // need['n'] = 1;

        int result = INT_MAX;
        for (auto i : need){
            char ch = i.first;
            int fNeed = i.second;
            int fHave = have[ch];

            int times = fHave/fNeed;

            result = min(result, times);
        }
        return result;
    }
};