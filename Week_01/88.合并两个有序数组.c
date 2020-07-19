/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 */

// @lc code=start


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int s1 = m -1, s2 = n -1, s3 = m + n -1;
    for (; s1 >= 0 && s2 >= 0; )
        nums1[s3--] = nums1[s1] > nums2[s2] ? nums1[s1--] : nums2[s2--];
        
    while (s2 >= 0) 
        nums1[s3--] = nums2[s2--];
}
// @lc code=end

