
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char c : s) {
             if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) return false;
                char top = stk.top();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
                stk.pop();
            }

            //     if (c == '(' || c == '{' || c == '[') {
            //         stk.push(c);
            //         continue;
            //     }
            //     if (stk.empty()) {
            //         return false;
            //     }
            //     if (c == ')' && stk.top() == '(') {
            //         stk.pop();
            //         continue;
            //     }
            //     if (c == '}' && stk.top() == '{') {
            //         stk.pop();
            //         continue;
            //     }
            //     if (c == ']' && stk.top() == '[') {
            //         stk.pop();
            //         continue;
            //     }
            //     return false;

        }
        
        return stk.empty();
    }
};
