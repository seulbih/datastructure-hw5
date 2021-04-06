/*
 * circularQ.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct { //queue 구성요소 구조체로 정의
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue();
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
int enQueue(QueueType *cQ, element item);
int deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);
element getElement();

int main(void)
{


	QueueType *cQ = createQueue();
	element data;
	char command;

	do{
		printf("[----- [황슬비] [2018032027] -----]");
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		fflush(stdout);
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement(); //큐에 넣을 값 입력
			enQueue(cQ, data); //큐에 삽입
			break;
		case 'd': case 'D':
			deQueue(cQ, &data); //큐에서 삭제
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
   	        freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 1;
}

QueueType *createQueue() //큐 생성
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

int freeQueue(QueueType *cQ) //큐 할당 해제
{
    if(cQ == NULL) return 1;
    free(cQ);
    return 1;
}

element getElement()
{
	element item;
	printf("Input element = ");
	fflush(stdout);
	scanf(" %c", &item);



	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ)
{

		if(cQ->front==cQ->rear){ //front와 rear값이 같으면 1반환 (true)
			return 1;
		}
    return 0;
}

/* complete the function */
int isFull(QueueType *cQ)
{

	if(cQ->front==cQ->rear){//rear+1한 후, front와 rear가 같으면 full, 1반환
		return 1;
			}
   return 0;
}


/* complete the function */
int enQueue(QueueType *cQ, element item)
{
	cQ->rear = (cQ->rear+1)%MAX_QUEUE_SIZE; //rear +1, 나머지연산
	int ls;
	ls=isFull(cQ);
	if(ls==1){
		printf("Queue is Full!\n");
	}
	else{ //full이 아닐 때

	cQ->queue[cQ->rear] = item;//큐에 데이터 삽입
	}
	return 0;
}

/* complete the function */
int deQueue(QueueType *cQ, element *item)
{
	int ls;
	ls=isEmpty(cQ);
	if(ls==1){ //큐가 비었는지
		printf("Queue is Empty!\n");
	}
	else{
		return cQ->queue[cQ->front=(cQ->front+1)%MAX_QUEUE_SIZE]; //front 한칸 증가시켜 값 삭제, front는 빈 곳를 가리키게 됨
	}
	return 0;
}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}

