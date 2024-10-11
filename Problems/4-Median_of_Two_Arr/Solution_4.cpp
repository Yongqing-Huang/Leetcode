#include<vector>
#include<iostream>

using namespace std;

// TODO: Improve
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        
        int size = nums1.size();
        if (size%2){
            return nums1[size/2];
        }
        return (double(nums1[size/2]+nums1[size/2-1]))/2;
    }
};