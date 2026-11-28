class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        int n = courses.size();

        // Step 1: Sort courses by deadline (ascending order)
        sort(courses.begin(), courses.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            }
        );

        // Step 2: Max Heap stores durations of selected courses
        priority_queue<int> maxHeap;

        int totalTime = 0;

        // Step 3: Process each course
        for (int i = 0; i < n; i++) {

            // Select the current course
            totalTime += courses[i][0];
            maxHeap.push(courses[i][0]);

            // Step 4: If deadline is exceeded, remove
            // the course with the maximum duration
            if (totalTime > courses[i][1]) {

                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }

        // Step 5: Number of selected courses
        return maxHeap.size();
    }
};
