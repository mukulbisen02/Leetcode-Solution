class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> stk;

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                answer[i] = stk.top() - i;
            }

            stk.push(i);
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (temperatures[j] > temperatures[i]) {
        //             answer[i] = j - i;
        //             break;
        //         }
        //     }
        // }
        return answer;
    }
};