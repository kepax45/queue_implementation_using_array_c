#include <stdio.h>
#include <stdlib.h>

typedef struct q {
    int size;
    int* queue_arr;
    int* front;
    int* back;
} queue;

queue* init_queue() {
    queue* q = (queue*) malloc(sizeof(queue));
    q->queue_arr = (int*) malloc(sizeof(int));
    q->size = 1;
    q->front = q->queue_arr - 1;
    q->back = q->queue_arr - 1;
}

void q_add(queue *q, int val) {
    if(q->front == q->queue_arr - 1 && q->back == q->queue_arr - 1) {
        q->front = q->queue_arr;
        q->back = q->queue_arr;
        q->queue_arr[0] = val;
        return;
    }
    if(q->back == q->queue_arr + q->size - 1) {
        q->size *= 2;
        q->queue_arr = (int*) realloc(q->queue_arr, q->size);
    }
    q->back += 1;
    *(q->back) = val;
}
int q_pop(queue *q) {
    int val;
    if(q->front == q->queue_arr - 1 || q->front > q->back) {
        *((int*) NULL) = 1;
        return -1;
    }
    val = *(q->front);
    q->front += 1;
    return val;
}


int main() {
    queue* q = init_queue();
    q_add(q, 10);
    q_add(q, 11);
    q_add(q, 13);
    printf("%d\n", q_pop(q));
    printf("%d\n", q_pop(q));
    return 0;
}
