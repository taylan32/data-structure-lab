#include <stdio.h>
#include <stdlib.h>

typedef struct bTree {
	int value;
	struct bTree* left;
	struct bTree* right;
}BTREE;

BTREE* root = NULL;

/* prototypes */
void insert(BTREE* treeRoot, BTREE* newNode);
void traversePre(BTREE* treeRoot);
void traverseIn(BTREE* treeRoot);
void traversePost(BTREE* treeRoot);
BTREE* search(BTREE* treeRoot, int item);
BTREE* Delete(BTREE* treeRoot, int item);
BTREE* readNode();
int countNodes(BTREE* treeRoot, int sum);
int getRightMin(BTREE* treeRoot);

int main(void) {

	int choice = 0;
	BTREE* n, * node;
	int count = 0;
	int item;

	while (choice != 6) {
		printf("\n------------------\n"
			"1-Insert a node\n"
			"2-Delete a node\n"
			"3-List nodes\n"
			"4-Search for a node\n"
			"5-Count the number of nodes\n"
			"6-Exit\n"
			"Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1: // insert a node
			n = readNode();
			insert(root, n);
			break;
		case 2: // delete a node
			printf("Enter the item to be deleted: ");
			scanf("%d", &item);
			node = Delete(root, item);
			if (node != NULL) {
				printf("%d deleted.\n", item);
			}
			else {
				printf("%d is not found.\n", item);
			}

			break;
		case 3: // traverse
			if (root == NULL) {
				printf("Tree is empty.\n");
			}
			else {
				printf("Pre-order:  ");
				traversePre(root);
				printf("\nIn-order:   ");
				traverseIn(root);
				printf("\nPost-order: ");
				traversePost(root);
				printf("\n");
			}
			break;
		case 4: // search for item
			printf("Enter the item to be searched: ");
			scanf("%d", &item);
			node = search(root, item);
			if (node == NULL) {
				printf("%d not found.\n", item);
			}
			else {
				printf("%d is found.\n", item);
			}
			break;
		case 5:  // count the number of nodes
			count = countNodes(root, 0);
			printf("Number of nodes in the tree is %d\n", count);
			break;
		case 6: // exit
			printf("Press any key to exit\n");
			break;
		default:
			printf("Invalid choice.\n");
			break;
		}
	}

	return 0;
}

BTREE* readNode() {

	BTREE* newNode = (BTREE*)malloc(sizeof(BTREE));

	if (newNode == NULL) {
		printf("No memory.\n");
		return NULL;
	}

	printf("Enter a value: ");
	scanf("%d", &(newNode->value));

	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void insert(BTREE* treeRoot, BTREE* newNode) {
	if (treeRoot == NULL) { // tree is empty
		root = newNode;
	}
	else {
		if (newNode->value < treeRoot->value) { // add to left
			if (treeRoot->left == NULL) {
				treeRoot->left = newNode;
			}
			else {
				insert(treeRoot->left, newNode);
			}
		}
		else { // add to right
			if (treeRoot->right == NULL) {
				treeRoot->right = newNode;
			}
			else {
				insert(treeRoot->right, newNode);
			}
		}
	}
}

// root - left - right
void traversePre(BTREE* treeRoot) {
	if (treeRoot != NULL) {
		printf("%d\t", treeRoot->value);
		traversePre(treeRoot->left);
		traversePre(treeRoot->right);
	}
}

// left - right - root
void traversePost(BTREE* treeRoot) {
	if (treeRoot != NULL) {
		traversePost(treeRoot->left);
		traversePost(treeRoot->right);
		printf("%d\t", treeRoot->value);
	}
}

//left - root - right
void traverseIn(BTREE* treeRoot) {

	if (treeRoot != NULL) {
		traverseIn(treeRoot->left);
		printf("%d\t", treeRoot->value);
		traverseIn(treeRoot->right);
	}
}

BTREE* search(BTREE* treeRoot, int item) {

	while ((treeRoot != NULL) && (treeRoot->value != item)) {
		if (item < treeRoot->value) {
			treeRoot = treeRoot->left;
		}
		else {
			treeRoot = treeRoot->right;
		}
	}
	return treeRoot;
}

int countNodes(BTREE* treeRoot, int sum) {
	if (treeRoot == NULL) {
		return sum;
	}
	sum++;
	sum = countNodes(treeRoot->left, sum);
	sum = countNodes(treeRoot->right, sum);
	return sum;
}

int getRightMin(BTREE* treeRoot) {
	BTREE* temp = treeRoot;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp->value;
}

BTREE* Delete(BTREE* treeRoot, int item) {
	if (treeRoot == NULL) {
		return NULL;
	}
	 
	if (item < treeRoot->value) {
		treeRoot->left = Delete(treeRoot->left, item);
	}
	else if (item > treeRoot->value) {
		treeRoot->right = Delete(treeRoot->right, item);
	}
	else {
		if (treeRoot->left == NULL && treeRoot->right == NULL) {
			free(treeRoot);
			return NULL;
		}
		else if (treeRoot->left == NULL) {
			// has only right child
			BTREE* temp = treeRoot->right;
			free(treeRoot);
			return temp;
		}
		else if (treeRoot->right == NULL) {
			// has only left child
			BTREE* temp = treeRoot->left;
			free(treeRoot);
			return  temp;
		}
		else {
			int rightMin = getRightMin(treeRoot->right);
			treeRoot->value = rightMin;
			treeRoot->right = Delete(treeRoot->right, rightMin);
		}
	}
	return treeRoot;
	
}