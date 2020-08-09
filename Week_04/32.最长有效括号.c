/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */

// @lc code=start


int longestValidParentheses(char * s){
    if (s == NULL)
        return 0;
    int len = strlen(s);
    if (len == 0 || len == 1)
        return 0;
    int dp[len];
    memset(dp, 0, len * sizeof(int));
    int max  = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && s[i] == ')') {
            if (s[i-1] == '(')
                dp[i] = (i >= 2 ? dp[i-2] + 2 : 2);
            else if (s[i-1] == ')' && i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] -1] == '(') 
                dp[i] = dp[i-1] + 2 + (i - dp[i-1] -2 >= 0 ? dp[i - dp[i-1] -2] : 0);
        }
        max = max > dp[i] ? max : dp[i];
    }
    return max;
}


// @lc code=end

