/*
 * @lc app=leetcode.cn id=529 lang=c
 *
 * [529] 扫雷游戏
 */

// @lc code=start

int judge(int x, int y, char**board, int m, int n)
{
    int sum = 0;

    if (x - 1 >= 0) {
        if (board[x-1][y] == 'M')
            sum++;
        if (y - 1 >= 0 && board[x-1][y-1] == 'M' )
            sum++;
        if (y + 1 < n && board[x-1][y+1] == 'M')
            sum++;
    }
    if (x + 1 < m) {
        if (board[x+1][y] == 'M')
            sum++;
        if (y - 1 >= 0 && board[x+1][y-1] == 'M')
            sum++;
        if (y + 1 < n && board[x+1][y+1] == 'M')
            sum++;
    }
    
    if (y - 1 >= 0 && board[x][y-1] == 'M')
        sum++;
    if (y + 1 < n && board[x][y+1] == 'M')
        sum++;
    return sum;
}

void dfs(int x, int y, char**board, int m, int n)
{
    int fi = 0;

    fi = judge(x,y,board,m,n);
    if (fi > 0){
        board[x][y] = fi + '0';
    } else {
        board[x][y] = 'B';
        if (x + 1 < m) {
            if (board[x+1][y] == 'E')
                dfs(x+1, y, board, m, n);
            if (y - 1 >= 0 && board[x+1][y-1] == 'E')
                dfs(x+1, y-1, board, m, n);
            if (y + 1 < n && board[x+1][y+1] == 'E')
                dfs(x+1, y+1, board, m, n);
        }
        if (x - 1 >= 0) {
            if (board[x-1][y] == 'E')
                dfs(x-1, y, board, m, n);
            if (y - 1 >= 0 && board[x-1][y-1] == 'E')
                dfs(x-1, y-1, board, m, n);
            if (y + 1 < n && board[x-1][y+1] == 'E')
                dfs(x-1, y+1, board, m, n);
        }
        if (y + 1 < n && board[x][y+1] == 'E')
            dfs(x, y+1, board, m, n);
        if (y - 1>= 0 && board[x][y-1] == 'E' )
            dfs(x, y-1, board, m, n);
        
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    *returnSize = boardSize;
    *returnColumnSizes = boardColSize;
    if(board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
    }
    dfs(click[0], click[1], board, boardSize, boardColSize[0]);
    return board;
}


// @lc code=end

