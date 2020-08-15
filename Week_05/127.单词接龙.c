/*
 * @lc app=leetcode.cn id=127 lang=c
 *
 * [127] 单词接龙
 */

// @lc code=start

int oneCharDiff(char *s1, char *s2) 
{
    int diff  = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2)
        return 0;
    for (int i = 0; i < len1; i++) {
        if (s1[i] != s2[i])
            diff++;
    }
    return diff == 1? 1 : 0;
}

int isInWordList(char* beginWord, char ** wordList, int wordListSize)
{
    for (int i = 0; i < wordListSize; i++) {
        if ( 0 == strcmp(beginWord, wordList[i])) 
            return 1;
    }
    return 0;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    //长度判断
    //判断是否在 wordList
    // if (isInWordList(beginWord, wordList, wordListSize) == 0) {
    //     return 0;
    // }
    char *queue[10000];
    int inIdx = 0, outIdx = 0;
    int *pUsed = (int*)malloc(sizeof(int) * wordListSize);
    memset(pUsed, 0, sizeof(int) *wordListSize);
    queue[inIdx++] = beginWord;
    int queueSize = inIdx - outIdx;
    int cnt = 1;
    while (queueSize > 0) {
        for (int i = 0; i < queueSize; i++) {
            if (0 == strcmp(queue[outIdx], endWord)) 
                return cnt;
            for (int j = 0; j < wordListSize; j++) {
                if (pUsed[j] == 0 && 1 == oneCharDiff(queue[outIdx], wordList[j])) {
                    queue[inIdx++] = wordList[j];
                    
                    pUsed[j] = 1;
                }
            }
            outIdx++;
        }
        cnt++;
        queueSize = inIdx - outIdx;
    }
    return 0;
}


// @lc code=end

