class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, -1);

        stack<int> stk;

        for (int i = n - 2; i >= 0; i--) {
            stk.push(nums[i]);
        }

        for (int j = n - 1; j >= 0; j--) {
            while (!stk.empty() && stk.top() <= nums[j]) {
                stk.pop();
            }

            if (!stk.empty()) {
                answer[j] = stk.top();
            }

            stk.push(nums[j]);
        }
        return answer;
    }
};