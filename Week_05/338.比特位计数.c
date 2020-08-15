/*
 * @lc app=leetcode.cn id=338 lang=c
 *
 * [338] 比特位计数
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    *returnSize = num + 1;
    int* dp = (int*)malloc(sizeof(int) * (num + 1));
    dp[0] = 0;
    for (int i = 1; i <= num; i++){
        if (i & 1)
            dp[i] = dp[i-1] + 1;
        else 
            dp[i] = dp[i>>1];
    }
    return dp;
}


// @lc code=end

