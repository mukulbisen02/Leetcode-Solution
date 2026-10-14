
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int maxSum = arr[0];
        int oneDelete = INT_MIN;

        for (int i = 1; i < arr.size(); i++) {
            int prev_noDelete = noDelete;

            int v1 = arr[i];
            int v2 = noDelete + arr[i];

            // No deletion
            noDelete = max(v1, v2);

            int v3;
            if (oneDelete == INT_MIN) {
                v3 = arr[i];
            } else {
                v3 = oneDelete + arr[i];
            }

            // One deletion allowed
            oneDelete = max(v3, prev_noDelete);

            maxSum = max(maxSum, max(noDelete, oneDelete));
        }

        return maxSum;
    }
};