#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"

struct node{
	Student data;
	struct node* next;
};

struct node *head = NULL;
struct node *tail = NULL;
extern Student stud[STUDENTS];

void Load_Database(void){
	struct node* newnode;
	for(int i = 1; i < STUDENTS; i++){
		if(stud[i].id != 0){
			newnode = malloc(sizeof(struct node*));
			// check if first node
			if(head == NULL){
				head = newnode;
				tail = newnode;
				newnode->data = stud[i];
				newnode->next = NULL;
			}
			else{
				newnode->data = stud[i];
				tail->next = newnode;
				tail = newnode;
				newnode->next = NULL;
			}
		}
	}
}

void freeData(void){
	struct node* current = head;
	if(head != NULL){
		while(head != NULL){
			head = current->next;
			current->next = NULL;
			free(current);
			current = head;
		}
		printf("DataBase Is Freed!\n");
	}
}

void GPA(f32 grade){
	if(grade < 60) printf("F");
	else if(grade >= 60 && grade < 65) printf("E");
	else if(grade >= 65 && grade < 67) printf("D");
	else if(grade >= 67 && grade < 70) printf("D+");
	else if(grade >= 70 && grade < 73) printf("C-");
	else if(grade >= 73 && grade < 77) printf("C");
	else if(grade >= 77 && grade < 80) printf("C+");
	else if(grade >= 80 && grade < 83) printf("B-");
	else if(grade >= 83 && grade < 87) printf("B");
	else if(grade >= 87 && grade < 90) printf("B+");
	else if(grade >= 90 && grade < 93) printf("A-");
	else if(grade >= 93 && grade < 97) printf("A");
	else if(grade >= 97) printf("A+");
}

void display_Student(int idNum){
	struct node* current = head;
	while(current->data.id != idNum && current != NULL) 
		current = current->next;
	
	if(current != NULL){
		printf("Student ID : %d\n", idNum);
		printf("Student Name : ");
		printf("%s %s \n", current->data.frstname, current->data.lstname);
		
		f32 Weekly_Average, total_grade_Average = 0;
		for(int_32 i = 0; i < WEEKS; i++){
			printf("Week (%d):\n", i+1);
			Weekly_Average = 0;
			for(int_32 j = 0; j < DAYS; j++){
				printf("Day (%d):\t\t", j+1);
				printf("%0.2f\t\t", current->data.grades[i][j]);
				printf("%0.2f\t\t", stud[0].grades[i][j]);
				GPA((current->data.grades[i][j] / stud[0].grades[i][j]) * 100);
				printf("\n");
				Weekly_Average += current->data.grades[i][j];
			}
			printf("\n");
			printf("## Week (%d) Average = %.2f%%\t\t", i, (Weekly_Average / 270) * 100);
			GPA((Weekly_Average / 270) * 100);
			printf("\n");
			total_grade_Average += Weekly_Average;
		}
		printf("\nThe Student Total Average = %.2f%%\t\t", (total_grade_Average / 540) * 100);
		GPA(((total_grade_Average / 540) * 100));
		printf("\n");
 }
}

void AddnewStudent(void){
	struct node* newnode;
	newnode	= malloc(sizeof(struct node*));
	printf("Enter First Name:");
	scanf("%s", &(newnode->data.frstname));
	printf("Enter Last Name:");
	scanf("%s", &(newnode->data.lstname));
	printf("Enter ID:");
	scanf("%d", &(newnode->data.id));
	printf("Enter Student Grades:");
	for(int i = 0; i < WEEKS; i++){
		printf("##Week (%d)\n", i+1);
		for(int j = 0; j < DAYS; j++){
			printf("Day (%d):", j+1);
			scanf("%f", &(newnode->data.grades[i][j]));
		}
	}
	// Check Possible First Node
	if(head == NULL){
		head = newnode;
		tail = newnode;
		newnode->next = NULL;
	}
	// not First Node
	else{
		tail->next = newnode;
		tail = newnode;
		newnode->next = NULL;
	}
}

void DeleteStudent(int idNum){
	struct node* current = head;
	struct node* prev = NULL;
	
	while(current->data.id != idNum && current != NULL){
		prev = current;
		current = current->next;
	}
	if(current != NULL){ // ID is in the database
		if(prev != NULL){ // Check if it's not the first node
			prev->next = current->next;
			current->next = NULL;
			printf(" %s %s Deleted Successfully\n", current->data.frstname, current->data.lstname);	
			free(current);
		}
		else{ // the selected node is the first node
			head = current->next;
			current->next = NULL;	
			printf(" %s %s Deleted Successfully\n", current->data.frstname, current->data.lstname);	
			free(current);
		}	
	}
	else{
		printf("Student isn't Existed int the Database\n");
	}
}
f32 get_AvrGrades(int weeks, int days, f32 Grades[weeks][days]){
	f32 sum = 0;
	for(int_32 i = 0; i < weeks; i++){
		for(int_32 j = 0; j < days; j++){
			sum += Grades[i][j];
		}
	}
	return (sum/540) * 100;
}

void DisplyDatabase(void){
	struct node* current =  head;
	if(head == NULL){
		printf("DataBase is Empty, No Students to View\n");
	}
	while(current != NULL){
		printf("%s\t\t\t%s\t\t\t%d\t\t%0.2f\n", current->data.frstname, current->data.lstname, current->data.id, get_AvrGrades(WEEKS, DAYS, current->data.grades));
		current = current->next;
	}
}


