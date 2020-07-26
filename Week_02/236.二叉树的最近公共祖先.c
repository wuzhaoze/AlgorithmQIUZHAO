/*
 * @lc app=leetcode.cn id=236 lang=c
 *
 * [236] 二叉树的最近公共祖先
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
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q)
        return root;
    struct TreeNode* left = lowestCommonAncestor(root->left, p , q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    //if (left == NULL || right == NULL) return NULL;
    if (left == NULL)   return right;
    if (right == NULL) return left;
    return root;
}
// @lc code=end

