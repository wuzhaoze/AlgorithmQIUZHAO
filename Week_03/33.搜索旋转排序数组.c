/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start


int search(int* nums, int numsSize, int target){
    int lo = 0, hi = numsSize -1;
    int mid = 0;
    while (lo <= hi){
        mid = ((hi - lo)>>1) + lo;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[lo] <= nums[mid]) {
            if (target >= nums[lo] && target < nums[mid]) 
                hi = mid -1;
            else 
                lo = mid + 1;
        } else {
            if (target > nums[mid] && target <= nums[hi])
                lo = mid + 1;
            else 
                hi = mid - 1;
        }
    }
    return -1;
}


// @lc code=end

