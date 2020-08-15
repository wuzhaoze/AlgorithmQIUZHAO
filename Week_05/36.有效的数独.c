/*
 * @lc app=leetcode.cn id=36 lang=c
 *
 * [36] 有效的数独
 */

// @lc code=start


bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize == 0 || boardColSize == NULL || boardColSize[0] == 0)
        return false;
    
    int check[3][9][10] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++){
            if (board[i][j] != '.') {
                int number = (int)(board[i][j] - '0');
                int chunk = i / 3 * 3 + j / 3;
                if (check[0][i][number] == 1 || check[1][j][number] == 1 || check[2][chunk][number] == 1)
                    return false;
                check[0][i][number] = 1;
                check[1][j][number] = 1;
                check[2][chunk][number] = 1;

            }
            
        }
    }
    return true;
}


// @lc code=end

