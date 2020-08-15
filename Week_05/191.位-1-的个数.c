/*
 * @lc app=leetcode.cn id=191 lang=c
 *
 * [191] 位1的个数
 */

// @lc code=start
int hammingWeight(uint32_t n) {
    int cnt = 0;
    while(n) {
        // cnt++;
        // n &= n-1;
        cnt += n & 1;
        n = n >> 1;
    }
    return cnt;
}
// @lc code=end

