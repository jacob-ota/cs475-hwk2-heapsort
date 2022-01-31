#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main()
{ 
	struct Employee emp[MAX_EMPLOYEES];
	char cont;
	int enteredEmployees;

	for (int i = 0; i < MAX_EMPLOYEES; ++i) {
		//get the names and salary
		printf("Name: ");
		scanf("%s", emp[i].name);
		printf("Salary: ");
		scanf("%d", &emp[i].salary);
		//update how many employees have been entered
		++enteredEmployees;
		//unless it reaches the max num keep query for another employee
		if(i < (MAX_EMPLOYEES - 1)) {
			printf("Enter another user ('y' / 'n')? ");
			scanf(" %c", &cont);
			//break if user enters 'n'
			if(cont == 'n') {
				break;
			}
		}
		//end if it reaches the max num of employees
		else {
			break;
		}
		printf("\n");
	}
	printf("\n");
	//sort the heap and print it
	heapSort(emp, enteredEmployees);
	printList(emp, enteredEmployees);
	printf("\n");
	return 0;
}
