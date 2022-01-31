/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author: 
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void heapSort(struct Employee *A, int n)
{
	//TODO - BuildHeap on the list
	buildHeap(A, n);
	//TODO - while n > 0:
		//TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
		//TODO - A[n-1] now sorted in place!
		//TODO - So decrement n
		//TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
	while (n > 0) {
		//swap A[n-1] with A[0]
		swap(&A[0], &A[n - 1]);
		//heapify the elements
		heapify(A, 0, (n - 1));
		//drecrement n
		--n;
	}
}


/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void buildHeap(struct Employee *A, int n)
{
	//TODO - heapify() every element from A[n/2] to A[0]
	int idx = n / 2;
	while(idx >= 0) {
		//heapify the idx
		heapify(A, idx, n);
		//work down to 0
		--idx;
	}
}


/**
 * We want to start with A[i] and trickle it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the list
 */
void heapify(struct Employee *A, int i, int n)
{
	//TODO - get index of left child of element i
	//TODO - get index of right child of element i

	int left_child = 2 * (i + 1) - 1;
	int right_child = 2 * (i + 1);

	//TODO - determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"
	//TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
	//TODO - Continue recursion as long as i is within range AND either right_child and left_child are still within range.
	while (i < n - 1) {
		int smaller;
		if(left_child <= (n - 1) && right_child <= (n - 1)) {
			if(A[left_child].salary < A[right_child].salary) {
				smaller = left_child;
			}
			else {
				smaller = right_child;
			}
		}
		else if (left_child <= (n - 1)) {
			smaller = left_child;
		}
		else if(left_child > (n - 1) && right_child > (n - 1)) {
			break;
		}
		if(A[i].salary > A[smaller].salary) {
			swap(&A[i], &A[smaller]);
			heapify(A, smaller, n);
		}
		else {
			break;
		}
	}
}

/**
 * Gets the minimally paid employee. Assumes the given list is a min-heap.
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
// struct Employee *getMinPaidEmployee(struct Employee *A, int n)
// {
// 	//TODO
// }


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(struct Employee *e1, struct Employee *e2)
{
	//TODO 
	struct Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(struct Employee *A, int n)
{
	//TODO
	for (int i = 0; i < n; ++i) {
		printf("[id=%s sal=%d] ", A[i].name, A[i].salary);
	}
}
