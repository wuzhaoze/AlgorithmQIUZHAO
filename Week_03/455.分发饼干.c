/*
 * @lc app=leetcode.cn id=455 lang=c
 *
 * [455] 分发饼干
 */

// @lc code=start

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int i = 0, j = 0;
    for (; i < gSize && j <sSize;){
        if (g[i] <= s[j])
            i++;
        j++;
    }    
    return i;
}


// @lc code=end

