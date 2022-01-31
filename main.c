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
		printf("Name: ");
		scanf("%s", emp[i].name);
		printf("Salary: ");
		scanf("%d", &emp[i].salary);
		++enteredEmployees;
		if(i < (MAX_EMPLOYEES - 1)) {
			printf("Enter another user ('y' / 'n')? ");
			scanf(" %c", &cont);
			if(cont == 'n') {
				break;
			}
		}
		else {
			printf("\n");
			break;
		}
		printf("\n");
	}
	return 0;
}
