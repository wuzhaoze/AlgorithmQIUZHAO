/*
 * @lc app=leetcode.cn id=130 lang=c
 *
 * [130] 被围绕的区域
 */

// @lc code=start

void dfs(char** board, int m, int n, int x, int y) 
{
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
        return;
    board[x][y] = '#';
    dfs(board, m, n, x + 1, y);
    dfs(board, m, n, x - 1, y);
    dfs(board, m, n, x, y + 1);
    dfs(board, m, n, x, y - 1);
}

void solve(char** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize == 0 || boardColSize == NULL || boardColSize[0] == 0)
        return;
    int m = boardSize, n = boardColSize[0];
    for (int i = 0; i < m; i++) {
        dfs(board, m, n, i, 0);
        dfs(board, m, n, i, n-1);

    }
    for (int i = 1; i < n - 1; i++) {
        dfs(board, m, n, 0, i);
        dfs(board, m, n, m-1, i);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '#') 
                board[i][j] = 'O';
            else if (board[i][j] == 'O') 
                board[i][j] = 'X';
        }
    }
    return;
}
// @lc code=end

