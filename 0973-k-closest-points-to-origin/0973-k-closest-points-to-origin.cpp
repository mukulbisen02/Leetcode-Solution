class Solution {
public:
    struct cmp {
        bool operator() (vector<int>& a, vector<int>& b) {
            return ((a[0] * a[0]) + (a[1] * a[1])) < ((b[0] * b[0]) + (b[1] * b[1]));
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        priority_queue <vector<int>, vector<vector<int>>, cmp> maxHeap;

        for( auto i : points ){

            if (maxHeap.size() < k){
                maxHeap.push(i);
                continue;
            }

            maxHeap.push(i);

            maxHeap.pop();
        }

        vector<vector<int>> result;

        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return result;
    }
};