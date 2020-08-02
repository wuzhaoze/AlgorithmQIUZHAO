/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static char digit2char[10][4] = {
"",
"",
"abc",
"def",
"ghi",
"jkl",
"mno",
"pqrs",
"tuv",
"wxyz",
};
static int gTotal[10] = {0,0,3,3,3,3,3,4,3,4};

void help(char* digits, char**result, int *returnSize, int *str, int depth, int start)
{
    //resursion terminator
    if (start == depth) {
        for (int i = 0; i < depth; i++)
            result[*returnSize][i] = digit2char[digits[i] - '0'][str[i]];
        
        result[*returnSize][depth] = '\0';
        (*returnSize)++;
        return;
    }
    //process currrent problem
    for (str[start] = 0; str[start] < gTotal[digits[start] - '0']; str[start]++) {
        help(digits, result, returnSize, str, depth, start + 1);
    }
    //drill down

    //reserved status
}
char ** letterCombinations(char * digits, int* returnSize){
    *returnSize = 0;
    int depth = strlen(digits);
    if (depth == 0)    
        return NULL;
    int totalSize = 1;
    for (int i = 0; i < depth; i++)
        totalSize *= digits[i] == '7'|| digits[i] == '9' ? 4 : 3;
    
    char** result = (char**)malloc(sizeof(char*) * totalSize);
    for (int i = 0; i < totalSize; i++)
        result[i] = (int*)calloc((depth + 1), sizeof(char));
    int* str = (int*)malloc (sizeof(int) * (depth + 1));
    help(digits, result, returnSize, str, depth, 0);
    return result;

}
// @lc code=end

