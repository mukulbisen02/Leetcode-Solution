class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnd = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int v1 = nums[i];
            int v2 = bestEnd + nums[i];

            // update
            bestEnd = max(v1, v2);
            maxSum = max(maxSum, bestEnd);
        }
        return maxSum;
    }
};