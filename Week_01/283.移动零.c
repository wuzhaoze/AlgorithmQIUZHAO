/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 */

// @lc code=start


void moveZeroes(int* nums, int numsSize){
    if ( nums == NULL || numsSize == 0)
        return;
    int i, j = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != 0) 
            nums[j++] = nums[i];
    }

    for (; j < numsSize; j++) {
        nums[j] = 0;
    }
}
// @lc code=end

