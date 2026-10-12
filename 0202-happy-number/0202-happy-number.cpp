class Solution {
private:
    int digitSquareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (fast != 1) {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));

            if (slow == fast && slow != 1) {
                return false;
            }
        }
        return true;
    }
};