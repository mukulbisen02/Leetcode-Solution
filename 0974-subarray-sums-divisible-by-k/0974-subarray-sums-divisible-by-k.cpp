class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0; // prefix sum of subarray 0 to i
        int count = 0; // no. of subarray
        unordered_map<int, int> remCount; //Hash Map for store Remainder
        remCount[0] = 1; //Initial sum = 0 so {0:1}

        for(int num : nums){
            sum  += num;

            int remainder = (((sum % k) + k) % k); // handle negative prefix sums

            // second way for find remainder
            // int remainder = (sum % k);
            // if (remainder < 0){ // handle negative prefix sums
            //     remainder += k;
            // }

            count += remCount[remainder]; // check remainder in hash map

            remCount[remainder]++; // add remainder into hash map
        }
        return count; // return final no. of subarray
    }
};