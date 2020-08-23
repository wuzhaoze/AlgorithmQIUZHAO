/*
 * @lc app=leetcode.cn id=1122 lang=c
 *
 * [1122] 数组的相对排序
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    *returnSize = arr1Size;
    if (arr1 == NULL || arr1Size == 0 || arr2 == NULL || arr2Size == 0)
        return NULL;
    int* result = (int*) malloc(sizeof(int) * arr1Size);
    int resultId = 0;
    int count[1001] = {0};

    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    for (int i = 0; i < arr2Size; i++) {
        while(count[arr2[i]] > 0) {
            result[resultId++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    for (int i = 0; i < 1001; i++) {
        while (count[i] > 0){
            result[resultId++] = i;
            count[i]--;
        }
    }
    return result;
}


// @lc code=end

