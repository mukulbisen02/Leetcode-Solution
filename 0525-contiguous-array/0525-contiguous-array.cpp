class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zeroCount = 0;
        int oneCount = 0;
        int maxLen = 0;

        unordered_map<int, int> diffIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                zeroCount++;
            else
                oneCount++;

            int diff = zeroCount - oneCount;

            if (diff == 0) {
                maxLen = max(maxLen, i + 1);
                continue;
            }

            if (diffIndex.count(diff)) {
                int len = i - diffIndex[diff];
                maxLen = max(maxLen, len);
            } else 
                diffIndex[diff] = i;
            
        }
        return maxLen;
    }
};