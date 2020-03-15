#include<stdio.h>
#include<math.h>

					/* Mustafa Tokgöz  171044077*/
int take_grades(int grade[]);
int take_exam_grades(int exam_grade[]);			/* these are for part 2 */
double calculate_homework(int grade[]);
double calculate_lab(int grade[]);
double calculate_all(int calc_hom,int exam_grade[],int calc_lab); 	 												


int doit(int f(),int number1,int number2);
int add(int number1,int number2);
int sub(int number1,int number2);
int mul(int number1,int number2);		/* these are for part1 addition subtraction etc.*/
int div(int number1,int number2);
int expo(int number1,int number2);
int modulo(int number1,int number2);

void draw_the_figure(int height);		/* this is for part 3 */

void menu_of_calculater();			/* these are menus */
void menu_of_program();

int main(){

	menu_of_program();
return 0;
}

void menu_of_program(){
 int choice=1;		/*this is choice that we used to take operation*/
 int height;		/*this is to take value of figure*/
 int grade[10];
 int hom_grade[10];
 int lab_grade[10];		/*these are arrays for grades*/
 int exam_grade[2];
 int exams[2];
 double calc_hom,calc_lab;
 double result;
 int temp,j;   /*these are temporary values*/
 
	while(choice!=4){
		printf("\n***** MENU *****\n");
		printf("1. Calculater\n");
		printf("2. Calculate Grades \n");
		printf("3. Draw the Figure \n");
		printf("4. Exit\n");
		printf("Choice: ");
			scanf("%d",&choice);
			switch (choice){
				case 1:	menu_of_calculater();	/* this is calculater*/
					
					break;
				case 2:	printf("Enter 10  homework grades\n");
					
					take_grades(grade);
					for(j=0;j<10;j++){
					hom_grade[j]=grade[j];}		/*these are filling arrays inside from grade to hom_grade*/
					
					printf("Enter 10 labrotary grades\n");
						take_grades(grade);
					for(j=0;j<10;j++){
					lab_grade[j]=grade[j];}			/*these are filling arrays inside from grade to lab_grade*/
						take_exam_grades(exam_grade);		
					exams[0]=exam_grade[0];
					exams[1]=exam_grade[1];
					calc_hom=calculate_homework(hom_grade);					
					calc_lab=calculate_lab(lab_grade);        /*these ara avarage */
					result=calculate_all(calc_hom,exams,calc_lab); /*this is calculating all grades*/
					printf("Your the weighted avarage is = %.2f\n",result);
					break;
				case 3:	
					printf("Please, enter the height you want it to be\n");
					scanf("%d",&height);
					draw_the_figure(height);
					break;
				case 4: break;

				default:
				printf("This is an invalid choice.Try again!\n");
			}

	}

}


void menu_of_calculater(){
 char calculater='a'; /* this is for calculater*/
 int number1=0,number2=0;
 int temp,j;	
	printf("if you want to do an operation,it can be +,-,*,/,**,%%\n");
	printf("please enter one of these but\n");
	printf("you should enter like this\n");
	printf("Example:\n");
	printf("+ 5 4\n9\n/ 3\n3\n** 5 2\n25\n");
	printf("like upper side\n");
	printf("if you want to quit enter 0 one time if it doesn't ,you should enter 0 one more time\n\n");

	while(calculater!='0'){
					
		scanf("%c\n",&calculater); /*this takes a line */
			if(calculater=='0'){break;} /*if character is 0 then program will quit*/
		while(calculater!='\n'){
			if(calculater=='0'){break;}
					if(calculater=='+'){		/*if calculater is + then it will do addition*/
						
					scanf("%d",&number1);		/*it takes first number */
					scanf("%c",&calculater);
					if(calculater!='\n'){		/*if line doesnt finish*/
					scanf("%d",&number2);		/*then take second number*/
													
					}
			
					number2=doit(add,number1,number2);	/*it sends function doit and that number will go number 2 so that if other line 										has one number then  second number is number 2*/
						
					}
					else if(calculater=='-'){ 		/*if calculater is - then it will do subtraction*/
						scanf("%d",&number1);  			/*it takes first number */
						scanf("%c",&calculater);
						if(calculater!='\n'){  				/*if line doesnt finish*/
							scanf("%d",&number2);		 /*then take second number*/				
						number2=doit(sub,number1,number2);
						}
						else{temp=number2;
						temp=doit(sub,temp,number1);		/*if there is no number 2 then previus answer is now our number 2 ,this is for that*/ 											
						number2=temp;								
						}
						

					}
					else if(calculater=='*'){ 	 	/*if calculater is * then it will do multipication*/
						
					scanf("%d",&number1);     		/*it takes first number */
					scanf("%c",&calculater);		
					if(calculater=='*'){					/*if calculater is * again then it will do exponent */
						scanf("%d",&number1);          			/*it again takes first number becouse of exponenet */
						scanf("%c",&calculater);
							if(calculater!='\n'){				/*if line doesnt finish*/
							scanf(" %d",&number2);          	 /*then take second number*/
							number2=doit(expo,number1,number2);
							}
							else{temp=number2;			/*if there is no number 2 then previus answer is now our number2 ,this is for that*/ 													
							temp=doit(expo,temp,number1);
							number2=temp;								
							}	
											
								
							}
						else{
							if(calculater!='\n'){
							scanf("%d",&number2);   /*then take second number  of multipication*/
							}
						number2=doit(mul,number1,number2);
						
						}
							
					}
					
					else if(calculater=='/'){        /*if calculater is / then it will do division*/
						scanf("%d",&number1);
						scanf("%c",&calculater);
						if(calculater!='\n'){   		/*if line doesnt finish*/
							scanf("%d",&number2);			 /*then take second number*/			
						number2=doit(div,number1,number2);
						}
						else {	j=number1;		/*if there is no number 2 then previus answer is now our number2 ,this is for that*/ 													
						number1=number2;
						number2=j;
						number2=doit(div,number1,number2);
						}

					}
					else if(calculater=='%'){ 		/*if calculater is % then it will do modulo*/
						scanf("%d",&number1);
						scanf("%c",&calculater);
						if(calculater!='\n'){
							scanf("%d",&number2);		
							number2=doit(modulo,number1,number2);						
						}
						else{temp=number2;
							temp=doit(modulo,temp,number1);
							number2=temp;		/*if there is no number 2 then previus answer is now our number2 ,this is for that*/	 		
							}
						
						

					}
					else {
						printf("Please enter a valid operation\n");
					}
						
						printf("\n");
						scanf("%c",&calculater);
				 }
						
					
			}	
}

