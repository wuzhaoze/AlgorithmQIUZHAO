/*
 * @lc app=leetcode.cn id=641 lang=c
 *
 * [641] 设计循环双端队列
 */

// @lc code=start



typedef struct {
    int front;
    int rear;
    int capacity;
    int *q;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *q = (MyCircularDeque *) malloc(sizeof(MyCircularDeque));
    if (q) {
        q->capacity = k + 1;
        q->front = q->rear = 0;
        q->q = (int*) malloc(sizeof(int) * (k + 1));
        if(q->q == NULL) {
            free(q);
            q = NULL;
        }
    }
    return q;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->front == obj->rear) {
        return true;
    }
    return false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if ((obj->rear + 1) % obj->capacity == obj->front) {
        return true;
    }
    return false;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) 
        return false;
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->q[obj->front] = value;
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) 
        return false;
    obj->q[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) 
        return false;
    obj->front = (obj->front + 1) % obj->capacity;
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) 
        return false;
    obj->rear = (obj->rear - 1  + obj->capacity) % obj->capacity;
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) 
        return -1;
    return obj->q[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) 
        return -1;
    return obj->q[(obj->rear - 1 + obj->capacity) % obj->capacity];
}



void myCircularDequeFree(MyCircularDeque* obj) {
    if (obj){
        if (obj->q)
            free(obj->q);
        free(obj);
        obj = NULL;
    }
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
// @lc code=end

