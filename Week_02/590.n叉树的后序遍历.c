/*
 * @lc app=leetcode.cn id=590 lang=c
 *
 * [590] N叉树的后序遍历
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

void _postorder(struct Node* root, int** res, int* returnSize, int* len)
{
    if (root) {
        if (*returnSize + 1 >= *len){
            *len += 100;
            *res = realloc(*res, sizeof(int) * (*len));
        }
        for (int i = 0 ; i < root->numChildren; i++)
            _postorder(root->children[i], res, returnSize, len);
        (*res)[(*returnSize)++] = root->val;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    int len = 10000;
    int* out = (int*)malloc(sizeof(int) * len);
    _postorder(root, &out, returnSize, &len);
    return out;
}
// @lc code=end

