
class Solution {
public:
    // Count elements smaller than or equal to guess
    int countFun(int m, int n, int guess) {

        int row = 1;
        int col = n;

        long long count = 0;

        // Start from top-right corner
        while (row <= m && col > 0) {

            int idx = row * col;

            if (idx <= guess) {

                // All elements to the left in this row are also <= guess
                count += col;

                row++; // Move down
            } else {

                // Current element is greater than guess
                col--; // Move left
            }
        }

        return (int)count;
    }

    int findKthNumber(int m, int n, int k) {

        // Minimum and maximum possible answers
        long long low = 1;
        long long high = 1LL * m * n;

        long long result = -1;

        // Binary Search on Answer
        while (low <= high) {

            long long guess = low + (high - low) / 2;

            // Count elements <= guess
            int count = countFun(m, n, (int)guess);

            if (count < k) {

                // Not enough elements
                // Search in the right half
                low = guess + 1;
            } else {

                // Possible answer found
                result = guess;

                // Search for a smaller possible answer
                high = guess - 1;
            }
        }

        return (int)result;
    }
};
