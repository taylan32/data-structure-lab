#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
	struct node* previous;
}Node;

Node* head = NULL;
Node* tail = NULL;

void insertAtBeginning(int);
int isEmpty();
void printList();
void insertAtEnd(int);
void removeFromBeginning();
void removeFromEnd();

int main(void) {

	int choice = 0;
	int data;
	while (choice != 4) {
		printf("\n1-Insert\n2-Delete\n3-Show\n4-Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1: {
			printf("Enter the value to be inserted: ");
			scanf("%d", &data);
			printf("1-Insert at beginning\n2-Insert end\n");
			printf("Where do you want to insert?: ");
			scanf("%d", &choice);
			if (choice == 1)  // Insert at beginning
				insertAtBeginning(data);
			else  // insert at end
				insertAtEnd(data);
			break;
		} // end case 1
		case 2: {
			printf("1-Remove from beginning\n2-Remove from end\n");
			printf("Enter your choice: ");
			scanf("%d", &choice);
			if (choice == 1) // from beginning
				removeFromBeginning();
			else // from end
				removeFromEnd();
			break;
		} // end case 2
		case 3: {
			printList();
			break;
		} // end case 3
		case 4:
			printf("Press any key to exit");
			break;

		default:
			printf("Invalid choice");
			break;
		} // end switch
		
	} // end while


	return 0;
}

int isEmpty() {

	if (head == NULL)
		return 1;
	else
		return 0;
}

void printList() {
	
	if (isEmpty()) {// list is empty
		printf("List is empty");
	}
	else { // list  is not empty
		Node* temp = head;
		
		printf("List:\n");
		while (temp->next != head) {
			printf("\nprev=%u\t%d\taddress=%u\tnext=%u\t", temp->previous, temp->data, temp, temp->next);
			temp = temp->next;
		}
		printf("\nprev=%u\t%d\taddress=%u\tnext=%u\t", temp->previous, temp->data, temp, temp->next);
	}
}

void insertAtBeginning(int x) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	
	if (isEmpty()) { // List is empty
		head = newNode;
		tail = newNode;
		head->next = tail;
		head->previous = tail;
		tail->next = head;
		tail->previous = head;
	}
	else { // list is not empty
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
		tail->next = head;
		head->previous = tail;
	}

	printf("One node inserted\n");
}

void insertAtEnd(int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;

	if (isEmpty()) { // list is empty
		head = newNode;
		tail = newNode;
		head->next = tail;
		head->previous = tail;
		tail->next = head;
		tail->previous = head;
	}
	else { // list is not empty
		tail->next = newNode;
		newNode->previous = tail;
		tail = newNode;
		tail->next = head;
		head->previous = tail;
	}

	printf("\nOne node inserted\n");
}

void removeFromBeginning() {
	
	if (isEmpty()) {
		printf("List is not empty\n");
	}
	else { // list is not empty

		Node* temp = head;
		if (head->next == head) { // one item on the list
			head = NULL;
			tail = NULL;
		}
		else { // more than one item on the list
			head = head->next;
			head->previous = tail;
			tail->next = head;
		}
		printf("\nOne node removed\n");
		free(temp);
	}	
}

void removeFromEnd() {
	
	if (isEmpty()) {
		printf("List is empty\n");
	}
	else {
		Node* temp = tail;
		if (head->next == head) { // one item on the list
			head = NULL;
			tail = NULL;
		}
		else { // more than one item on the list
			tail = tail->previous;
			tail->next = head;
			head->previous = tail;
		}
		free(temp);
		printf("\nOne node removed\n");
	}

}