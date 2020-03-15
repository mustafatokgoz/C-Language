#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct people{
char id[100];
char name[100];
char surname[100];
char email[100];


}purpose;

/* this is how to findname */
int Name(char temp[30]){
for(int i=0;i<=30;i++){
	if((temp[i]>='A')&&(temp[i]<='Z')){
	if((temp[i+1]<='z')&&(temp[i+1]>='a')){
		return 1;
		
		}	
		}
		}

return 0;
}
/*this is how to find id number*/
int Id(char temp[30]){

	if((temp[0]>='0')&&(temp[0]<='9')){
	
		return 1;
		
		}	
		
		

return 0;
}
/* This is how to find email.*/
int Mail(char temp[30]){
int s;

	
	if((temp[0]<='z') && (temp[0]>='a')){
	
		return 1;
		}
			
		
		

return 0;
}




/* This is how to find surname.*/

int Surname(char temp[30]){
	
	
	if((temp[1]>='A')&&(temp[1]<='Z')){
	
	
	
		return 1;
		
		}	
		
		

return 0;
}
		







void main(){

FILE *fp;
fp=fopen("hw4_disordered_people.txt","r");
int person=0,b=0;
char ch,c;
char temp[30];



/* This is person number*/
while(!feof(fp)){
		ch=getc(fp);
		if(ch=='\n'){
		person=person+1;	}
}

fclose(fp);
purpose a[person];
fp=fopen("hw4_disordered_people.txt","r");

/* These are the functions that I did*/ 
while(!feof(fp)){
		fscanf(fp,"%s",temp);	
		Name(temp);
		if(Name(temp)==1){
		strcpy(a[b].name,temp);  printf("%d %s ",b,a[b].name);
		  	  }

		Surname(temp);
		if(Surname(temp)==1){
		strcpy(a[b].surname,temp);   
			 }

		Id(temp);
		if(Id(temp)==1){
		strcpy(a[b].id,temp); 
			}
	
		
		Mail(temp);
		if(Mail(temp)==1){strcpy(a[b].email,temp); 
		
		
		}
			  
		/* if the character that is after the word is \n,b(array number) will be added */
		c=getc(fp);
		if(c=='\n'){b++;}
                		
				
		}
		fclose(fp);
		/* this is where we write our datas*/ 
		fp = fopen ("orederedFile.txt", "w");
		fprintf(fp,"\t\tName\t\t\tSurname\t\t\tId\t\t\tMail");			
		for(int i=0;i<person;i++){
		fprintf(fp,"\n");		
		fprintf(fp,"%20s\t%20s\t%20s\t%20s",a[i].name,a[i].surname,a[i].id,a[i].email); 	
			
		

			}

		
		
		
		
		fclose(fp);
}		
			


		
		

			
		

























