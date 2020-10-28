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
void display_reverse(Link pnode) {  // (���)
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
    // ���Ḯ��Ʈ�� ����� ������ 0���� ��Ȳ�̶��:
    if (pnode == NULL) {
        *ppnode = (Link)malloc(sizeof(struct node));
        (*ppnode)->data = value;
        (*ppnode)->next = NULL;
        return;
    }
    // ������ ������ Ž��, Ž���� ��� pnode�� ������ ��带 ����Ű�� �ֵ���:
    while (pnode->next != NULL)
        pnode = pnode->next;
    pnode->next = (Link)malloc(sizeof(struct node));
    pnode = pnode->next;
    pnode->data = value;
    pnode->next = NULL;
}
void insert_node_front(Link* ppnode, int value) {
    Link head = *ppnode;        // head : ù ��° ����� �ּҰ�. --> �� ����� next�� ������ ����.

    // (1) *ppnode(=main() �Լ��� head) �� malloc()
    *ppnode = (Link)malloc(sizeof(struct node));
    (*ppnode)->data = value;

    // (2) *ppnode�� ����Ű�� ����� next�� head(������ ù ��° ��忴�� ����� �ּҰ�)�� ����.
    (*ppnode)->next = head;
}
void main() {
    Link head = NULL;       // head : ù ��° ��带 ����Ű�� �����ͺ���.

    create_node(&head, 10);         // 1.
    create_node(&head, 20);
    create_node(&head, 30);

    display(head);                  // 2.

    printf("(NULL)");
    display_reverse(head);          // 3(���).
    printf(" <- (head)\n");

    printf("����� �� : %d\n", count_nodes(head));   // 4. 

    insert_node_front(&head, 5);    // 5.
    display(head);                  // 5 -> 10 -> 20 -> 30 -> (NULL)

    printf("���α׷� ����");
}

