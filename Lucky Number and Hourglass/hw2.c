#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>					/* Mustafa Tokgöz 171044077 */

void menu();
int make_a_guess(int trial, int min, int max);
void show_scores(int score_human, int score_program);
void draw_hourglass(int height);
void draw_mountain_road(int length, int max_radius);
void show_game(int guess);

int main(){
 srand(time(NULL));	/* this is for random number */
 menu();
	
return 0;
}

void menu(){
 int height;	/* this is for */
 int choice=1; /* this is for switch case */
 int trial=0;  /* these is for trial number */
 int min=1;		/* these are for lucky number game */
 int max=1024;
 int N,R;		/* these are for case 3 (how many circle and maximum radius) */
 int human=0,program=0;	/* these are scores */


 int result;
 int trialreally=10;			/* trialreally is amount of the right of trial */
 int guess=0;				/*for lucky number game */ 
 int distance;
 int i,j,d=max,a=0;  /*this is for distance exponent */



 

while(choice!=4){  	
	printf("\n***** MENU *****\n");
	printf("1. Play Lucky Number\n");
	printf("2. Draw Hourglass \n");
	printf("3. Draw Mountain Road\n");
	printf("4. Exit\n");
	printf("Choice: ");

	scanf("%d",&choice);
		switch(choice){
			case 1:		
					result=rand()%(max+1); /* the number will be included 1 and included 1024 so , we look random modulo of 1025 */
					if(result==0){result=result+1;}
				while(trial!=trialreally){ /* trial is increasing one by one until it reachs  really trial number that is 10 */
					
				guess=make_a_guess(trial,min,max); /* this is guess funtion */

				if(guess>=min && guess<=max){	 /* guess should be between minimum and maximum */ 
					distance=result-guess;
					if(distance<0){distance=distance*(-1);} /* if the distance minus then this makes it positive */
						while(d>=1){	
						d=d/2;
						a=a+1;			/* this is for 2 exponent */
						}
						
						for(j=1;j<a+1;j++){				
							if(distance<pow(2,j) &&  distance>=pow(2,j-1)){		/* this is distance algorithm  */
								printf("\nDistance:%d\n",j);
							}						
						}
	
					if(distance==0){
					printf("\nDistance:0\n");
					printf("\nYou win the game!! the lucky number is : %d  exactly the same as yours.\n",result);
					human=human+1;  /* if the distance is 0 then human score will be augmented */ 
					break;		
					}
						
					
						if(guess<result){	
						 min=max;	 /* if guess is less than result then , minimum will be maximum */
						}
						else if(guess>result){
							
						max=guess;  /* if guess is bigger than result then maximum will be guess */
							 
						}
						
						if(max>guess){	
							
						min=guess; /* if maximum is bigger than guess then minimum will be guess*/ 
						}
					}
					else{printf("\nYou had better enter the number between minimum and maximum!! because your trial right is decreasing! \n");
					}
					trial=trial+1; /* this augments trial number*/
				}
			
					if(guess!=result){
					printf("\nYou lost the game!! the lucky number is : %d\n",result);
					program=program+1; /* if user is lost program score will be increase one by one */ 
					}
							
				trial=0;  /* if user exits and plays another game ,then when user back here, program will run again initial position */
				min=1; /* so that program runs like initialize */ 
				max=1024;  /* so that program runs like initialize */
				show_scores(human,program);
				break;

			case 2:
			printf("\nPlease enter odd number.\n");
			scanf("%d",&height);
			draw_hourglass(height);
				break;
			case 3:
			printf("\nFirst,enter how many half circles do you want.\n ");
			scanf("%d",&N);
			printf("Now,enter the maximum radius\n");
			scanf("%d",&R);
			draw_mountain_road(N,R);
				break;
			case 4:
				break;
			default:
			printf("This is an invalid choice.Try again!\n");
		}
	}

}


int make_a_guess(int trial, int min, int max){
 int guess;

	printf("\n(Trial: %d) Make a guess between %d and %d: ",trial+1,min,max);

		scanf("%d",&guess);
return guess;
}

void show_scores(int score_human, int score_program){
	printf("\nYour Score: %d Program Score: %d\n",score_human,score_program);

}


void draw_hourglass(int height){
 int i,j;
 int a=0;
 int temp=height; /* there is veriable so that it  was used  below parts */ 
	if(height>0 && height%2==1){ /* it must be odd number and positive number */
	printf("\n");	
	for(i=0;i<(height+1)/2;i++){
		for(j=0;j<a;j++){	/* a is gradually increasing becouse of space */
			printf(" ");
		}		
		for(j=0;j<temp;j++){
			printf("*");   /* stars decreases like 2 values */
		}
		printf("\n");
		temp=temp-2;  /* stars decreases like 2 values */
		a=a+1;	
	}
	a=a-2;   	/* at the middle there is a one star so , we decrease 2 space */ 
	temp=temp+4;
	for(i=0;i<(height-1)/2;i++){
		for(j=0;j<a;j++){    /* a is gradually decreasing becouse of space */
			printf(" ");
		}		
		for(j=0;j<temp;j++){
			printf("*");  /* stars increases like 2 values */
		}
		printf("\n");
		temp=temp+2;
		a=a-1;	  /* a is gradually decreasing becouse of space */
	}
	}
	else {
		printf("\nPlease enter only odd positive number.Try again!\n");
	}

}
void draw_mountain_road(int length, int max_radius){
 int i,j,k,s,a;
		if(length>0 && max_radius>0){ /* they must be positive numbers */
a=rand()%(max_radius+1); 	/* if the radius is 0 then print only | with respect to homework  and max radius included so I used +1 */
	
	s=max_radius; /* this is first space that is determined by maximum radius*/
	
	for(i=0;i<length;i++){
		
		if(i%2==0){		/* this pattern goes on reversible so this provides  pattern */
			for(k=0;k<a;k++){
				for(j=0;j<s;j++){ 
				printf(" ");   /* space is put decreasingly one by one */
				}		
				printf("/\n"); 	
				s=s-1;	 /* this reduce the space */	
				}
			for(j=0;j<s;j++){
				printf(" ");   /* this prints spaces by decreasing */ 	
			}
			printf("|\n");
			s=s+1;  
			for(k=0;k<a;k++){
				for(j=0;j<s;j++){
				printf(" ");   /* space is put increasingly one by one */
				}
				printf("\\ \n");
				s=s+1;  /* this augment the space */
			}	
		}
		
		if(i%2==1){  /* if row is odd row then the pattern is reverse of even  ones */
			for(k=0;k<a;k++){
				for(j=0;j<s;j++){   /* space is put increasingly one by one */
				printf(" ");
				}
				printf("\\ \n");
				s=s+1;  /* this augment the space */
				}
			for(j=0;j<s;j++){
				printf(" ");			
			}
			printf("|\n");
			s=s-1;    /* this prints spaces by decreasing */ 
			for(k=0;k<a;k++){
				for(j=0;j<s;j++){
				printf(" ");   /* space is put decreasingly one by one */
				}
				printf("/\n"); 
				s=s-1;   /* this reduce the space */
				
	
			}
		}
			
	a=rand()%(max_radius+1); /* if the radius is 0 then print only | with respect to homework */
	}
		}
	
	else{ printf("\nplease enter positive numbers and try again !\n");}
}



























