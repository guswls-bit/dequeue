#include<stdio.h>
#include<stdlib.h>
typedef struct dequeue {
	int* data;
	int max;
	int stack_Point;
	int queue_Point;
}dequeue;
int size = 10;
void init(dequeue* dq);
void push_top(dequeue* dq,int value);
void push_bottom(dequeue* dq,int value);

int pop_top(dequeue* dq);
int pop_bottom(dequeue* dq);

int de_print(dequeue* dq);
int Isempty(dequeue* dq);
int dequeuesize(dequeue* dq);
int main() {

}

void init(dequeue* dq) {
	dq->data = (int*)malloc(sizeof(int) * size);
	dq->max = size;
	dq->stack_Point = -1;
	dq->queue_Point = -1;
}

void push_top(dequeue* dq, int value) {
	if (dq->stack_Point < dq->max-1) {
		dq->data[++dq->stack_Point] = value;
	}
	else {
		dq->max += 10;
		(int*)realloc(dq->data, sizeof(int) * dq->max);
		dq->data[++dq->stack_Point] = value;
	}
}
void push_bottom(dequeue* dq,int value) {
	if (dq->queue_Point == -1) {
		dq->max += size;
		dq->queue_Point = 10;
		(int*)realloc(dq->data, sizeof(int) * dq->max);
		for (int i = 0; i < dq->stack_Point; i++) {
			dq->data[dq->stack_Point - i + 10] = dq->data[dq->stack_Point - i];
		}
		dq->data[--dq->queue_Point] = value;
	}
	else {
		dq->data[--dq->queue_Point] = value;
	}
}

int pop_top(dequeue* dq) {
	if(Isempty(dq)){
		printf("NO DeQUEUEU\n");
		return -1;
	}
	printf("%d\n", dq->data[dq->stack_Point--]);
	return 0;
}
int pop_bottom(dequeue* dq) {
	if (Isempty(dq)) {
		printf("NO QUEUE\n");
		return -1;
	}
	if (dq->queue_Point == size - 1) {
		dq->max -= size;
		dq->queue_Point -= size;
		for (int i = 0; i < dequeuesize(dq); i++) {
			dq->data[i] = dq->data[i + size];
		}
		(int*)realloc(dq->data, sizeof(int) * dq->max);
		dq->queue_Point = -1;
	}
	printf("%d\n", dq->data[++dq->queue_Point]);
}

int de_print(dequeue* dq) {
	if (Isempty(dq)) {
		printf("NO DEQUEUE\n");
		return -1;
	}
	for (int i = dq->queue_Point; i < dq->stack_Point; i++) {
		printf("%d\n", dq->data[i+1]);
	}
	return 0;
}
int Isempty(dequeue* dq) {
	return dq->stack_Point == dq->queue_Point;
}
int dequeuesize(dequeue* dq) {
	return dq->stack_Point - dq->queue_Point;
}