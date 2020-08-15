/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// @lc code=start


int climbStairs(int n){
    if (n <= 1)
        return 1;
    return climbStairs(n -1) + climbStairs(n -2);
}
// @lc code=end

