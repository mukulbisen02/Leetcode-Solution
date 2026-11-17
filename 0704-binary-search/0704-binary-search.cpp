class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // int mid = (left + right) / 2;
            int mid = left + (right - left) / 2; // avoid overflow

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) { // so tha target is in right half
                left = mid + 1;
            } else { //(nums[mid] > target)      //so the target is in left half
                right = mid - 1;
            }
        }
        return -1; // when answer is not exist
    }
};