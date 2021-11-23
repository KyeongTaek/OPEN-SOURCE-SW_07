//과목별 할일
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 100

struct list {
	struct list* next;
	char subject[100];
	char things[100];
	int l_page;
};

void to_do(FILE *fp)
{
	FILE* FP = fp;
	list* now = (list*)malloc(sizeof(struct list));
	while (1)//switch case 이용해서 1. 이전 정보 불러오기, 2. 새로 작성하기
	{
		time_t t = time(NULL);
		char sub[100];
		char thg[100];
		int page;
		struct tm tm = *localtime(&t);

		printf("과목(없다면 x를 입력하세요) : ");
		scanf_s("%s", &sub, SIZE);
		strcpy(now->subject, sub);
		if (sub[0] == 'x')
			break;
		printf("할일(공백대신'_'를 사용하세요) : ");
		scanf_s("%s", &thg, SIZE);
		strcpy(now->things, thg);
		printf("마지막으로 공부한 페이지 : ");
		scanf_s("%d", &page);
		now->l_page = page;
		fprintf(FP, "%d-%d-%d\n",
			tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);
		fprintf(FP, "과목 : %s\n", sub);
		fprintf(FP, "할일 : %s\n", thg);
		fprintf(FP, "마지막 페이지 : %d\n", page);
		fprintf(FP, "===========================\n");

		list* newnode = (list*)malloc(sizeof(struct list));
		now->next = newnode;
		now = now->next;
	}

}

void choice(FILE *fp)
{
	int num = 0;
	char buffer[1000] = { 0, };
	printf("다음 중 하고 싶은 작업의 번호를 입력하세요\n1. 이전 정보 불러오기\n2. 새로 작성하기\n");
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:
		fread(buffer, 1, 1000, fp);
		printf("%s", buffer);
		break;
	case 2:
		to_do(fp);
		break;
	default:
		break;
	}
}

int main()
{
	FILE* fp;
	fp = fopen("To_do_things.txt", "a+");


	choice(fp);

	fclose(fp);
	return 0;
}
