/*
 * @lc app=leetcode.cn id=515 lang=c
 *
 * [515] 在每个树行中找最大值
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

#define MAX(x, y) ((x) > (y) ? (x) : (y))

void dfs(struct TreeNode *root, int *ret, int *returnSize, int depth)
{
    if (root == NULL)
        return;
    if ((*returnSize) < depth + 1) {
        ret[depth] = root->val;
        *returnSize = depth + 1;
    } else {
        ret[depth] = MAX(root->val , ret[depth]);
    }
    dfs(root->left, ret, returnSize, depth + 1);
    dfs(root->right, ret, returnSize, depth + 1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *ret = (int*)malloc(sizeof(int) *2000);
    dfs(root, ret, returnSize, 0);
    return ret;
}


// @lc code=end

