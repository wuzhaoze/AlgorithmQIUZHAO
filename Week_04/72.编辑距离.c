/*
 * @lc app=leetcode.cn id=72 lang=c
 *
 * [72] 编辑距离
 */

// @lc code=start


#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
int minDistance(char * word1, char * word2){
    int m = strlen(word1);
    int n = strlen(word2);
    int **dp = (int**)malloc(sizeof(int*) * (m+1));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*) malloc(sizeof(int) * (n+1));
        memset(dp[i], 0, (n+1) * sizeof(int));
    }

    for (int i = 0; i <= m; i++) 
        dp[i][0] = i;

    for (int i = 0; i <= n; i++) 
        dp[0][i] = i;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];
            else 
                dp[i][j] = MIN(dp[i - 1][j - 1], MIN(dp[i][j - 1], dp[i-1][j])) + 1;
        }
    }
    return dp[m][n];
}


// @lc code=end

