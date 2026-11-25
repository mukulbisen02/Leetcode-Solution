class Solution {
public:
    // Custom comparator for Max Heap
    struct cmp {
        bool operator()(vector<int>& a, vector<int>& b) {

            // Compare squared distances from origin
            return ((a[0] * a[0]) + (a[1] * a[1])) <
                   ((b[0] * b[0]) + (b[1] * b[1]));
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n = points.size();

        // Max Heap based on squared distance
        priority_queue<vector<int>, vector<vector<int>>, cmp> maxHeap;

        for (int i = 0; i < n; i++) {

            // Insert current point into the heap
            maxHeap.push(points[i]);

            // If heap size exceeds k, remove farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
            
            // or
            // if (maxHeap.size() < k) {
            //     maxHeap.push(i);
            //     continue;
            // }

            // maxHeap.push(i);
            // maxHeap.pop();
        }

        // Store the k closest points
        vector<vector<int>> result;

        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return result;
    }
};