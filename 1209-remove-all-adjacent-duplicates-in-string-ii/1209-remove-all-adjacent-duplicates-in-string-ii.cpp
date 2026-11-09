class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;

        for (char c : s) {
            if (stk.empty() || stk.top().first != c) {
                stk.push({c, 1});
            } else {
                stk.top().second++;
            }

            if (!stk.empty() && stk.top().second == k) {
                stk.pop();
            }
        }

        string answer;

        while (!stk.empty()) {
            pair<char, int> p = stk.top();
            stk.pop();

            while (p.second--) {
                answer.push_back(p.first);
            }
        }

        reverse(answer.begin(), answer.end());

        // while (!stk.empty()) {
        //     auto [ch, count] = stk.top();
        //     stk.pop();

        //     answer.append(count, ch);
        // }
        // reverse(answer.begin(), answer.end());

        return answer;
    }
};