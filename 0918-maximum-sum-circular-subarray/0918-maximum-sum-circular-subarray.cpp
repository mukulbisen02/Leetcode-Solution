class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxEnd = 0, minEnd = 0;
        int maxSum = nums[0], minSum = nums[0];

        for (int i = 0; i < nums.size(); i++){
            maxEnd = max(maxEnd + nums[i], nums[i]);
            maxSum = max(maxSum, maxEnd);

            minEnd = min(minEnd + nums[i], nums[i]);
            minSum = min(minSum, minEnd);

            total += nums[i];
        }

        if (maxSum < 0)
            return maxSum;
        
        int ans = max(maxSum, total - minSum);
        return ans;
    }
};