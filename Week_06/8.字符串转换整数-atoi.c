/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start


int myAtoi(char * str){
    long n = 0;
    int sign = 0;
    while (*str == ' ') str++;

    if (*str == '-' || *str == '+') {
        sign = (*str == '-');
        str++;
    }

    while (isdigit(*str)) {
        if ( 10 * n + *str - '0' > INT_MAX) {
            return sign  ? INT_MIN : INT_MAX;
        }
        n = 10 * n + *str - '0';
        ++str;
    }
    return sign ? -n : n;
}


// @lc code=end

