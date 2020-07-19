/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start


bool isAnagram(char * s, char * t){
    int sLen= strlen(s), tLen= strlen(t);
    if(sLen != tLen)
        return false;
    int ascii[256] = {0};
    for (int i = 0; i < sLen; i++) {
        ascii[s[i]]++;
    }
    

    for (int i = 0; i < tLen; i++) {
        ascii[t[i]]--;
        if(ascii[t[i]] < 0)
            return false;
    }
    return true;
}


// @lc code=end

