#include <stdio.h>
#define MAX 100

typedef struct {
    int front;  // 첫 요소의 인덱스번호(head)
    int back;   // 마지막 요소의 인덱스번호(tail)
    int data[MAX];
} Queue;
void enqueue(Queue *pq, int value) {
    pq->back++;
    pq->data[pq->back] = value;
}
int dequeue(Queue *pq) {
    int result = pq->data[pq->front];
    pq->front++;
    return result;
}
void display(Queue *pq) {
    for (int i = pq->front; i <= pq->back; i++) {
        printf("%d ", pq->data[i]);
    }
    printf(" <--- back\n");
}
void main() {
    Queue queue;     // 큐 메모리 할당.
    // 큐 초기화
    queue.front = 0;
    queue.back = -1;


    for(int i=1; i<=5; i++)     // 다섯 번 enqueue(인큐)
        enqueue(&queue, i*10);
    display(&queue);  // 10 20 30 40 50 <-- back

    for(int i=1; i<=3; i++)     // 세 번 dequeue(디큐)
        printf("dequeue한 값 : %d\n", dequeue(&queue));
    display(&queue);  // 40 50 <-- back
}






