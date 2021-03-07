#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* under;
}Node;

Node* top;
int a = 0;

void add(Node* top) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = top->data;
	node->under = top->under;
	top->data = a++;
	top->under = node;
	printf("add()\n");
}

void pop(Node* top) {
	Node* temp = top->under;
	//Node* temp2 = top;
	//free(temp);
	free(top);
	top->data = temp->data;
	top->under = temp->under;
	printf("topdata : %d, topunder : %d\n", top->data, top->under);
	printf("pop()\n");
}

void showAll(Node* top) {
	//Node* temp = (Node*)malloc(sizeof(Node));
	Node* temp = top;
	printf("tdata : %d, tunder : %d\n", temp->data, temp->under);
	while (temp->under != NULL) {
		printf("data : %d\n", temp->data);
		temp = temp->under;
	}
	printf("data : %d\n", temp->data);
}

int main(void) {
	top = (Node*)malloc(sizeof(Node));
	top->data = -1;
	top->under = NULL;
	add(top);
	add(top);
	add(top);
	add(top);
	add(top);
	add(top);
	pop(top);
	printf("topdata : %d, topunder : %d\n", top->data, top->under);
	showAll(top);
	system("pause");
}