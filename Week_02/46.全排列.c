/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 */

// @lc code=start

int calPermuteSize(int numsSize){
    int     i           = 0;
    int     iRetSize    = 1;

    for (i = 1; i <= numsSize; i++)
    {
        iRetSize *= i;
    }

    return iRetSize;
}

void backTrackPermute(int* nums, int numsSize, int **pRet, int *pUsed, int*pRetPos, int iCurPos)
{
    int iTmp = 0;
    int i =0;
    if (iCurPos == numsSize) {
        *pRetPos += 1;
        memcpy(pRet[*pRetPos], pRet[(*pRetPos)-1], sizeof(int) * numsSize);
        return;
    }
    for(i = 0; i < numsSize; i++){
        if ( pUsed[i] == 0) {
            //iTmp = i;
            pRet[*pRetPos][iCurPos] =  nums[i];
            pUsed[i] = 1;
            backTrackPermute(nums, numsSize, pRet, pUsed, pRetPos, iCurPos + 1);
            pUsed[i] = 0;
        }
    }
    return;

}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int iRetPos = 0;
    int iRetSize = calPermuteSize(numsSize);
    int** pRet = (int **) malloc(sizeof(int*) * (iRetSize + 1 ));
    int* pRetCol = (int*) malloc(sizeof(int) * (iRetSize + 1 ));
    int *pUsed = (int*) malloc(sizeof(int) * numsSize);
    memset(pUsed, 0 ,sizeof(int) * numsSize);
    for (int i = 0; i <= iRetSize; i++) {
        pRet[i] = (int*) malloc(sizeof(int) * numsSize);
        memset(pRet[i], 0, sizeof(int) * numsSize);
        pRetCol[i] = numsSize;
    }

    backTrackPermute(nums, numsSize, pRet, pUsed, &iRetPos, 0);
    free(pUsed);
    *returnSize = iRetSize;
    *returnColumnSizes = pRetCol;
    return pRet;
}


// @lc code=end

