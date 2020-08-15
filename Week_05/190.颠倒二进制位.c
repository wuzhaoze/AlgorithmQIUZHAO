/*
 * @lc app=leetcode.cn id=190 lang=c
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
uint32_t reverseBits(uint32_t n) {
    uint64_t mask = 1;
    uint32_t ret = 0;
    for (int i = 0; i < 32; i++) {
        if (n & mask )
            ret |= ((uint64_t)1 << (31-i));
        mask <<= 1;
    }
    return ret;
}
// @lc code=end

