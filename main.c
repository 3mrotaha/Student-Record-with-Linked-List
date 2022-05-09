#include <stdio.h>
#include "std_types.h"
#include "prototypes.h"

int main(){
	int Check, id, Operation = 1;
	Load_Database();
	while(Operation == 1){
		printf("Add/Delete Student/Display Student Data/Display Database/Delete All 1/2/3/4/5: ");
		scanf(" %d", &Check);
		if(Check == 1){
			AddnewStudent();
		}
		else if(Check == 2){
			printf("Enter The Id : ");
			scanf(" %d", &id);
			DeleteStudent(id);
		}
		else if(Check == 3){
			printf("Enter The Id : ");
			scanf(" %d", &id);
			display_Student(id);
		}
		else if(Check == 4){
			DisplyDatabase();
		}
		else{
			freeData();
		}
		printf("Another Operation! 1/0:");
		scanf(" %d", &Operation);
	}
	freeData();
	printf("Exiting...");
	return 0;
}