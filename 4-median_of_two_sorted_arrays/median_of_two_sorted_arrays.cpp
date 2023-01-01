/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int s1 = nums1.size(), s2 = nums2.size();
        if(s1 > s2) findMedianSortedArrays(nums2, nums1);  // s1 is the little one
        int left = 0, right = s1 - 1;
        int mid = (right-left+1) / 2;  // middle of the little array
        int left2 = 0, right2 = s1 + s2 - mid - 1;
        
        while (true)
        {
            if(nums1[mid] < nums2[right2 + 1])
        }
        
    }
};