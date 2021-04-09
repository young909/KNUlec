#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct NODE {
	int data;
	struct NODE* next;
}NODE;

void addFirst(NODE** head, int data) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

int main(void) {
	NODE* head = NULL;

	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		addFirst(&head, input);
	}
	
	if (head) {
		NODE* temp = head;
		head = head->next;
		printf("%d", temp->data);
		free(temp);
	}
	
	while (head != NULL) {
		NODE* temp = head;
		printf(" -> ");
		printf("%d", temp->data);
		head = head->next;
		free(temp);
	}

	return 0;
}