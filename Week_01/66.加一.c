/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){

    for (int i = digitsSize-1; i >= 0; i--) {
        //出现非9，+1 后可以退出
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        //为9 的 +1 变 0
        digits[i] = 0;
    }
    // 到此处则出现，9 ，99， 999 ， 999... 的值
    int* res = (int*) malloc(sizeof(int) * (digitsSize +1 ));
    memset(res, 0, sizeof(int) * (digitsSize +1 ));
    res[0] = 1;
    *returnSize = digitsSize +1;
    return res;
}
// @lc code=end

