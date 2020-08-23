/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 */

// @lc code=start


// int numDecodings(char * s){
//     int len = strlen(s);
//     if (len == 0 || s[0] == '0')
//         return 0;
//     int dp[len];
//     memset(dp, 0, len * sizeof(int));
//     dp[0] = 1;
//     for (int i = 1; i < len; i++) {
//         if ( s[i] != '0')
//             dp[i] = dp[i-1];
        
//         int num = 10 * (s[i-1] - '0') + s[i] - '0';
//         if (num >= 10 && num <= 26)
//         {
//             if (i == 1) {
//                 dp[i]++;
//             } else {
//                 dp[i] += dp[i-2];
//             }
//         }
//     }
//     return dp[len-1];
// }
int numDecodings(char * s){
    int len = strlen(s);
    if (len == 0 || s[0] == '0')
        return 0;
    int dp[len + 1];
    memset(dp, 0, (len+1) * sizeof(int));
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i < len; i++) {
        if (s[i] != '0')
            dp[i+1] = dp[i];
        int num = (s[i-1] - '0' ) * 10 + s[i] - '0';
        if (num >= 10 && num <= 26)
            dp[i+1] += dp[i-1];
    }
    return dp[len];
}

// @lc code=end

