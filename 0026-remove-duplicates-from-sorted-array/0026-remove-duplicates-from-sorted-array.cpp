class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int result = 1;

        while (right < nums.size()) {
            if (nums[left] != nums[right]) {
                nums[left + 1] = nums[right];
                left++;
                result++;
            }
            right++;
        }
        return result;
    }
};