#include <stdio.h>

//���� �� ������ �� ã��: ���ڸ��߱� ���� ����!
	/* ���� ������ �ڵ�
	int data[1];
	for (int i = 0; i < 1; i++) {
		fscanf(in, "%d", &data[i]);
		printf("%d\n", data[i]);
	}
	*/

//�������� �޾Ƽ� ���ߴ°͵�....

//�ڵ��?? �޾Ƽ� �������غ���...!

int main() {

    FILE* in = fopen("../../../TEST/input.txt", "r");
    FILE* out = fopen("../../../TEST/output.txt", "w");

    printf("������� �̸��� �Է��ϼ���.\n");
    char name[10];
    scanf("%s", name);

    int data, n, cnt = 0;
    fscanf(in, "%d", &data);
    while (1) {
        printf("�������Է�: ");
        scanf("%d", &n);
        cnt++;
        if (n == data) {
            printf("����!\n");
            break;
        }
        else if (n > data) {
            printf("DOWN!\n");
        }
        else {
            printf("UP!\n");
        }
    }
    fprintf(out, "%s��, %d������ ����!\n", name, cnt); //���ھ�� ���� ����!

    fclose(in);

    return 0;
}