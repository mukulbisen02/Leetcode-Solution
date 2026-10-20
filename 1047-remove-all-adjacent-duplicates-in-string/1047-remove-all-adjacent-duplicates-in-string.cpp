class Solution {
public:
    string removeDuplicates(string s) {
        string result;

        // Normal String Method
        // for (char c : s) {
        //     if (!result.empty() && result.back() == c){
        //         result.pop_back();
        //     }
        //     else {
        //         result.push_back(c);
        //     }
        // }
        // Return final String
        // return result;

        // Stack Method
        int n = s.size();
        stack<char> stack;
        for (char c : s) {
            if (!stack.empty() && stack.top() == c) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        while (!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }
        reverse(result.begin(), result.end());

        // Return final String
        return result;
    }
};