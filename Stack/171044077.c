#include<stdio.h>
#include<stdlib.h>
#include<string.h>

						/*Mustafa Tokgöz 171044077*/
struct person{			/*this is struct that is given by the Teacher*/
	char name[1000];
	char surname[1000];
	char musical_Work[1000];
	int age;
	struct person *next;
}*top;


void menu(){			/*this is printing menu*/
printf("\n****MENU****\n");
printf("1- Add a Person to the Stack\n");
printf("2- Pop a Person from the Stack\n");
printf("3- Sort Alphabetical Order\n");
printf("4- Sort Age in Increasing Order\n");
printf("5- Exit menu\n");
printf("*************\n");
printf("Select your choice:");
}

void addNode(char name[], char surname [], char creation [], int age){  /*this is adding person to the stack*/
	struct person *temp;
	temp=(struct person *)malloc(sizeof(struct person));
	
	printf("Name:");
	scanf("\n%[^\n]s",name);	/*this is getting all line for getting one word or more than one words*/
	printf("Surname:");
	scanf("\n%[^\n]s",surname);	
	printf("Creation:");
	scanf("\n%[^\n]s",creation);	
	printf("Age:");
	scanf("%d",&age);
								
	strcpy(temp->name,name);
	strcpy(temp->surname,surname);			/*this is assigning the features*/
	strcpy(temp->musical_Work,creation);
	temp->age=age;

	temp->next=top;
	top=temp;

}
void deleteNode(){ 			/*this is deleting person*/
    struct person *temp; 
    if (top != NULL) { 
        temp=top;
        top=top->next; 
        temp->next = NULL; 
        free(temp); 
	printf("\nDeleting is success!\n");
    } 
    else { 
        printf("\nStack is empty\n");
    } 
} 

void Sort_Alphabetically(){			/*this is sorting alphabetically*/
struct person *te;
	te=(struct person *)malloc(sizeof(struct person));
struct person *temp=top,*temp2;
	if(temp!=NULL){		/*this is checking if is empty or not*/
		temp2=temp->next;	/*this points temp->next for comparing forward*/
	
		while(temp->next!=NULL){		/*this is controlling letters with respect to ascii*/
			while(temp2!=NULL){
				
				if(strcmp(temp->name,temp2->name)>0){	/*if letter's ascii number is small than other*/
				strcpy(te->name,temp->name);			/*then it will replace them */
				strcpy(te->surname,temp->surname);
				strcpy(te->musical_Work,temp->musical_Work);
				te->age=temp->age;
				
				strcpy(temp->name,temp2->name);
				strcpy(temp->surname,temp2->surname);
				strcpy(temp->musical_Work,temp2->musical_Work);
				temp->age=temp2->age;
				
				
				strcpy(temp2->name,te->name);
				strcpy(temp2->surname,te->surname);
				strcpy(temp2->musical_Work,te->musical_Work);
				temp2->age=te->age;
				}
				temp2=temp2->next;	
			}
			temp=temp->next; /*this is going until reaching NULL*/
			temp2=temp->next;	/*this points temp->next for comparing forward*/
		}
	}
	else 
		printf("\nStack is empty!\n");
}

void Sort_Increasingly(){		/*this is sorting increasingly*/
struct person *te; /*this is temporary pointer for replacing between 2 of them*/
	te=(struct person *)malloc(sizeof(struct person));
struct person *temp=top,*temp2;
	if(temp!=NULL){			/*this is checking if is empty or not*/
		temp2=temp->next; /*this points temp->next for comparing forward*/
	
		while(temp->next!=NULL){		/*this is controlling numbers*/
			while(temp2!=NULL){

				if((temp->age)>(temp2->age)){	/*if number is bigger than other*/
				strcpy(te->name,temp->name);
				strcpy(te->surname,temp->surname);
				strcpy(te->musical_Work,temp->musical_Work);
				te->age=temp->age;
				
				strcpy(temp->name,temp2->name);
				strcpy(temp->surname,temp2->surname);
				strcpy(temp->musical_Work,temp2->musical_Work);
				temp->age=temp2->age;
				
				
				strcpy(temp2->name,te->name);
				strcpy(temp2->surname,te->surname);
				strcpy(temp2->musical_Work,te->musical_Work);
				temp2->age=te->age;
				}
				temp2=temp2->next;	
			}
			temp=temp->next; /*this is going until reaching NULL*/
			temp2=temp->next; /*this points temp->next for comparing forward*/
		}
	}
	else
		printf("\nStack is empty!\n");

}


void show_list(){		/*this is showing list*/
struct person *temp=top;
int i=1;
	while(temp!=NULL){
		printf("\n%d) %s\n",i,temp->name);
		printf("   %s\n",temp->surname);
		printf("   %s\n",temp->musical_Work);
		printf("   %d\n",temp->age);
		temp=temp->next;
		i++;
	}
}
void print_stack(){		/*this is printing list for sorts*/
struct person *temp=top;
	while(temp!=NULL){
		printf("\n   %s\n",temp->name);
		printf("   %s\n",temp->surname);
		printf("   %s\n",temp->musical_Work);
		printf("   %d\n",temp->age);
		temp=temp->next;
	}
}

void free_stack(){		/*this is deallocating stack*/
struct person *temp;
   while(top!=NULL){
       temp=top;
       top=top->next;
       free(temp);
   }
}

int main(){
 int select=0;
 char name[1000],surname[1000],creation[1000];
 int age;
 top=NULL;
 while(select!=5){	/*if user enter 5 then program will be over*/
 menu();
 scanf("%d",&select);
 	switch (select){
 		case 1: addNode(name,surname,creation,age);
			show_list();
			break;
		case 2: deleteNode();
			show_list();
			break;
		case 3: Sort_Alphabetically();
			print_stack();
			break;
		case 4: Sort_Increasingly();
			print_stack();
			break;
		case 5: break;
		default: printf("Please enter valid operation\n");
 	}
 }

 free_stack(); /*this is deallocating stack*/
return 0;
}









