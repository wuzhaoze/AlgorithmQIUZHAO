/*
 * @lc app=leetcode.cn id=127 lang=c
 *
 * [127] 单词接龙
 */

// @lc code=start
int oneCharDiff(char* s1, char *s2)
{   
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2)
        return 0;
    int diff = 0;
    for (int i = 0; i < len1; i++) {
        if (s1[i] != s2[i])
            diff++;
    }
    return diff == 1? 1: 0;
}

int checkInBank(char *target, char** bank, int bankSize)
{
    int len = strlen(target);
    for (int i = 0; i < bankSize; i++){
        if (strcmp(target, bank[i]) == 0)
            return 1;
    }
    return 0;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    char* queue[10000];
    int inIdx = 0, outIdx = 0;
    queue[inIdx++] = beginWord;
    int queueSize = inIdx - outIdx;
    int *used = (int*) malloc(wordListSize * sizeof(int));
    memset(used, 0, sizeof(int) * wordListSize);

    int cnt = 1;
    while (queueSize > 0){
        for (int i = 0; i < queueSize; i++) {
            if (strcmp(queue[outIdx], endWord) == 0)
                return cnt;
            for (int j = 0; j < wordListSize; j++) {
                if (used[j] == 0 && oneCharDiff(queue[outIdx], wordList[j]) == 1) {
                    queue[inIdx++] = wordList[j];
                    used[j] = 1;
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

