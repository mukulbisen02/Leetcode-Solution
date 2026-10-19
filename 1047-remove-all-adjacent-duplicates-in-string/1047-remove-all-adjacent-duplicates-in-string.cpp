class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string result;

        // Normal String Method
        for (char c : s) {
            if (!result.empty() && result.back() == c){
                result.pop_back();
            }
            else {
                result.push_back(c);
            }
        }
        // Return final String
        return result;

        // // Stack Method
        // stack<char> stack;
        // for (int i = 0; i < n; i++) {
        //     if (stack.empty()) {
        //         stack.push(s[i]);
        //         continue;
        //     }
        //     if (stack.top() == s[i]) {
        //         stack.pop();
        //         continue;
        //     }
        //     stack.push(s[i]);
        // }
        // while (!stack.empty()) {
        //     result.push_back(stack.top());
        //     stack.pop();
        // }
        // reverse(result.begin(), result.end());
        // Return final String
        // return result;
    }
};