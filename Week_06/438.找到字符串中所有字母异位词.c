/*
 * @lc app=leetcode.cn id=438 lang=c
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize){
    *returnSize = 0;
    int slen = strlen(s), plen = strlen(p);
    if (s == NULL || p == NULL || slen < plen)
        return NULL;
    int *res = (int*)malloc(sizeof(int) * slen + 1);
    int hash[256] = {0};
    for (int i = 0; i < plen; i++) 
        hash[p[i]]++;
    
    int left = 0, right = 0, count = plen;
    while(right < slen) {
        if (hash[s[right++]]-- >= 1) count--;
        if (count == 0) {
            res[*returnSize] = left;
            (*returnSize)++;
        }
        if (right - left == plen && hash[s[left++]]++ >= 0) count++;
    }

    return res;
}


// @lc code=end

