
class Solution {
public:
    // Custom comparator for Max Heap
    struct cmp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {

            // If frequencies are equal, compare characters
            if (a.first == b.first) {
                return a.second < b.second;
            }

            // Higher frequency gets higher priority
            return a.first < b.first;
        }
    };

    string reorganizeString(string s) {

        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Create Max Heap
        // Pair format: {frequency, character}
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> maxHeap;

        for (auto i : freq) {
            char letter = i.first;
            int frequency = i.second;

            maxHeap.push({frequency, letter});
        }

        string res;

        // Step 3: Reorganize the string
        while (!maxHeap.empty()) {

            // Get the most frequent character
            pair<int, char> p1 = maxHeap.top();
            maxHeap.pop();

            // Check whether the character can be placed
            if (res.empty() || res.back() != p1.second) {

                res.push_back(p1.second);
                p1.first--;

                // Insert back if frequency remains
                if (p1.first > 0) {
                    maxHeap.push(p1);
                }
            } else {

                // No other character is available
                if (maxHeap.empty()) {
                    return "";
                }

                // Take the second most frequent character
                pair<int, char> p2 = maxHeap.top();
                maxHeap.pop();

                res.push_back(p2.second);
                p2.first--;

                // Insert back if frequency remains
                if (p2.first > 0) {
                    maxHeap.push(p2);
                }

                // Put the first character back
                maxHeap.push(p1);
            }
        }

        return res;
    }
};
