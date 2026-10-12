class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            //when cycle prasent
            if(slow == fast){

                //update slow
                slow = 0;

                //for staring node of cycle
                while (slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
    }
};