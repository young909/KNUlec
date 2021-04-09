#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

typedef struct __queue {
	int data;
	struct __queue* next;
}queue;

queue* front;
queue* back;

int main(void) {
	int n;
	int size = 0;
	scanf("%d", &n);
	while (n--) {
		char op[10];
		scanf("%s", op);
		if (!strcmp(op, "push")) {
			int input;
			scanf("%d", &input);
			queue* newEl = (queue*)malloc(sizeof(queue));
			newEl->data = input;
			newEl->next = NULL;

			if (size == 0) {
				front = newEl;
				back = newEl;
			}
			else {
				back->next = newEl;
				back = newEl;
			}
			size++;
		}
		else if (!strcmp(op, "pop")) {
			if (size == 0)
				printf("-1\n");
			else {
				queue* temp = front;
				front = front->next;
				printf("%d\n", temp->data);
				free(temp);
				size--;
			}
		}
		else if (!strcmp(op, "size")) {
			printf("%d\n", size);
		}
		else if (!strcmp(op, "empty")) {
			if (size == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if(!strcmp(op, "front")){
			if (size == 0)
				printf("-1\n");
			else {
				printf("%d\n", front->data);
			}
		}
		else {
			if (size == 0)
				printf("-1\n");
			else {
				printf("%d\n", back->data);
			}
		}
	}

	return 0;
}