int doit(int f(),int number1,int number2){				/*this is doit function*/
		printf("%d",f(number1,number2));
	return f(number1,number2);
}

int add(int number1,int number2){

	return number1+number2;
}

int sub(int number1,int number2){					/*........THESE ARE OPERATİON FUNSTİONS.......*/
		
	return number1-number2;
}

int mul(int number1,int number2){
		

	return number1*number2;
}

int div(int number1,int number2){
	if(number2==0){
		return 0;
	}
	else{
		return number1/number2;
	}
}

int expo(int number1,int number2){					/*........THESE ARE OPERATİON FUNSTİONS.......*/
int a;
	
a=pow(number1,number2);
	return a;
}

int modulo(int number1,int number2){

	return number1%number2;
}



int take_grades(int grade[]){
 int i,how_much=10;	
	for(i=0;i<how_much;i++){
	scanf("%d",&grade[i]);				/*This is filling arrays inside*/
	}

return 0;
}

int take_exam_grades(int exam_grade[]){
	printf("Please fist enter your midterm greade\n");			/*these are taking midterm and final*/
	scanf("%d",&exam_grade[0]);
	printf("Please now enter your final grade\n");
	scanf("%d",&exam_grade[1]);	
return 0;
}

double calculate_homework(int grade[]){	
 int i,many=10;
 double avarage=0.0;	
	for(i=0;i<many;i++){					/*this calculates avarage of homework grades*/
		avarage=avarage+grade[i];	
	}
	return avarage=avarage/many;
}

double calculate_lab(int grade[]){
 int i,many=10;
 double avarage=0.0;					/*this calculates avarage of lab grades*/
	for(i=0;i<many;i++){
		avarage=avarage+grade[i];	
	}
	return avarage=avarage/many;

}

double calculate_all(int calc_home,int exam_grade[],int calc_lab){		/*this calculates all avarage of grades*/

	
	return 	(calc_home*10)/100+(exam_grade[0]*30)/100+(exam_grade[1]*40)/100+(calc_lab*20)/100;
}


void draw_the_figure(int height){
 int i,j;
 int space=height-1;		/*this is becouse of the figure*/
 int star=0;
	
	for(i=0;i<height;i++){
		for(j=0;j<space;j++){
			printf(" ");	
		}		
		printf("/");
		for(j=0;j<star;j++){
			printf("*");
		}
		printf("\\");
		printf("\n");
		space=space-1;
		star=star+2;
	}
	star=star-2;
	for(i=0;i<height;i++){
		space=space+1;
		for(j=0;j<space;j++){
			printf(" ");	
		}		
		printf("\\");
		
		for(j=0;j<star;j++){
			printf("*");
		}
		printf("/");
		printf("\n");
		star=star-2;
	}
	
}














