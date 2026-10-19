class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        int found = true;

        while (found) {
            found = false;
            for (int i = 0; i < n; i++) {
                if (s[i] == s[i + 1]) {
                    s.erase(i, 2);
                    found = true;
                    break;
                }
            }
        }
        return s;
    }
};