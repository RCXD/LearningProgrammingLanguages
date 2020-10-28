#include <stdio.h>
#define MAX 100

typedef struct {
    int front;  // ù ����� �ε�����ȣ(head)
    int back;   // ������ ����� �ε�����ȣ(tail)
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
    Queue queue;     // ť �޸� �Ҵ�.
    // ť �ʱ�ȭ
    queue.front = 0;
    queue.back = -1;


    for(int i=1; i<=5; i++)     // �ټ� �� enqueue(��ť)
        enqueue(&queue, i*10);
    display(&queue);  // 10 20 30 40 50 <-- back

    for(int i=1; i<=3; i++)     // �� �� dequeue(��ť)
        printf("dequeue�� �� : %d\n", dequeue(&queue));
    display(&queue);  // 40 50 <-- back
}






