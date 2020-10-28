#include <stdio.h>
#include <stdlib.h>

typedef struct node *Link;
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
void create_node(struct node **ppnode, int value) {
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
void insert_node_front(Link *ppnode, int value) {
    Link head = *ppnode;        // head : ù ��° ����� �ּҰ�. --> �� ����� next�� ������ ����.

    // (1) *ppnode(=main() �Լ��� head) �� malloc()
    *ppnode = (Link)malloc(sizeof(struct node));
    (*ppnode)->data = value;

    // (2) *ppnode�� ����Ű�� ����� next�� head(������ ù ��° ��忴�� ����� �ּҰ�)�� ����.
    (*ppnode)->next = head;
}
void insert_node_at(Link *ppnode, int index, int value) {
    if (index == 0) {
        insert_node_front(ppnode, value);
        return;
    }
    Link pnode = *ppnode;   // *ppnode �� �ǹ̻� head(�� ��� �ִ� �ּҰ�).
    Link pre_pnode = NULL;

    for (int i = 1; i <= index; i++) {
        pre_pnode = pnode;
        pnode = pnode->next;
    }
    if (pre_pnode != NULL) {
        Link new_node = (Link)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = pnode;
        pre_pnode->next = new_node;
    }
}
void delete_node_by_value(Link *ppnode, int value) {
    Link pnode = *ppnode;       // *ppnode�� �ǹ̻� main�� head
    if (pnode->data == value) {    // ù ��° ��带 �����ϴ� ���.
        Link pnode_delete = pnode;
        *ppnode = pnode->next;
        free(pnode_delete);
    }
    else {                         // �� ��° ������ ��带 �����ϴ� ���.
        Link pre_pnode = NULL;
        while (pnode != NULL) {
            if (pnode->data == value) {
                Link node_delete = pnode;
                pre_pnode->next = pnode->next;
                free(node_delete);
                break;
            }
            pre_pnode = pnode;
            pnode = pnode->next;
        }
    }
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

    insert_node_at(&head, 1, 55);   // 6.
    display(head);  //    5 -> 55 -> 10 -> 20 -> 30 -> (NULL)

    delete_node_by_value(&head, 55); // 8.
    display(head);  //     5 -> 10 -> 20 -> 30 -> (NULL)

    printf("���α׷� ����");
}

