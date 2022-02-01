#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data;
	struct node* next;

}Node;

Node* rear = NULL;
Node* front = NULL;

void enqueue(int x);
void dequeue();
void printQueue();

int main(void) {

	int choice = 0, data;
	while (choice != 4) {
		printf("\n1-Enqueue\n2-Dequeue\n3-Print\n4-Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter the data to be enqueued: ");
			scanf("%d", &data);
			enqueue(data);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			printQueue();
			break;
		case 4:
			printf("Press any key to exit.\n");
			break;
		default:
			printf("Invalid choice.\n");
			break;
		}
	}

	return 0;
}

void enqueue(int x) {

	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;

	if (front == NULL) {
		front = newNode;
		rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = rear->next;
	}

	printf("\One node enqueued\n");
}

void dequeue() {
	if (front == NULL) {
		printf("\nQueue is empty\n");
	}
	else {
		if (front->next == NULL) { // one item on the queue
			front= NULL;
			rear = NULL;
		}
		else {
			Node* temp = front;
			front = front->next;
			free(temp);
		}

		printf("\nOne node dequeued\n");
	}
}

void printQueue() {

	if (front == NULL) {
		printf("\nQueue is empty\n");
	}
	else {
		Node* temp = front;
		printf("%d\t", temp->data);
		while (temp != rear) {
			temp = temp->next;
			printf("%d\t", temp->data);
			
		}

	}
}

/*
 // tail tutmak gerekmiyor.
#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data;
	struct node* next;

}Node;

Node* front = NULL;

void enqueue(int x);
void dequeue();
void printQueue();

int main(void) {

	int choice = 0, data;
	while (choice != 4) {
		printf("\n1-Enqueue\n2-Dequeue\n3-Print\n4-Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter the data to be enqueued: ");
			scanf("%d", &data);
			enqueue(data);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			printQueue();
			break;
		case 4:
			printf("Press any key to exit.\n");
			break;
		default:
			printf("Invalid choice.\n");
			break;
		}
	}

	return 0;
}

void enqueue(int x) {

  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = NULL;
  if(front == NULL){
	front = newNode;
  }
  else{
	Node* temp = front;

	while(temp->next!=NULL){
	  temp=temp->next;
	}
	temp->next = newNode;
  }

}

void dequeue() {
	if(front == NULL){
	printf("\nQueue is empty\n");
  }
  else{
	if(front->next == NULL){ // one item on the queue
	  front = NULL;
	}
	else{
	  Node* temp = front;
	  front=front->next;
	  free(temp);
	}
  }
}

void printQueue() {

  if(front==NULL){
	printf("\nQueue is empty\n");
  }
  else{
	Node* temp = front;
	while(temp!=NULL){
	  printf("%d\t",temp->data);
	  temp = temp->next;
	}
  }

}
*/