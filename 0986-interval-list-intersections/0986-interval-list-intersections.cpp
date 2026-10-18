class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0;
        int j = 0;
        int m = firstList.size();
        int n = secondList.size();

        while (i < m && j < n) {
            int st1 = firstList[i][0];
            int end1 = firstList[i][1];

            int st2 = secondList[j][0];
            int end2 = secondList[j][1];

            // Method 1: to find Intersection point
            if (st1 <= st2) {
                if (end1 >= st2) {
                    int s = max(st1, st2);
                    int e = min(end1, end2);
                    result.push_back({s, e});
                }
            } else {
                if (end2 >= st1) {
                    int s = max(st1, st2);
                    int e = min(end1, end2);
                    result.push_back({s, e});
                }
            }

            // Method 1: to find Intersection point
            // int start = max(st1, st2);
            // int end = min(end1, end2);

            // if (start <= end) {
            //     result.push_back({start, end});
            // }
            
            // Update i and j
            if (end1 <= end2)
                i++;
            else
                j++;
        }
        return result;
    }
};
