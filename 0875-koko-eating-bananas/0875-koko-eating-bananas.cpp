class Solution {
public:
    // Phase 1: Calculate the total hours required at a given eating speed
    long long hoursFun(vector<int>& arr, int speed) {
        long long hours = 0;

        for (int i = 0; i < arr.size(); i++) {
            // Calculate hours required for the current pile (ceiling division)
            hours += arr[i] / speed;

            if (arr[i] % speed != 0) {
                hours++;
            }
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // Phase 2: Initialize the binary search range
        int left = 1; // Minimum possible eating speed
        int right = *max_element(piles.begin(), piles.end()); // Maximum required eating speed

        int minSpeed = -1;

        // Phase 3: Apply binary search on possible eating speeds
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Phase 4: Calculate required hours at the current speed
            long long time = hoursFun(piles, mid);

            if (time > h) {
                // Speed is too slow; search for a higher speed
                left = mid + 1;
            }
            else {
                // Speed is valid; try to find a smaller speed
                minSpeed = mid;
                right = mid - 1;
            }
        }

        // Phase 5: Return the minimum valid eating speed
        return minSpeed;
    }
};