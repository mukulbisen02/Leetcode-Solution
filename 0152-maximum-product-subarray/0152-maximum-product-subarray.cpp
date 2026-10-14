class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = nums[0];
        int minEnd = nums[0];
        int maxEnd = nums[0];

        for (int i = 1; i < nums.size(); i++){
            int v1 = nums[i];
            int v2 = minEnd * nums[i];
            int v3 = maxEnd * nums[i];

            //update
            minEnd = min(v1, min(v2, v3));
            maxEnd = max(v1, max(v2, v3));

            maxPro = max(maxPro, max(minEnd, maxEnd));
        }

        return maxPro;
    }
};