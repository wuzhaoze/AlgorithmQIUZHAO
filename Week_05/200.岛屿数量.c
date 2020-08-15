/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start

void dfs(char **grid, int row, int col, int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1')
        return;

    grid[i][j] = '0';
    dfs(grid, row, col, i + 1, j);
    dfs(grid, row, col, i - 1, j);
    dfs(grid, row, col, i, j + 1);
    dfs(grid, row, col, i, j - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || gridColSize == NULL || gridColSize[0] == 0)
        return 0;
    int ret = 0, col = gridColSize[0];

    for (int i = 0; i < gridSize; i++) {
        for (int j =  0; j < col; j++) {
            if (grid[i][j] == '1') {
                ret++;
                dfs(grid, gridSize, col, i, j);
            }
        }
    }
    return ret;
}
// @lc code=end

