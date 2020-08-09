/*
 * @lc app=leetcode.cn id=221 lang=c
 *
 * [221] 最大正方形
 */

// @lc code=start

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL || matrixColSize[0] == 0)
        return 0;
    int m = matrixSize, n = matrixColSize[0];
    int dp[m][n];
    //memset(dp, 0, sizeof(int) * m * n);
    int max = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) 
                    dp[i][j] = 1;
                else 
                    dp[i][j] = MIN(dp[i-1][j-1], MIN(dp[i-1][j], dp[i][j-1])) + 1;
                max = max > dp[i][j] ? max : dp[i][j];
            } else 
                dp[i][j] = 0;
            
        }
    }
    return max * max;
}
// @lc code=end

