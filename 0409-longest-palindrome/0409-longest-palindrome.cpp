class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        bool odd = false;
        int result = 0;

        for (auto i : freq) {
            int count = i.second;

            if (count % 2 == 0) {
                result += count;
            } else {
                odd = true;
                result += count - 1;
            }
        }

        if (odd == false) {
            return result;
        }

        // for (auto i : freq) {
        //     int count = i.second;

        //     if (count % 2 == 1) {
        //         result += count - 1;
        //     }
        // }
        return result + 1;
    }
};