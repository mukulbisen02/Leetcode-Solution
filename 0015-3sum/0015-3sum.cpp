class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < n - 2; i++) {

            // No three positive numbers can sum to zero
            if (nums[i] > 0)
                break;

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            while (left < right) {

                int sum = nums[left] + nums[right];

                if (sum == target) {

                    result.push_back({nums[i], nums[left], nums[right]});


                    // // Skip duplicate left values
                    // left++;
                    // while (left < right && nums[left] == nums[left - 1]) {
                    //     left++;
                    // }
                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left - 1]);

                    // // Skip duplicate right values
                    // right--;
                    // while (left < right && nums[right] == nums[right + 1]) {
                    //     right--;
                    // }
                    do {
                        right--;
                    } while (left < right && nums[right] == nums[right + 1]);

                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};