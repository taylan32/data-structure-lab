#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

Node* head = NULL;

void push(int x);
void pop();
void printStack();

int main(void) {

	int choice = 0, data;

	while (choice != 4) {
		printf("\n1-Push\n2-Pop\n3-Print\n4-Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter the data to be pushed: ");
			scanf("%d", &data);
			push(data);
			break;
		case 2:
			pop();
			break;
		case 3:
			printStack();
			break;
		case 4:
			printf("Press any key to exit.\n");
			break;
		default:
			printf("\Invalid choice.\n");
			break;
		}
	}

	return 0;
}

void push(int x) {

	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
	}
	else {
		Node* temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	
	printf("\nOne node pushed\n");
}

void pop() {

	if (head == NULL) {
		printf("\nStack is empty\n");
	}
	else {
		if (head->next == NULL) {
			head = NULL;
		}
		else {
			Node* temp = head;
			Node* prev = head;

			while (temp->next->next != NULL) {
				temp = temp->next;
				prev = prev->next;
			}
			temp = temp->next;
			prev->next = NULL;
			free(temp);
		}
		printf("\nOne node popped\n");
	}

	

}
void printStack() {
	if (head == NULL) {
		printf("\nStack is empty\n");
	}
	else {
		printf("Stack:\n");
		Node* temp = head;
		while (temp != NULL) {
			printf("%d\t", temp->data);
			temp = temp->next;
		}
	}
}