class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int half = nums.size() / 2;
        unordered_map<int, int> count;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;

            if (count[nums[i]] > half) {
                return nums[i];
            }
        }
        return -1;
    }
};