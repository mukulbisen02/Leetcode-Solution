class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         
        // Handle an empty matrix
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        // // start at top-right corner:-
        // int row = 0;
        // int col = n - 1;

        // while (row < m && col >= 0) {
        //     int corner = matrix[row][col];

        //     if (corner == target) {
        //         return true;
        //     } else if (corner > target) {
        //         col--;
        //     } else {
        //         row++;
        //     }
        // }
        // // when target is not found
        // return false;


        // start at bottom-left corner:-
        int row = m - 1;
        int col = 0;

        while (row >= 0 && col < n) {
            int corner = matrix[row][col];

            if (corner == target) {
                return true;
            } else if (corner > target) {
                row--;
            } else {
                col++;
            }
        }
        // when target is not found
        return false;

    }
};