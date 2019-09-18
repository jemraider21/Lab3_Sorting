/*  
	Jared Morris
	Lab 3
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void reset(const int[], const int *ptr[], int);
void displayIntArray(const int num[], int size);
void displayPtrArray(const int *ptr[], int size);
void displayPtrArrayDeref(const int *ptr[], int size);
void BubbleSort(const int *ptr[], int size);
void SelectionSort(const int *ptr[], int size);
void InsertionSort(const int *ptr[], int size);

int main() {
	const int SIZE = 4;
	const int numbers[SIZE] = { 20, 40, 10, 30 };
	const int *ptr[SIZE];

	for (int i = 0; i < 3; i++) {
		//call reset
		reset(numbers, ptr, SIZE);

		cout << "\nHere is the content of the array in the ORIGINAL order: \n";
		//call displayIntArray
		displayIntArray(numbers, SIZE);

		cout << "\nHere is the content of the array of pointers in the ORIGINAL order: \n";
		//call displayPtrArray
		displayPtrArray(ptr, SIZE);

		switch (i) {
			case 0:
				cout << "\n\n\nSORTING -  Bubble Sort\n";
				/* call BubbleSort */
				BubbleSort(ptr, SIZE);
				break;
			case 1:
				cout << "\n\n\nSORTING -  Selection Sort\n";
				/* call SelectionSort */
				SelectionSort(ptr, SIZE);
				break;
			case 2:
				cout << "\n\n\nSORTING -  Insertion Sort\n";
				/* call InsertionSort */
				InsertionSort(ptr, SIZE);
				break;
		}

		cout << "\nSorting complete\n";
		cout << "\nHere is the content of the sorted array of pointers: \n";
		/* call displayPtrArray */
		displayPtrArray(ptr, SIZE);

		cout << "\nHere is the content of the sorted array of pointers dereferenced: \n";
		/* call displayPtrArrayDeref */
		displayPtrArrayDeref(ptr, SIZE);
		cout << "-----------------------------------------------------------------------\n";
		
		//system("pause"); 
	}

	cout << "\nDone by Jared Morris\n";
	system("pause");
	return 0;
}


/*  1. Assign each int element address to elements of the array of int pointers in such a way
that the address of the first element in the int array is assigned to the first element of the pointer array,
the address of the second element in the int array is assigned to the second element of the pointer array, and so on.
*/
void reset(const int start_num[], const int *ptr[], int size)
{
	for (int i = 0; i < size; i++) {
		ptr[i] = &start_num[i];
	}
}

/* 2. use a loop to display the content of the num array */
void displayIntArray(const int num[], int size) {
	for (int i = 0; i < size; i++) {
		printf("\t %i", num[i]);
	}
	cout << endl;
}

void displayPtrArray(const int *ptr[], int size) {
	/* use a loop to display the content of the ptr array (showing addresses) */
	for (int i = 0; i < size; i++) {
		cout << "\t " << ptr[i];
	}
	cout << endl;
}

void displayPtrArrayDeref(const int *ptr[], int size) {
	/* use a loop to display the content of the ptr array dereferenced (showing values) */
	for (int i = 0; i < size; i++) {
		cout << "\t " << *ptr[i];
	}
	cout << endl;
}

/*
3. Bubble sort function will be called which will use the bubble sort technique
to sort the content of the pointer array such that
when you iterate through the  array and print out its content,
the integers will be in descending sorted order.

Every time you change the content of the elements of the array,
print out the entire array by calling the displayPtrArrayDeref function.
But only display the contents when the N elements in the array has changed.
*/
void BubbleSort(const int *ptr[], int size) {
	/* Most of the code is provided for you.  Additional code or modifications may be
	*  necessary. You will also need to make sure that the bubble sort is sorting in
	*  ASCENDING order (low to high)
	*/

	bool swap;
	const int *temp = 0;

	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (*ptr[count] > *ptr[count + 1]) {
				temp = ptr[count];
				ptr[count] = ptr[count + 1];
				ptr[count + 1] = temp;
				swap = true;
				displayPtrArrayDeref(ptr, size);
			}
		}
	} while (swap);
}

/*
4.  You will repeat the same steps for Selection sort (the code for the function is given)

Every time you change the content of the elements of the pointer array,
print out the entire pointer array by calling the displayPtrArrayDeref function.
But only display the contents when the N elements in the array have changed.
*/
void SelectionSort(const int *ptr[], int size) {
	/* Most of the code is provided for you.  Additional code or modifications may be
	*  necessary. You will also need to make sure that the selection sort is sorting in
	*  ASCENDING order (low to high)
	*/

	int startScan = 0;
	int maxIndex = 0;
	const int *maxValue = nullptr;

	for (startScan = 0; startScan < (size - 1); startScan++) {
		maxIndex = startScan;
		maxValue = ptr[startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (*ptr[index] < *maxValue) {
				maxValue = ptr[index];
				maxIndex = index;
			}
		}
		//const int *temp = ptr[maxIndex];
		ptr[maxIndex] = ptr[startScan];
		ptr[startScan] = maxValue;

		displayPtrArrayDeref(ptr, size);
	}
}

/*
5. You will repeat the same steps for  Insertion sort.

Every time you change the content of the elements of the pointer array,
print out the entire pointer array by calling the displayPtrArrayDeref function.
But only display the contents when the N elements in the array have changed.
*/
void InsertionSort(const int *ptr[], int size) {

	/* Most of the code is provided for you.  Additional code or modifications may be
	*  necessary. You will also need to make sure that the insertion sort is sorting in
	*  ASCENDING order (low to high)
	*/

	for (int i = 1; i < size; i++) {
		int j = i - 1;
		const int *current = ptr[i];

		for (j = i - 1; j >= 0 && *ptr[j] > *current; j--) {
			ptr[j + 1] = ptr[j];
		}

		ptr[j + 1] = current;
		displayPtrArrayDeref(ptr, size);
	}
}