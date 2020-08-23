/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start


bool isAnagram(char * s, char * t){
    int sLen = strlen(s), tLen = strlen(t);
    if (sLen != tLen)
        return false;
    int cnt[26] = {0};
    
    for (int i = 0; i < sLen; i++) {
        cnt[s[i] - 'a']++;
    }

    for (int i = 0; i < tLen; i++) {
        cnt[t[i] - 'a']--;
        if (cnt[t[i] - 'a'] < 0)
            return false;
    }

    return true;
}


// @lc code=end

