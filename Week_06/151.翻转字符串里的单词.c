/*
 * @lc app=leetcode.cn id=151 lang=c
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start

void reversed(char*s ,int left, int right)
{
    while(left < right){
        char t = s[left];
        s[left++] = s[right];
        s[right--] = t;
    }
}

void trimSpace(char *s ,int start)
{
    do {
        s[start] = s[start+1];
        start++;
    }while(s[start]);
}

char * reverseWords(char * s){
    while (*s == ' ') s++;
    int len = strlen(s) - 1;
    if (len < 0)
        return s;
    while(s[len] == ' '){
        s[len] = '\0';
        len--;
    }

    reversed(s, 0, len);

    int idx = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            reversed(s, idx, i - 1);
            while( s[i+1] && s[i+1] == ' ') {
                trimSpace(s, i+1);
                len--;
            }
            idx = i + 1;
        }
    }
    reversed(s, idx,len);
    return s;

}


// @lc code=end

