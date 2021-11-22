#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
	int* data;
	int Point;
	int max;
}stack;
int size = 10;
void StackPush(stack* st,int value);
int StackPop(stack* st);
void init(stack* st);
int Isempty(stack* st);
int StackPick(stack* st);
int StackPrint(stack* st);
int StackSize(stack* st);

int main() {
	stack st;
	init(&st);
	StackPush(&st,1);
	StackPush(&st,2);
	StackPush(&st,3);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPrint(&st);
	StackPop(&st);
	StackPop(&st);
	StackPick(&st);
	StackPop(&st);
	free(st.data);
}
void init(stack* st) {
	st->data = (int*)malloc(size * sizeof(int));
	st->max = size;
	st->Point = -1;
}

void StackPush(stack* st,int value) {
	if (st->Point < st->max-1) {
		st->data[++st->Point] = value;
	}
	else {
		st->max += 10;
		(int*)realloc(st->data, sizeof(int) * st->max);
		st->data[++st->Point] = value;
	}
}
int StackPop(stack* st) {
	if (Isempty(st)) {
		printf("No stack\n");
		return -1;
	}
	printf("%d\n", st->data[st->Point--]);
	return 0;
}
int StackPick(stack* st) {
	if (Isempty(st)) {
		printf("No stack\n");
		return -1;
	}
	printf("%d\n", st->data[st->Point]);
	return st->data[st->Point];
}
int StackPrint(stack* st) {
	if (Isempty(st)) {
		printf("No stack\n");
		return -1;
	}
	for (int i = 0; i < StackSize(st); i++) {
		printf("%d\n", st->data[st->Point - i]);
	}
}
int StackSize(stack* st) {
	return st->Point + 1;
}

int Isempty(stack* st) {
	return st->Point == -1;
}
