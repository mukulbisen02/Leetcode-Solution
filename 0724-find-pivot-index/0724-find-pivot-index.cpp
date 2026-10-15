class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            //prefix = left
            int leftSum = 0;
            //suffix = right
            int rightSum = 0;

            // Compute left sum for index i
            //prefix sum = (0, i-1)
            for (int j = 0; j < i; j++) {
                leftSum += nums[j];
            }

            // Compute right sum for index i
            //suffix sum = (i+1, n-1)
            for (int k = i + 1; k < n; k++) {
                rightSum += nums[k];
            }

            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};