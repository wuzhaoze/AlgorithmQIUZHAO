/*
 * @lc app=leetcode.cn id=74 lang=c
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrix == NULL || matrixSize == 0 || (*matrixColSize) == 0) return false;
    long left = 0, right = matrixSize * (*matrixColSize) - 1, mid = 0;
    while (left <= right) {
        mid = ((right - left)>>1) + left;
        if (matrix[mid/(*matrixColSize)][mid%(*matrixColSize)] == target) 
            return true;
        if (matrix[mid/(*matrixColSize)][mid%(*matrixColSize)] < target) 
            left = mid + 1;
        else 
            right = mid -1;
    }
    return false;
}


// @lc code=end

