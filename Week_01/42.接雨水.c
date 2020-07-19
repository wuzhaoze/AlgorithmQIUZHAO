/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 */

// @lc code=start


#define MAX(A,B) ((A) >= (B) ? (A) : (B))
#define MIN(A,B) ((A) < (B) ? (A) : (B))

int trap(int* height, int heightSize){
    
    /*
    //解法1， 计算当前位置的接纳的雨水，等于左侧最大值，和右侧最大值中的最小值与当前值的差值
    if (height == NULL || heightSize == 0)
        return 0;

    int *maxLeft = (int*) malloc(sizeof(int) * heightSize);
    int *maxRight = (int*) malloc(sizeof(int) * heightSize);

    int i = 0, ret = 0;
    maxLeft[0] = height[0];
    maxRight[heightSize - 1] = height[heightSize - 1];
    
    for (i = 1 ; i < heightSize; i++) {
        maxLeft[i] = MAX(maxLeft[i -1], height[i-1]);
        maxRight[heightSize - i -1] = MAX(maxRight[heightSize - i], height[heightSize - i]);
    }

    for (i = 0; i < heightSize - 1; i++)
        ret += MAX(0, MIN(maxLeft[i], maxRight[i]) - height[i]);
    
    return ret;
    */

   //解法二，查找到最高峰，再依次构建谷地

    int max = 0, maxId = 0;
    int water = 0, waterTmp = 0;
    for (int i = 0; i < heightSize; i++) {
        if (height[i] > max) {
            max = height[i];
            maxId = i;
        }
    }

    for (int i = 0,waterTmp = 0; i < maxId; i++) {
        if (height[i] > waterTmp) 
            waterTmp = height[i];
        water += waterTmp - height[i];
    }

    for (int i = heightSize - 1, waterTmp = 0; i > maxId; i--) {
        if(height[i] > waterTmp) 
            waterTmp = height[i];
        water += waterTmp - height[i];
    } 

    return water;

}


// @lc code=end

