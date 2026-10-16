class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Method 1-
        int count = 0;
        int sum = 0;
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        for (int num : nums) {
            sum += num;

            if (sumCount.count(sum - k)) {
                count += sumCount[sum - k];
            }
            sumCount[sum]++;
        }
        // Final Result
        return count;

        // Method 2-
        //  int count = 0;
        //  for (int i = 0; i < nums.size(); i++){
        //      int sum = 0;
        //      for (int j = i; j < nums.size(); j++){
        //          sum += nums[j];
        //          if (sum == k){
        //              count++;
        //          }
        //      }
        //  }
        //  return count;

        // Method 3-
        //  int count = 0;
        //  int sum = 0;
        //  for(int i = 0; i < nums.size(); i++){
        //      sum += nums[i];
        //      int check = sum - k;
        //      int freq = sumCount[check];
        //      count += freq;
        //      sumCount[sum]++;
        //  }
        //  return count;
    }
};