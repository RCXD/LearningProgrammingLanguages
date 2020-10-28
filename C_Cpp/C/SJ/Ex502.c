#include <stdio.h>
#define MAX 100

typedef struct {
    int top;    // 제일 위에 있는 요소의 인덱스번호.
    int data[MAX];
} Stack;
//void display(Stack *ps) {         // 구조체포인터 버전.
//    for (int i = 0; i <= ps->top; i++) {   // ps->top : 최상단 요소의 인덱스번호.
//        printf("%d ", ps->data[i]);
//    }
//    printf("<--Top");
//}
void display(Stack s) {             // 구조체 버전.
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("<--Top\n");
}
void push_stack(Stack *ps, int value) {
    ps->data[++(ps->top)] = value;
}
int pop_stack(Stack *ps) {    // 만약 스택이 비어있으면, -1을 리턴.
    if (ps->top == -1)
        return -1;
    return ps->data[ps->top--];
}
int peek_stack(Stack *ps) {    // 만약 스택이 비어있으면, -1을 리턴.
    if (ps->top == -1)
        return -1;
    return ps->data[ps->top];
}
void main() {
    Stack stack;       // 구조체 할당

    // 초기화
    stack.top = -1;

    for(int i=1; i<=4; i++)
        push_stack(&stack, i*10);

    //display(&stack);  // 구조체포인터 버전 (권장)
    display(stack);    // 구조체 버전.
    printf("하나를 pop: %d\n", pop_stack(&stack));
    display(stack);    // 구조체 버전.
    printf("최상단요소 : %d\n", peek_stack(&stack));

}






