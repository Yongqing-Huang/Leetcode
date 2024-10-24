#include<vector>
#include<iostream>

using namespace std;

// TODO: Improve
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m>n) return findMedianSortedArrays(nums2, nums1);

        int size = m + n;
        int half = size/2;

        if (m == 0 || nums1[m-1] <= nums2[0]) {
            if (size % 2 == 1) {
                return nums2[half];
            } else {
                return (double(nums2[half] + nums2[half - 1])) / 2;
            }
        }

        int low = 0;
        int high = m;

        while (low <= high){
            int a = (low+high) / 2;
            int b = half - a;
            
            int nums1_low = (a==0)? INT_MIN : nums1[a-1];
            int nums1_high = (a==m)? INT_MAX : nums1[a];
            int nums2_low = (b==0)? INT_MIN : nums2[b-1];
            int nums2_high = (b==n)? INT_MAX : nums2[b];

            if (nums1_low <= nums2_high && nums2_low <= nums1_high){
                if (size%2){
                    return max(nums1_low, nums2_low);
                }
                return (max(nums1_low, nums2_low) + min(nums1_high, nums2_high))/2;
            }

            if (nums1_low > nums2_high) {
                high = a - 1;
            }
            else {
                low = a + 1;
            }
        }

        return 0.0;
    }
};