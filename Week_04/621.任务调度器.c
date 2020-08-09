/*
 * @lc app=leetcode.cn id=621 lang=c
 *
 * [621] 任务调度器
 */

// @lc code=start


int leastInterval(char* tasks, int tasksSize, int n){
    // total = (max -1) *(n+1) + cnt
    // max =  最大任务数， cnt = 最大任务数个数

    if (n == 0) 
        return tasksSize;
    if (tasks == NULL || tasksSize == 0) 
        return 0;
    
    int t[26] = {0};
    int max = 0;

    for (int i = 0; i < tasksSize; i++) {
        t[tasks[i] - 'A']++;
        max = max > t[tasks[i] - 'A'] ? max : t[tasks[i] - 'A'];
    }

    int cnt = 0;
    for (int i = 0 ; i < 26; i++) {
        if (t[i] == max)
            cnt++;
    }

    int total = (max-1) * (n+1) + cnt;
    if (total < tasksSize)
        total = tasksSize;
    return total;
}
// @lc code=end

