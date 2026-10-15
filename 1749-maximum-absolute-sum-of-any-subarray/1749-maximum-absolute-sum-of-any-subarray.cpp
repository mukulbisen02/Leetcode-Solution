class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minEnd = 0;
        int maxEnd = 0;
        int minSum = nums[0];
        int maxSum = nums[0];

        //Approach 1:
        for (int i = 0; i < nums.size(); i++) {
            // find Maximum Sum
            int v1 = maxEnd + nums[i];
            maxEnd = max(v1, nums[i]);
            maxSum = max(maxSum, maxEnd);

            // find Minimum Sum
            int v2 = minEnd + nums[i];
            minEnd = min(v2, nums[i]);
            minSum = min(minSum, minEnd);
        }

        //Approach 2:
        // for (int num : nums) {
        //     maxEnd = max(num, maxEnd + num);
        //     maxSum = max(maxSum, maxEnd);

        //     minEnd = min(num, minEnd + num);
        //     minSum = min(minSum, minEnd);
        // }

        // maximum Result
        return max(maxSum, abs(minSum));
    }
};