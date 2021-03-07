#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* head;
Node* tail;

int a = 0;

void addNP(Node* node) {
	Node* aPNode = (Node*)malloc(sizeof(Node));
	aPNode->data = a++;
	aPNode->pre = node->pre;
	aPNode->next = node;
	(node->pre)->next = aPNode;
	node->pre = aPNode;
	printf("addNP()\n");
}

void addNN(Node* node) {
	Node* aPNode = (Node*)malloc(sizeof(Node));
	aPNode->data = a++;
	aPNode->pre = node;
	aPNode->next = node->next;
	(node->next)->pre = aPNode;
	node->next = aPNode;
	printf("addNN()\n");
}

void removeNP(Node* node) {
	Node* temp = (node->pre)->pre;
	temp->next = node;
	free(node->pre);
	node->pre = temp;
	printf("removeNP()\n");
}

void removeNN(Node* node) {
	Node* temp = (node->next)->next;
	temp->pre = node;
	free(node->next);
	node->next = temp;
	printf("removeNN()\n");
}

void freeAll(Node* head) {
	Node* temp = head->next;
	while (temp != NULL) {
		free(temp->pre);
		temp = temp->next;
	}
	free(tail);
	printf("freeAll()\n");
}

void showAll(Node* head) {
	Node* temp = head->next;
	while (temp != NULL) {
		printf("data : %d\n", (temp->pre)->data);
		temp = temp->next;
	}
	printf("data : %d\n", tail->data);
	printf("showAll()\n");
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->pre = NULL;
	head->next = tail;
	head->data = -1;
	tail->pre = head;
	tail->next = NULL;
	tail->data = -2;
	addNN(head);
	addNN(head);
	addNN(head);
	addNN(head);
	addNP(tail);
	removeNP(tail);
	removeNN(head);
	showAll(head);
	freeAll(head);
	system("pause");
}