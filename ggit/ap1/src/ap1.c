
#include <stdio.h>
#include <stdlib.h>


void main() {
	printf("[----- [황슬비] [2018032027] -----]\n\n");
	int list[5]; //int형 배열 선언
	int *plist[5] = {NULL,};//int형 포인트 배열 선언과 동시에 NULL로 초기화

	plist[0] = (int *)malloc(sizeof(int)); //plist[0]에 4bytes만큼 공간 할당하여 주소 배정

	list[0] = 1;
	list[1] = 100;

	*plist[0] = 200; //plist[0]이 가리키는 곳에 200할당

	printf("value of list[0] = %d\n", list[0]); //list[0]의 값 출력 : 1
	printf("address of list[0] = %p\n", &list[0]); //list[0]의 주소 출력
	printf("value of list = %p\n", list); //list의 값 출력
	printf("address of list (&list) = %p\n", &list); //list의 주소 출력

	printf("------------------------------------------------\n");
	printf("value of list[1] = %d\n", list[1]);//list[1]의 값 출력 : 100
	printf("address of list[1] = %p\n", &list[1]); //list[1]의 주소 출력
	printf("value of list+1 = %d\n", *(list+1)); //list+1이 가리키는 곳(=list[1])의 값 출력 : 100
	printf("address of list+1 = %p\n", (list+1)); //list[1]의 주소 출력

	printf("------------------------------------------------\n");
	printf("value of *plist[0] = %d\n", *plist[0]);//plist[0]이 가리키고 있는 곳(heap영역)의 값 출력 : 200
	printf("&plist[0] = %p\n", &plist[0]); //plist[0]의 주소 출력
	printf("&plist = %p\n", &plist); ///plist의 주소 출력
	printf("plist = %p\n", plist); //plist의 주소 출력
	printf("plist[0] = %p\n", plist[0]);
	printf("plist[1] = %p\n", plist[1]);
	printf("plist[2] = %p\n", plist[2]);
	printf("plist[3] = %p\n", plist[3]);
	printf("plist[4] = %p\n", plist[4]);

	free(plist[0]);
}
