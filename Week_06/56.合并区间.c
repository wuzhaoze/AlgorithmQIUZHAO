/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 */

// @lc code=start

int cmp(const void **a, const void **b){
    return ((int**)a)[0][0] - ((int**)b)[0][0];
}

int max(int x, int y)
{
    return x > y ? x : y;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (intervals == NULL || intervalsSize == 0)
        return NULL;
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);

    for(int i = 0; i < intervalsSize - 1; i++) {
        if (intervals[i][1] >= intervals[i + 1][0]) {
            intervals[i + 1][0] = intervals[i][0];
            intervals[i + 1][1] = max(intervals[i][1], intervals[i+1][1]);
            intervals[i][0] = 0;
            intervals[i][1] = -1;
        }
    }
    int **res = (int**)malloc(sizeof(int*) * intervalsSize);

    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i][0] == 0 && intervals[i][1] == -1) continue;
        res[*returnSize] = (int*)malloc(sizeof(int) * 2);
        res[*returnSize][0] = intervals[i][0];
        res[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }
    return res;
}
// @lc code=end

