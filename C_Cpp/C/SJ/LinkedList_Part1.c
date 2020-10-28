#include <stdio.h>
#include <stdlib.h>

typedef struct node* Link;
struct node {
    int data;
    Link next;
};

void display(Link pnode) {          // "10 -> 20 -> 30 -> (NULL)"
    while (pnode != NULL) {
        printf("%d -> ", pnode->data);
        pnode = pnode->next;
    }
    printf("(NULL)\n");
}

// "(NULL) <- 30 <- 20 <- 10 <- (head)"
void display_reverse(Link pnode) {  // (고급)
    if (pnode == NULL) {
        return;
    }
    display_reverse(pnode->next);
    printf(" <- %d", pnode->data);
}
int count_nodes(Link pnode) {
    int count = 0;
    while (pnode != NULL) {
        count++;
        pnode = pnode->next;
    }
    return count;
}
void create_node(struct node** ppnode, int value) {
    Link pnode = *ppnode;
    // 연결리스트에 노드의 개수가 0개인 상황이라면:
    if (pnode == NULL) {
        *ppnode = (Link)malloc(sizeof(struct node));
        (*ppnode)->data = value;
        (*ppnode)->next = NULL;
        return;
    }
    // 마지막 노드까지 탐색, 탐색의 결과 pnode가 마지막 노드를 가리키고 있도록:
    while (pnode->next != NULL)
        pnode = pnode->next;
    pnode->next = (Link)malloc(sizeof(struct node));
    pnode = pnode->next;
    pnode->data = value;
    pnode->next = NULL;
}
void insert_node_front(Link* ppnode, int value) {
    Link head = *ppnode;        // head : 첫 번째 노드의 주소값. --> 새 노드의 next에 대입할 예정.

    // (1) *ppnode(=main() 함수의 head) 에 malloc()
    *ppnode = (Link)malloc(sizeof(struct node));
    (*ppnode)->data = value;

    // (2) *ppnode가 가리키는 노드의 next에 head(이전에 첫 번째 노드였던 노드의 주소값)를 대입.
    (*ppnode)->next = head;
}
void main() {
    Link head = NULL;       // head : 첫 번째 노드를 가리키는 포인터변수.

    create_node(&head, 10);         // 1.
    create_node(&head, 20);
    create_node(&head, 30);

    display(head);                  // 2.

    printf("(NULL)");
    display_reverse(head);          // 3(고급).
    printf(" <- (head)\n");

    printf("노드의 수 : %d\n", count_nodes(head));   // 4. 

    insert_node_front(&head, 5);    // 5.
    display(head);                  // 5 -> 10 -> 20 -> 30 -> (NULL)

    printf("프로그램 종료");
}

