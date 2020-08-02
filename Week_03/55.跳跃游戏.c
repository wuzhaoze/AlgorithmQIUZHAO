/*
 * @lc app=leetcode.cn id=55 lang=c
 *
 * [55] 跳跃游戏
 */

// @lc code=start

#define MAX(X,Y) ((X)>(Y) ? (X) : (Y))
bool canJump(int* nums, int numsSize){
    int k = 0;
    for(int i = 0; i < numsSize ; i++) {
        if (i > k) return false;
        k = MAX(k, i + nums[i]);
        if (k >= numsSize)
            return true;
    }
    return true;
}
// @lc code=end

