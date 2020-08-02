/*
 * @lc app=leetcode.cn id=153 lang=c
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start


int findMin(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) return -1;
    if (numsSize == 1 || nums[numsSize  - 1] > nums[0]) return nums[0];
    int left = 0, right = numsSize - 1, mid = 0;
    while (left < right) {
        mid = ((right-left)>>1) + left;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else {
            right = mid;
        }
    }
    return nums[left];
}


// @lc code=end

