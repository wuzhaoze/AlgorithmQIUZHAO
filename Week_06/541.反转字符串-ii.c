/*
 * @lc app=leetcode.cn id=541 lang=c
 *
 * [541] 反转字符串 II
 */

// @lc code=start


char * reverseStr(char * s, int k){
    int len = strlen(s);
    if (s == NULL || len == 0)
        return NULL;
    
    for (int i = 0; i < len; i += 2*k){
        int left = i;
        int right = (i + k - 1) >= len ? len - 1: i + k - 1;
        while(left <= right){
            char t = s[left];
            s[left++] = s[right];
            s[right--] = t;
        }
    }
    return s;

}


// @lc code=end

