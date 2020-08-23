/*
 * @lc app=leetcode.cn id=680 lang=c
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start

int judge(char *s, int left, int right)
{
    while(left < right) {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}
bool validPalindrome(char * s){
    int len = strlen(s);
    if (s == NULL || len == 0)
        return false;
    for (int i = 0, j = len - 1; i < j; i++, j--){
        if (s[i] != s[j]) {
            return judge(s, i + 1, j) || judge(s, i, j - 1);
        }
    }
    return true;

}


// @lc code=end

