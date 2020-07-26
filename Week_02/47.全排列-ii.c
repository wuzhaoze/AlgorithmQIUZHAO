/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 */

// @lc code=start

int calPermuteSize(int size)
{
    int sum = 1;
    for(int i = 1; i <= size; i++) 
        sum *= i;
    return sum;
}
bool checkRepeat(int** pRet, int* pRetPos, int iCurPos, int num)
{
    bool ret = false;
    for (int i = 0; i < *pRetPos; i++) {
        if ((0 == memcmp(&pRet[i][0], &pRet[*pRetPos][0], sizeof(int) * iCurPos)) &&
            (pRet[i][iCurPos] == num))
        {
            ret = true;
            break;
        }
    }
    return ret;

}
void backTracePermuteUnique(int* nums, int numsSize, int** pRet, int* pUsed, int*pRetPos, int iCurPos)
{
    if (iCurPos == numsSize){
        *pRetPos += 1;
        memcpy(pRet[*pRetPos], pRet[(*pRetPos)-1], sizeof(int) * numsSize);
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if ( pUsed[i] == 0) {
            if (checkRepeat(pRet, pRetPos, iCurPos, nums[i])) continue;
            pRet[*pRetPos][iCurPos] = nums[i];
            pUsed[i] = 1;
            backTracePermuteUnique(nums, numsSize, pRet, pUsed, pRetPos, iCurPos + 1);
            pUsed[i] = 0;

        }
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int pos = 0;
    int size = calPermuteSize(numsSize);
    int **pRet = (int**)malloc(sizeof(int*) * (size + 1));
    int *pRetCol = (int*)malloc(sizeof(int) * (size + 1));
    int *pUsed = (int*)malloc(sizeof(int) * numsSize);
    memset(pUsed, 0 , sizeof(int) * numsSize);
    for (int i = 0; i <= size; i++) {
        pRet[i] = (int*) malloc(sizeof(int) * numsSize);
        memset(pRet[i], 0, sizeof(int) * numsSize);
        pRetCol[i] = numsSize;
    }
    backTracePermuteUnique(nums, numsSize, pRet, pUsed, &pos, 0);
    free(pUsed);
    *returnSize = pos;
    *returnColumnSizes = pRetCol;
    return pRet;

}


// @lc code=end

