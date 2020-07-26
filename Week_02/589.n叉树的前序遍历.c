/*
 * @lc app=leetcode.cn id=589 lang=c
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
void _preorder(struct Node* root, int **res, int* returnSize, int *len)
{
    if (root) {
        if (*returnSize + 1 >= *len) {
            *len += 100;
            *res = (int*) realloc(*res, sizeof(int) *(*len));
        }
        (*res)[(*returnSize)++] = root->val;
        for(int i = 0; i < root->numChildren; i++) 
            _preorder(root->children[i], res, returnSize, len);

    }
} 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int len = 1000;
    int *out = (int*) malloc(sizeof(int) * len);
    _preorder(root, &out, returnSize, &len);
    return out;
}
// @lc code=end


