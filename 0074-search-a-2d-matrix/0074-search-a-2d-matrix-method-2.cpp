class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Handle an empty matrix
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        // Phase 1: First binary search → Find the possible row
        int low = 0;
        int high = matrix.size() - 1;

        int row = -1;

        while (low <= high) {
            int guess = low + (high - low) / 2;

            if (matrix[guess][0] <= target) {
                row = guess;
                low = guess + 1;
            }
            else {
                high = guess - 1;
            }
        }

        // Target is smaller than the first element
        if (row == -1) {
            return false;
        }

        // Phase 2: Second binary search → Find the target inside that selected row
        int left = 0;
        int right = matrix[0].size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[row][mid] == target) {
                return true;
            }
            else if (matrix[row][mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};
