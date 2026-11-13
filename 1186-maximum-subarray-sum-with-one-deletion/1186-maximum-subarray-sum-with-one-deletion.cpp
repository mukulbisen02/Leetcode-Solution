
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = 0;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int v1 = oneDelete + arr[i];
            oneDelete = max(noDelete, v1);

            int v2 = noDelete + arr[i];
            noDelete = max(arr[i], v2);

            ans = max(ans, max(noDelete, oneDelete));
        }

        return ans;
    }
};