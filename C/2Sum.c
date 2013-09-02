/**
 * Check if there are distinct numbers x,y in the input file that satisfy x + y = sum.
 *
 * @author      Bogdan Constantinescu <bog_con@yahoo.com>
 * @since       2013.08.14
 * @version     1.0
 * @link        GitHub    https://github.com/z3ppelin/2Sum
 * @licence     The MIT License (http://opensource.org/licenses/MIT); see LICENCE.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "2Sum.h"

/**
 * Main function. Reads vector, check if there are 2 values that   it, and prints the result.
 * @param     argc       Command line arguments no.
 * @param     argv       Command line arguments.
 * @return               Success/error code. (0 is a success, anything else is error).
 */
int main(int argc, char** argv) {
	printf("------ Begin 2Sum ------\n");
	int n, i, found = 0;
	long long *v, sum, x, y;
	clock_t start, end;
	char error[128];

	/* read vector */
	if (argc == 1) {
		err("Err. The input file must be given as an argument.\n");
	}
	if (!readVectorFromFile(&v, &n, &sum, argv[1], error)) {
		err(error);
	}

	/* print read vector */
	//printf("The read vector is: ");
	//printVector(v, n);
	//printf("\n");
	
	/* start searching for x,y, x != y, so x + y = sum */
	start = clock();
	quickSort(v, 0, n - 1);
	for (i = 0; i < n; i++) {
		if (v[i] != sum - v[i] && -1 != binarySearch(v, 0, n - 1, sum - v[i])) {
			found = 1;
			x = v[i];
			y = sum - v[i];
			break;
		}
	}
	end = clock();

	/* print results */
	if (found) {
		printf("Found %lld + %lld = %lld\n", x, y, sum);
	} else {
		printf("Found no elements with sum %lld\n", sum);
	}

	/* free memory */
	free(v);

	printf("Elapsed: %f seconds.\n", (double) (end - start) / CLOCKS_PER_SEC);
	printf("------- End 2Sum -------\n");
	return EXIT_SUCCESS;
}

/**
 * Prints error and exits program.
 * @param    msg   The error to print.
 */
void err(const char* msg) {
	printf(msg);
	printf("------- End 2Sum -------\n");
	exit(EXIT_FAILURE);
}

/**
 * Recursive function (based on Divide and Conquer algorithm) that sorts a vector (via QuickSort algorithm).
 * @param    v        The vector to sort.
 * @param    left     The left margin of the vector.
 * @param    right    The right margin of the vector.
 */
void quickSort(long long* v, const int left, const int right) {
	if (left < right) {
		int i = partition(v, left, right);
		quickSort(v, left, i - 1);
		quickSort(v, i + 1, right);
	}
}

/**
 * Partition the vector, choose a pivot and arrange all elements lower
 * than it to the left, elements bigger than it to the right.
 *
 * @param    v         The vector to sort.
 * @param    left      The left margin of the vector.
 * @param    right     The right margin of the vector.
 * @return             The pivot position.
 */
int partition(long long* v, const int left, const int right) {
	int i = left + 1, j, pivotPos;
	long long pivot, aux;

	srand(time(NULL));
	pivotPos = (rand() % (right - left)) + left;
	pivot = v[pivotPos];

	/* make the pivot the first element */
	v[pivotPos] = v[left];
	v[left] = pivot;

	for (j = left + 1; j <= right; j++) {
		if (pivot > v[j]) {
			aux = v[j];
			v[j] = v[i];
			v[i] = aux;
			i++;
		}
	}

	/* move the pivot between elements < pivot and elements > pivot */
	v[left] = v[i - 1];
	v[i - 1] = pivot;

	return i - 1;
}

/**
 * Reads array from file.
 * @param      v     The address of the array to store read elements.
 * @param      n     The address of the number of elements array has.
 * @param      sum   The address of the taget sum.
 * @param      file  The file where to read array from.
 * @param      err   An error message, if any occcurred during reading.
 * @return           1 if everything went fine, 0 otherwise. 
 */
int readVectorFromFile(long long** v, int* n, long long *sum, char* file, char* err) {
	FILE *inputFile = fopen(file, "rt");
	int countReadedElements = 0, i = 0;

	if (inputFile == NULL) {
		strcpy(err, "Err. Could not open file.\n");
		return 0;
	}
	if (fscanf(inputFile, "%d", n) != 1) {
		fclose(inputFile);
		strcpy(err, "Err. Could not read number of elements.\n");
		return 0;
	}
	if (fscanf(inputFile, "%lld", sum) != 1) {
		fclose(inputFile);
		strcpy(err,	"Err. Could not read target sum to search for if there are 2 values x + y = sum.\n");
		return 0;
	}
	*v = (long long *) malloc(sizeof(long long) * (*n));
	while (!feof(inputFile)) {
		if (fscanf(inputFile, "%lld", &(*v)[i++]) != 1) {
			break;
		}
		countReadedElements++;
	}
	fclose(inputFile);
	if (countReadedElements != *n) {
		strcpy(err,	"Err. Number of declared elements does not match with the one found in file.\n");
		return 0;
	}
	return 1;
}

/**
 * Prints an array 's elements.
 * @param    v        The vector to print.
 * @param    n        The number of elements vector has.    
 */
void printVector(const long long *v, const int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
}

/**
 * Binary seach algorightm. Searches for a value in a sorted vector in O(log n);
 * @param       v                  The vector to search in.
 * @param       left               The left margin of the vector.
 * @param       right              The right margin of the vector.
 * @param       searchedValue      The searched value.
 * @return                         -1 if the value was not found, otherwise the position in the vector.
 */
int binarySearch(const long long *v, const int left, const int right, const long long searchedValue) {
	if (right < left) {
		return -1;
	}
	int middle = (right + left) / 2;
	if (searchedValue == v[middle]) {
		return middle;
	} else if (v[middle] < searchedValue) {
		return binarySearch(v, middle + 1, right, searchedValue);
	} else {
		return binarySearch(v, left, middle - 1, searchedValue);
	}
}
