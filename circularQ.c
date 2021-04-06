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
typedef struct { //queue ������� ����ü�� ����
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
		printf("[----- [Ȳ����] [2018032027] -----]");
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
			data = getElement(); //ť�� ���� �� �Է�
			enQueue(cQ, data); //ť�� ����
			break;
		case 'd': case 'D':
			deQueue(cQ, &data); //ť���� ����
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

QueueType *createQueue() //ť ����
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

int freeQueue(QueueType *cQ) //ť �Ҵ� ����
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

		if(cQ->front==cQ->rear){ //front�� rear���� ������ 1��ȯ (true)
			return 1;
		}
    return 0;
}

/* complete the function */
int isFull(QueueType *cQ)
{

	if(cQ->front==cQ->rear){//rear+1�� ��, front�� rear�� ������ full, 1��ȯ
		return 1;
			}
   return 0;
}


/* complete the function */
int enQueue(QueueType *cQ, element item)
{
	cQ->rear = (cQ->rear+1)%MAX_QUEUE_SIZE; //rear +1, ����������
	int ls;
	ls=isFull(cQ);
	if(ls==1){
		printf("Queue is Full!\n");
	}
	else{ //full�� �ƴ� ��

	cQ->queue[cQ->rear] = item;//ť�� ������ ����
	}
	return 0;
}

/* complete the function */
int deQueue(QueueType *cQ, element *item)
{
	int ls;
	ls=isEmpty(cQ);
	if(ls==1){ //ť�� �������
		printf("Queue is Empty!\n");
	}
	else{
		return cQ->queue[cQ->front=(cQ->front+1)%MAX_QUEUE_SIZE]; //front ��ĭ �������� �� ����, front�� �� ���� ����Ű�� ��
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

