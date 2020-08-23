/*
 * @lc app=leetcode.cn id=300 lang=c
 *
 * [300] 最长上升子序列
 */

// @lc code=start


#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
int lengthOfLIS(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0)
        return 0;
    int dp[numsSize];
    for (int i = 0; i < numsSize; i++) 
        dp[i] = 1;

    int max = dp[0];
    for(int i = 1; i < numsSize; i++) {
        for(int j = 0; j < i; j++){
            if (nums[j] < nums[i]) {
                dp[i] = MAX(dp[i], dp[j] + 1);
                max = MAX(dp[i], max);
            }
        }
    }
    return max;

}


// @lc code=end

