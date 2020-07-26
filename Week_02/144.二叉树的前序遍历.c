/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
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

int getTreeSize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return getTreeSize(root->left) + getTreeSize(root->right) + 1;
}

void preorder(struct TreeNode* root, int* returnSize, int* ret)
{
    if (root == NULL)
        return;
    ret[(*returnSize)++] = root->val;
    preorder(root->left, returnSize, ret);
    preorder(root->right, returnSize, ret);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) 
        return NULL;
    int* out = (int*) malloc(sizeof(int) * getTreeSize(root));
    preorder(root, returnSize, out);
    return out;
}


// @lc code=end

