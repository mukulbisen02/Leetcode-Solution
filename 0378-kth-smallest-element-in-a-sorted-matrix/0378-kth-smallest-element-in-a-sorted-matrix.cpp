
class Solution {
public:

    // Count elements smaller than or equal to guess
    int countFun(vector<vector<int>>& mat, int n, int guess) {

        int row = 0;
        int col = n - 1;

        long long count = 0;

        // Start from top-right corner
        while (row < n && col >= 0) {

            int idx = mat[row][col];

            if (idx <= guess) {

                // All elements to the left in this row are also <= guess
                count += col + 1;
                row++; // Move down
            }
            else {

                // Current element is greater than guess
                col--; // Move left
            }
        }

        return (int)count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        // Handle empty matrix or invalid k
        if (n == 0 || k < 1 || k > 1LL * n * n) {
            return -1;
        }

        // Minimum and maximum possible answers
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        int result = -1;

        // Binary Search on Answer
        while (low <= high) {

            int guess = low + (high - low) / 2;

            // Count elements <= guess
            int count = countFun(matrix, n, guess);

            if (count < k) {

                // Not enough elements
                // Search in the right half
                low = guess + 1;
            }
            else {

                // Possible answer found
                result = guess;

                // Search for a smaller possible answer
                high = guess - 1;
            }
        }

        return result;
    }
};
