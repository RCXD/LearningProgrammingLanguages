#include <stdio.h>
#define MAX 100

typedef struct {
    int top;    // ���� ���� �ִ� ����� �ε�����ȣ.
    int data[MAX];
} Stack;
//void display(Stack *ps) {         // ����ü������ ����.
//    for (int i = 0; i <= ps->top; i++) {   // ps->top : �ֻ�� ����� �ε�����ȣ.
//        printf("%d ", ps->data[i]);
//    }
//    printf("<--Top");
//}
void display(Stack s) {             // ����ü ����.
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("<--Top\n");
}
void push_stack(Stack *ps, int value) {
    ps->data[++(ps->top)] = value;
}
int pop_stack(Stack *ps) {    // ���� ������ ���������, -1�� ����.
    if (ps->top == -1)
        return -1;
    return ps->data[ps->top--];
}
int peek_stack(Stack *ps) {    // ���� ������ ���������, -1�� ����.
    if (ps->top == -1)
        return -1;
    return ps->data[ps->top];
}
void main() {
    Stack stack;       // ����ü �Ҵ�

    // �ʱ�ȭ
    stack.top = -1;

    for(int i=1; i<=4; i++)
        push_stack(&stack, i*10);

    //display(&stack);  // ����ü������ ���� (����)
    display(stack);    // ����ü ����.
    printf("�ϳ��� pop: %d\n", pop_stack(&stack));
    display(stack);    // ����ü ����.
    printf("�ֻ�ܿ�� : %d\n", peek_stack(&stack));

}






