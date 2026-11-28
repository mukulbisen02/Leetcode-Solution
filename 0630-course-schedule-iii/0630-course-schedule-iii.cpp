class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

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
        for (int i = 0; i < courses.size(); i++) {

            int duration = courses[i][0];
            int deadline = courses[i][1];

            // Select the current course
            totalTime += duration;
            maxHeap.push(duration);

            // Step 4: If deadline is exceeded, remove
            // the course with the maximum duration
            if (totalTime > deadline) {

                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }

        // Step 5: Number of selected courses
        return maxHeap.size();
    }
};
