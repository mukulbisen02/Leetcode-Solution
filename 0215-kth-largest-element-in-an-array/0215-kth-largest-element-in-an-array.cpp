
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();

        // Phase 1: Create a Min Heap
        // It will maintain the largest k elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Phase 2: Insert the first k elements into the heap
        for (int i = 0; i < k; i++) {
            minHeap.push(nums[i]);
        }

        // Phase 3: Process the remaining elements
        for (int i = k; i < n; i++) {

            // Insert the current larger element
            minHeap.push(nums[i]);
            // Remove the smallest element
            minHeap.pop();

        }

        // Phase 4: The heap top is the kth largest element
        return minHeap.top();
    }
};
