/*
 * @lc app=leetcode.cn id=347 lang=c
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <uthash.h>
typedef struct {
    int key;
    int cnt;
    UT_hash_handle hh;
}number_t;

static void countNumber(number_t **head, int key, int cnt)
{
    number_t *node = NULL;
    HASH_FIND_INT(*head, &key, node);
    if (node != NULL) {
        node->cnt++;
        return;
    }
    node = (number_t*)malloc(sizeof(number_t));
    node->cnt = cnt;
    node->key = key;
    HASH_ADD_INT(*head, key, node);
}

static void countArray(number_t **head, int *arr, int n)
{
    for (int i = 0; i < n; i++)
        countNumber(head, arr[i], 1);
}

static void release(number_t **hash)
{
    number_t *node, *next;
    HASH_ITER(hh, *hash, node, next) {
    	HASH_DEL(*hash, node);
    }
}

static int cmp(number_t *a, number_t *b) 
{
    return (b->cnt) - (a->cnt);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    int *result  = (int*)malloc(sizeof(int) * k);
    *returnSize = k;
    number_t *hash = NULL;
    countArray(&hash, nums, numsSize);
    HASH_SORT(hash, cmp);
    int i = 0;
    number_t * node = NULL, *next = NULL;
    HASH_ITER(hh, hash, node, next){
        result[i++] = node->key;
        if (i == k){
            break;
        } 
    }
    release(&hash);
    return result;
}	
// @lc code=end

