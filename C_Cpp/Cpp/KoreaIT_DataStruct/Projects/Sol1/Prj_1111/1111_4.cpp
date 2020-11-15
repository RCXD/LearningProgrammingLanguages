#include <stdio.h>

//파일 내 미지의 값 찾기: 숫자맞추기 게임 구현!
	/* 별로 안좋은 코드
	int data[1];
	for (int i = 0; i < 1; i++) {
		fscanf(in, "%d", &data[i]);
		printf("%d\n", data[i]);
	}
	*/

//랜덤으로 받아서 맞추는것도....

//코드는?? 받아서 마무리해보자...!

int main() {

    FILE* in = fopen("../../../TEST/input.txt", "r");
    FILE* out = fopen("../../../TEST/output.txt", "w");

    printf("사용자의 이름을 입력하세요.\n");
    char name[10];
    scanf("%s", name);

    int data, n, cnt = 0;
    fscanf(in, "%d", &data);
    while (1) {
        printf("데이터입력: ");
        scanf("%d", &n);
        cnt++;
        if (n == data) {
            printf("정답!\n");
            break;
        }
        else if (n > data) {
            printf("DOWN!\n");
        }
        else {
            printf("UP!\n");
        }
    }
    fprintf(out, "%s님, %d번만에 정답!\n", name, cnt); //스코어보드 같은 개념!

    fclose(in);

    return 0;
}