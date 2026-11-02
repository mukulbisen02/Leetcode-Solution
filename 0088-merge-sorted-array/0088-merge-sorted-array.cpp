class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;     // Pointer to end of valid nums1
        int j = n - 1;     // Pointer to end of nums2
        int k = m + n - 1; // Pointer to end of nums1 (write position)

        // Merge from the back, placing the larger element first
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Copy remaining elements from nums2 (if any)
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }

    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     while((m-1)>=0 && (n-1)>=0){
    //         if(nums1[m-1] >= nums2[n-1]){
    //             nums1[m+n-1] = nums1[m-1];
    //             m--;
    //         } else {
    //             nums1[m+n-1] = nums2[n-1];
    //             n--;
    //         }
    //     }
    //     while((n-1) >= 0){
    //         nums1[m+n-1] = nums2[n-1];
    //         n--;
    //     }
    // }
};
