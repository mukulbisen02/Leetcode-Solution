
class Solution {
public:
    // Custom comparator for Min Heap
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {

            // If frequencies are equal, smaller element gets higher priority
            if (a.first == b.first) {
                return a.second > b.second;
            }

            // Smaller frequency gets higher priority
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        // Step 1: Count frequency of each element
        unordered_map<int, int> freqCount;

        for (int i = 0; i < n; i++) {
            freqCount[nums[i]]++;
        }

        // Step 2: Create a Min Heap of pairs
        // Pair format: {frequency, element}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, cmp> minHeap;

        // Step 3: Maintain only k most frequent elements
        for (auto i : freqCount) {

            int element = i.first;
            int frequency = i.second;

            pair<int, int> curr = {frequency, element};

            // Insert elements until heap contains k elements
            if (minHeap.size() < k) {
                minHeap.push(curr);
                continue;
            }

            // Skip if current frequency is smaller than the
            // minimum frequency present in the heap
            if (curr.first < minHeap.top().first) {
                continue;
            }

            // Remove the least frequent element
            minHeap.pop();

            // Insert the current element
            minHeap.push(curr);
        }

        // Step 4: Extract elements from the heap
        vector<int> result;

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
