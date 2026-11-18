class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int res = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                res = nums[mid];
                right = mid - 1;
            }
        }
        return res;
    }
};