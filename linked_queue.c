#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int val;
    struct n* next;
} node;

typedef struct q {
    node* front;
    node* back;
} queue;

queue* init_queue() {
    queue* q = (queue*) malloc(sizeof(queue));
    q->front = NULL;
    q->back = NULL;
    return q;
}
void q_add(queue* q, int val) {
    if(q->front == NULL && q->back == NULL) {
        q->front = (node*) malloc(sizeof(node));
        q->front->next = NULL;
        q->back = q->front;
        q->back->val = val;
        return;
    }
    node* new_node = (node*) malloc(sizeof(node));
    new_node->val = val;
    q->back->next = new_node;
    new_node->next = NULL;
    q->back = new_node;
}

int q_pop(queue* q) {
    int val;
    if(q->front == NULL && q->back == NULL) {
        *((int*) NULL) = 1;
        return 0;
    }
    if(q->front == q->back) {
        val = q->front->val;
        free(q->front);
        q->front = NULL;
        q->back = NULL;
        return val;
    }
    node* next_node = q->front->next;
    val = q->front->val;
    free(q->front);
    q->front = next_node;
    return val;
}

int main() {
    queue* q = init_queue();
    q_add(q, 10);
    q_add(q, 11);
    printf("%d\n", q_pop(q));
    printf("%d\n", q_pop(q));
    return 0;
}
