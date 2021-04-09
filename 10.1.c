#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct Node* listPointer;
typedef struct Node {
	int data;
	struct Node* link;
}Node;

listPointer invert(listPointer lead)
{
	listPointer middle, trail;
	middle = NULL;
	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}
	return middle;
}

listPointer addNode(listPointer list, int input) {
	listPointer ptr;
	ptr = list;
	listPointer temp;

	temp = (Node*)malloc(sizeof(Node));
	temp->data = input;
	temp->link = NULL;

	if (list == NULL) {
		list = temp;
		return list;
	}

	while (ptr->link != NULL)
		ptr = ptr->link;

	ptr->link = temp;
	return list;
}

void printList(const listPointer list) {
	listPointer ptr;
	ptr = list;
	while (ptr) {
		printf("%d\n", ptr->data);
		ptr = ptr->link;
	}
}

int main(void)
{
	listPointer list = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		list = addNode(list, input);
	}
	list = invert(list);
	printList(list);

	return 0;
}