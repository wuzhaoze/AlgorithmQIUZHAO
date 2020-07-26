/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
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

int getTreeSize(struct TreeNode *root) 
{
    if (root == NULL)
        return 0;
    return getTreeSize(root->left) + getTreeSize(root->right) + 1;

}

void inorder(struct TreeNode* root, int* returnSize, int* ret)
{
    if (root == NULL) 
        return;
    inorder(root->left, returnSize, ret);
    ret[(*returnSize)++] = root->val;
    inorder(root->right, returnSize, ret);

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) 
        return NULL;
    int *out = (int *) malloc(sizeof(int) * getTreeSize(root));
    inorder(root, returnSize, out);
    return out;
}


// @lc code=end

