/*
 * @lc app=leetcode.cn id=205 lang=c
 *
 * [205] 同构字符串
 */

// @lc code=start


bool isIsomorphic(char * s, char * t){
    int slen = strlen(s), tlen = strlen(t);
    if ( slen != tlen)
        return false;
    int cnts[256]= {0};
    int cntt[256] = {0};
    for (int i = 0; i < slen; i++) {
        // if (cnts[s[i]] == 0)
        //     cnts[s[i]] = t[i];
        // else if (cnts[s[i]] != t[i])
        //     return false;
        // if (cntt[t[i]] == 0)
        //     cntt[t[i]] = s[i];
        // else if (cntt[t[i]] != s[i])
        //     return false;
        if (cnts[s[i]] != cntt[t[i]])
            return false;
        cnts[s[i]] = cntt[t[i]] = i + 1;
    }
    return true;
}


// @lc code=end

