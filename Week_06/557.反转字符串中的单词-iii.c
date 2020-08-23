/*
 * @lc app=leetcode.cn id=557 lang=c
 *
 * [557] 反转字符串中的单词 III
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

char * reverseWords(char * s){
    int len = strlen(s);
    if (s == NULL || len == 0)
        return s;
    int idx = 0;
    for(int i = 0; i < len ; i++) {
        if (s[i] == ' '){
            reversed(s, idx, i - 1);
            idx = i + 1;
        }
        if (i == len -1) 
            reversed(s, idx, i);
    }
    return s;
}


// @lc code=end

