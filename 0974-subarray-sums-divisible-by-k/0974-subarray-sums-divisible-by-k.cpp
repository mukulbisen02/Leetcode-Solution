class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0; // prefix sum of subarray 0 to i
        int count = 0; // no. of subarray
        unordered_map<int, int> remCount; //Hash Map for store Remender
        remCount[0] = 1; //Initial sum = 0 so {0:1}

        for(int num : nums){
            sum  += num;
            int remender = (((sum % k) + k) % k); // handle negative prefix sums

            count += remCount[remender]; // check remender in hash map

            remCount[remender]++; // add remender into hash map
        }
        return count; // return final no. of subarray
    }
};