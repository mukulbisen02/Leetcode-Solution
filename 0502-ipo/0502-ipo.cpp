class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();

        // Step 1: Store projects as {required capital, profit}
        vector<pair<int, int>> project;

        for (int i = 0; i < n; i++) {
            project.push_back({capital[i], profits[i]});
        }

        // Step 2: Sort projects by required capital
        sort(project.begin(), project.end());

        // Step 3: Max Heap stores profits of affordable projects
        priority_queue<int> maxHeap;

        int idx = 0;

        // Step 4: Select at most k projects
        while (k--) {

            // Add all currently affordable projects
            while (idx < n && project[idx].first <= w) {
                maxHeap.push(project[idx].second);
                idx++;
            }

            // No project is currently affordable
            if (maxHeap.empty()) {
                return w;
            }

            // Select the project with maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;

        //or
        // Step 4: Select at most k projects
        // for (int round = 0; round < k; round++) {
        //     // Push all newly affordable projects into the heap
        //     while (idx < n && projects[idx].first <= w) {
        //         maxHeap.push(projects[idx].second);
        //         idx++;
        //     }

        //     if (maxHeap.empty()) break; // No affordable project
        //     w += maxHeap.top();
        //     maxHeap.pop();
        // }
        // return w;
    }
};