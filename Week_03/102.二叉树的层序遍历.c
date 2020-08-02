/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_SIZE  2000
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL)    
        return NULL;
    
    int** ret = (int**)malloc(sizeof(int*) * MAX_SIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX_SIZE);

    struct TreeNode *queue[MAX_SIZE];
    int inIdx = 0, outIdx = 0;
    queue[inIdx++] = root;
    int levelCnt = inIdx - outIdx;
    while (levelCnt > 0) {
        ret[*returnSize] = (int*)calloc(levelCnt, sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelCnt;
        for (int i = 0; i < levelCnt; i++) {
            if (queue[outIdx]->left != NULL)
                queue[inIdx++] = queue[outIdx]->left;
            if (queue[outIdx]->right != NULL)
                queue[inIdx++] = queue[outIdx]->right;    
            ret[*returnSize][i] = queue[outIdx++]->val;
        }
        (*returnSize)++;
        levelCnt = inIdx -outIdx;
    }
    return ret;
}


// @lc code=end

