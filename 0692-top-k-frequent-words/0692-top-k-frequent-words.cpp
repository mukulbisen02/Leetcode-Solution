
class Solution {
public:
    // Custom comparator for Min Heap
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {

            // If frequencies are equal,
            // lexicographically larger word gets higher priority
            if (a.first == b.first) {
                return a.second < b.second;
            }

            // Smaller frequency gets higher priority
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        int n = words.size();

        // Step 1: Count frequency of each word
        unordered_map<string, int> freqCount;

        for (int i = 0; i < n; i++) {
            freqCount[words[i]]++;
        }

        // Step 2: Create a Min Heap
        // Pair format: {frequency, word}
        priority_queue<pair<int, string>,
                       vector<pair<int, string>>, cmp> minHeap;

        // Step 3: Maintain only k most frequent words
        for (auto i : freqCount) {

            string word = i.first;
            int frequency = i.second;

            pair<int, string> curr = {frequency, word};

            // Insert until heap contains k elements
            if (minHeap.size() < k) {
                minHeap.push(curr);
                continue;
            }

            // Skip if current word is less desirable
            if (curr.first < minHeap.top().first ||
                (curr.first == minHeap.top().first &&
                 curr.second > minHeap.top().second)) {
                continue;
            }

            // Remove the least desirable word
            minHeap.pop();

            // Insert current word
            minHeap.push(curr);
        }

        // Step 4: Extract words from heap
        vector<string> result;

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // Min Heap extraction gives reverse of required order
        reverse(result.begin(), result.end());

        return result;
    }
};
