class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int i : stones) {
            maxHeap.push(i);
        }

        if (maxHeap.size() == 1) {
            return maxHeap.top();
        } else {
            while (maxHeap.size() > 1) {
                int y = maxHeap.top();
                maxHeap.pop();

                int x = maxHeap.top();
                maxHeap.pop();

                if (x == y) {
                    x = 0;
                    y = 0;
                } else {
                    y = y - x;
                    x = 0;

                    maxHeap.push(y);
                }
            }
        }

        if (maxHeap.empty()) {
            return 0;
        }

        return maxHeap.top();
    }
};