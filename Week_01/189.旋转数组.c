/*
 * @lc app=leetcode.cn id=189 lang=c
 *
 * [189] 旋转数组
 */

// @lc code=start


void rotate(int* nums, int numsSize, int k){
    //numsSize = 4, k = 2, abcd 移动第一次， cbad, bd未移动
    //计数，需要移动numsSize 次
    if (k <= 0)
        return;
    int count = 0;
    for (int start = 0; count < numsSize; start++) {
        int cur = start;
        int pre = nums[cur];
        do {
            int next = (cur + k) % numsSize;
            int tmp = nums[next];
            nums[next] = pre;
            pre = tmp;
            cur = next;
            count++;
        }while(cur != start);
    }
}
// @lc code=end

