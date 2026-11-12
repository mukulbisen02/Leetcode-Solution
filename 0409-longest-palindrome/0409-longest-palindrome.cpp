class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
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

        // type 1 for answer
        // if (odd == false) {
        //     return result;
        // }
        // return result + 1;

        //or
        // type 2 for answer
        return result + odd;
    }
};