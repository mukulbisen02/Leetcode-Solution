class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnd = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++){
            bestEnd = max( nums[i], bestEnd + nums[i] );
            maxSum = max(maxSum, bestEnd);
        }
        return maxSum;
    }
};