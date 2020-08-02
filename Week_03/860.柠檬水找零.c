/*
 * @lc app=leetcode.cn id=860 lang=c
 *
 * [860] 柠檬水找零
 */

// @lc code=start


bool lemonadeChange(int* bills, int billsSize){
    int five = 0, ten = 0, tewnty = 0;
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) 
            five++;
        else if (bills[i] == 10) {
            ten++;
            five--;
        } else {
            if (ten == 0) 
                five -= 2;
            else
                ten--;
            five--;             
        }
        if (ten < 0 || five < 0)
            return false;
    }
    return true;
}


// @lc code=end

