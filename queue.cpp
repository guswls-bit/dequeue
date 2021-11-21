#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
	int* data;
	int max;
	int Point;
	int bottom;
}qu;
int size = 10;
void init(queue* qu);
void queuepush(queue* qu,int value);
int queuepop(queue* qu);
int queueempty(queue* qu);
int queuesize(queue* qu);
int queueprint(queue* qu);
int queuebottom(queue* qu);
int main() {
	qu qu;
	init(&qu);
	queuepush(&qu, 1);
	queuepush(&qu, 2);
	queuepush(&qu, 3);
	queuepush(&qu, 4);
	queuepush(&qu, 5);
	queuepush(&qu, 6);
	queuepush(&qu, 7);
	queueprint(&qu);
	queuepush(&qu, 8);
	queuepush(&qu, 9);
	queuepush(&qu, 10);
	queuepush(&qu, 11);
	queuepush(&qu, 12);
	queuepush(&qu, 13);
	queuepush(&qu, 14);
	printf("%d\n",queuesize(&qu));
	queuepop(&qu);
	queuebottom(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	queuepop(&qu);
	free(qu.data);
}

void init(queue* qu) {
	qu->data = (int*)malloc(size * sizeof(int));
	qu->max = size;
	qu->Point = -1;
	qu->bottom = -1;
}

void queuepush(queue* qu, int value) {
	if (qu->Point > qu->max-2) {
		qu->max += 10;
		(int*)realloc(qu->data, sizeof(int) * qu->max);
		qu->data[++qu->Point] = value;

	}
	else {
		qu->data[++qu->Point] = value;
	}
}
int queuepop(queue* qu) {
	if (queueempty(qu)) {
		printf("NO QUEUE");
		return -1;
	}
	if (qu->bottom == size - 1) {
		qu->max -= size;
		qu->Point -= size;
		for (int i = 0; i < queuesize(qu); i++) {
			qu->data[i] = qu->data[i + size];
		}
		(int*)realloc(qu->data, sizeof(int) * qu->max);
		qu->bottom = -1;
	}
	printf("%d\n", qu->data[++qu->bottom]);
}
int queueprint(queue* qu) {
	if (queueempty(qu)) {
		printf("NO QUEUE");
		return -1;
	}
	for (int i = 0; i < queuesize(qu); i++) {
		printf("%d\n", qu->data[queuesize(qu) - i-1]);
	}
}
int queuebottom(queue* qu) {
	if (queueempty(qu)) {
		printf("NO QUEUE");
		return -1;
	}
	printf("%d\n", qu->data[qu->bottom+1]);
	return qu->data[qu->bottom];
}

int queueempty(queue* qu) {
	return qu->bottom == qu->Point;
}
int queuesize(queue* qu) {
	return qu->Point-qu->bottom;
}