/*
 * @lc app=leetcode.cn id=547 lang=c
 *
 * [547] 朋友圈
 */

// @lc code=start
/* 代码可读性好，但内存泄漏
typedef struct {
    int count;
    int* parent;
}unionFind_t;

unionFind_t * unionFindInit(int count)
{
    unionFind_t * f = (unionFind_t*)malloc(sizeof(unionFind_t));
    f->parent = (int*)malloc(sizeof(int) * count);
    f->count = count;
    for (int i = 0; i < count; i++) 
        f->parent[i] = i;
    return f;
}
int find(unionFind_t * f, int x)
{
    while(x != f->parent[x]) {
        x = f->parent[x];
    }
    return x;
}

void unionInsert(unionFind_t * f, int x, int y)
{
    int pX = find(f, x);
    int pY = find(f, y);
    if (pX == pY)
        return;
    if (pX != pY)
        f->parent[pX] = pY;
    f->count--;
}


int findCircleNum(int** M, int MSize, int* MColSize){
    if (M == NULL || MSize == 0 || MColSize == NULL || MColSize[0] == 0)
        return 0;
    unionFind_t *uf = unionFindInit(MSize);
    for (int i = 0; i < MSize; i++) {
        for (int j = 0; j < MSize; j++) {
            if(M[i][j] == 1) {
                unionInsert(uf, i, j);
            }
        }
    }
    return uf->count;
}
 */


int find(int * p, int x)
{
    while(x != p[x]) {
        x = p[x];
    }
    return x;
}

void unionInsert(int *p, int x, int y, int *count)
{
    int pX = find(p, x);
    int pY = find(p, y);
    if (pX == pY)
        return;
    if (pX != pY)
        p[pX] = pY;
    (*count)--;
}


int findCircleNum(int** M, int MSize, int* MColSize){
    if (M == NULL || MSize == 0 || MColSize == NULL || MColSize[0] == 0)
        return 0;
    int count = MSize;
    int* parent = (int *)malloc(sizeof(int) * MSize);
    for (int i = 0; i < MSize; i++)
        parent[i] = i;
    for (int i = 0; i < MSize; i++) {
        for (int j = 0; j < MSize; j++) {
            if(M[i][j] == 1) {
                unionInsert(parent, i, j, &count);
            }
        }
    }
    return count;
}
// @lc code=end

