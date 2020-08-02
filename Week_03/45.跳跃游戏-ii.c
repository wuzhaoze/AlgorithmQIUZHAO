/*
 * @lc app=leetcode.cn id=45 lang=c
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

#define MAX(X,Y) ((X)>(Y) ? (X) : (Y))

int jump(int* nums, int numsSize){
    int end = 0, steps = 0, maxPos = 0;
    for (int i = 0; i < numsSize-1; i++) {
        maxPos = MAX(maxPos, i + nums[i]);
        if (i == end) {
            steps++;
            end = maxPos;
        }
    }
    return steps;
}


// @lc code=end

