class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Phase 1: Initialize the binary search boundaries
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        // Phase 2: Perform binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Phase 3: Check if the middle element is the target
            if (nums[mid] == target) {
                return mid;
            }

            // Phase 4: Identify whether mid belongs to the left (larger) portion of the rotated array
            if (nums[mid] > nums[n - 1]) {

                // Phase 5: Search in the right portion if target is greater than the middle element
                if (nums[mid] < target) {
                    left = mid + 1;
                }
                else {
                    // Phase 6: Decide which side may contain the target
                    if (nums[0] > target) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
            }
            else {
                // Phase 7: mid belongs to the right (smaller) portion of the rotated array

                // Phase 8: Search in the left portion if target is smaller than the middle element
                if (nums[mid] > target) {
                    right = mid - 1;
                }
                else {
                    // Phase 9: Decide which side may contain the target
                    if (nums[n - 1] < target) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
            }
        }

        // Phase 10: Target is not present in the array
        return -1;
    }
};