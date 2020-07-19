/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    /*
    //暴力破解
    for (int i = 0; i < numsSize -1; i++) {
        int tmp = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == tmp) {
                int *res = (int *) malloc(2 * sizeof(int));
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
    }
    */
    
    //排序后，两侧夹逼
    int *new_arr = (int *) malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++) {
        new_arr[i] = nums[i];
    }
    qsort(new_arr, numsSize, sizeof(int), cmpfunc);

    for (int i = 0, j = numsSize -1; i < j; ) {
        if (nums[i] + nums[j] == target) {
            int *res = (int *) malloc(2 * sizeof(int));
            res[0] = i;
            res[1] = j;
            *returnSize = 2;
            free(new_arr);
            return res;
        } 
        if (nums[i] + nums[j] < target) 
            i++;
        else 
            j++;

    }
    
    return NULL;
}


// @lc code=end

