
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
                continue;
            }

            if (stk.empty()) {
                return false;
            }

            if (s[i] == ')' && stk.top() == '(') {
                stk.pop();
                continue;
            }
            if (s[i] == '}' && stk.top() == '{') {
                stk.pop();
                continue;
            }
            if (s[i] == ']' && stk.top() == '[') {
                stk.pop();
                continue;
            }

            return false;
        }

        return stk.empty();
    }
};
