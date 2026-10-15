class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = 0;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            //Approach 1:
            // int v1 = oneDelete + arr[i];
            // oneDelete = max(noDelete, v1);

            // int v2 = noDelete + arr[i];
            // noDelete = max(arr[i], v2);

            //Approach 2:
            int prev_nodelete = noDelete;

            int v1 = noDelete + arr[i];
            int v2 = oneDelete + arr[i];

            noDelete = max(v1, arr[i]);
            oneDelete = max(v2, prev_nodelete);

            //Final Answer
            ans = max(ans, max(noDelete, oneDelete));
        }

        return ans;
    }
};