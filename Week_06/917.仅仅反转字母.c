/*
 * @lc app=leetcode.cn id=917 lang=c
 *
 * [917] 仅仅反转字母
 */

// @lc code=start


char * reverseOnlyLetters(char * S){
    int len = strlen(S);
    if (S == NULL || len == 0) 
        return S;
    // int left = 0, right = len -1;
    // while (left < right)
    // {
    //     while (left < right && !isalpha(S[left])) left++;
    //     while (left < right && !isalpha(S[right])) right--;
    //     if (left < right) {
    //         char t = S[left];
    //         S[left++] = S[right];
    //         S[right--] = t;
    //     }
        
    // }
    for (int i = 0, j = len -1; i < j;) {
        if (! isalpha(S[i]))
            i++;
        else if (!isalpha(S[j]))
            j--;
        else {
             char t = S[i];
             S[i++] = S[j];
             S[j--] = t;
        }
    }
    
    return S;
}


// @lc code=end

