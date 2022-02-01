#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* PROTOTYPES */
void addNumbers(int arr[], int size); // A function to add the numbers to the array
void printArray(int arr[], int size); // A function to print the array
void getInput(int* k); // A function to get an input from user
int binarySearch(int arr[], int size, int key); // a function to search the key
void insertionSort(int arr[], int size); // a function to sort the array

int main(void) {

	int numbers[10];
	int size = sizeof(numbers) / sizeof(numbers[0]);
	addNumbers(numbers, size);
	printf("Numbers:\n");
	insertionSort(numbers, size);
	printArray(numbers, size);
	int keyToBeSearched;
	getInput(&keyToBeSearched);
	int result = binarySearch(numbers, size, keyToBeSearched);

	if (result != -1) // the element exists
		printf("%d fount at index %d", keyToBeSearched, result+1);
	else
		printf("%d not found", keyToBeSearched);

	return 0;
}

void addNumbers(int arr[], int size) {

	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

void getInput(int* k) {
	printf("Enter the number to be searched: ");
	scanf("%d", &*k);
}

void insertionSort(int arr[], int size) {
	int i, j, key;

	for (i = 1; i < size; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && key<=arr[j]; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

int binarySearch(int arr[], int size, int key) {

	int left = 0;
	int right = size - 1;
	int middle;

	while (left < right) { // a loop to find the correct index;
		middle = (left + right) / 2;
		if (key == arr[middle])
			return middle;
		else if (key > arr[middle])
			left = middle + 1;
		else
			right = middle - 1;
	} // end while

	return -1;
}