class Solution {
public:
    // Phase 1: Find the index of the minimum element (pivot)
    int minFun(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int res = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] > nums[n - 1]) {
                l = m + 1;
            } else {
                res = m;
                r = m - 1;
            }
        }
        return res;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // Phase 2: Find the pivot index
        int idx = minFun(nums);

        // Phase 3: Decide which sorted half may contain the target
        if (idx > 0 && nums[0] <= target && target <= nums[idx - 1]) {

            // Phase 4: Binary search in the left sorted half
            int l1 = 0;
            int r1 = idx - 1;

            while (l1 <= r1) {
                int m1 = l1 + (r1 - l1) / 2;

                if (nums[m1] == target) {
                    return m1;
                } else if (nums[m1] < target) {
                    l1 = m1 + 1;
                } else {
                    r1 = m1 - 1;
                }
            }
        } else {
            // Phase 5: Binary search in the right sorted half
            int l2 = idx;
            int r2 = n - 1;

            while (l2 <= r2) {
                int m2 = l2 + (r2 - l2) / 2;

                if (nums[m2] == target) {
                    return m2;
                } else if (nums[m2] < target) {
                    l2 = m2 + 1;
                } else {
                    r2 = m2 - 1;
                }
            }
        }

        // Phase 6: Target not found
        return -1;
    }
};