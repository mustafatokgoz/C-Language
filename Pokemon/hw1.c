#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define SQUARE 1    
#define RECTANGULAR 2
#define CIRCULAR 3
#define PI 3
#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4


				     /* MUSTAFA TOKGÖZ 171044077 */


double CreateBody(int shape){      /* this part calculates the area */
int size;
int other;
	printf("\nplease enter the pokémon value or pokémon radius that you want it to be\n");
	scanf("%d",&size);
	if(shape==SQUARE){
		return size*size;	
	}
	else if(shape==RECTANGULAR){
		printf("please enter the other lenght of pokémon\n");
		scanf("%d",&other);
		return other*size;	
	}	
	else if(shape==CIRCULAR){
		return PI*size*size;	
	}
	else {
		printf("please only integer!!\n");
		return CreateBody(shape);
	}
}

int SetColor(int color){ /* this part takes color */
	if(color>=0 && color<=1000){
		return color%5;	      /*  colors pre-defined at the top */
	}
	else{
		return 1;
	}
}

double LoadMoves(int shape,double body_size){ /* this part calculates move */
	double rec=body_size/5;
	if(shape==SQUARE){
		return 	sqrt(body_size)*4;
	}
	else if(shape==RECTANGULAR){
		if(rec!=0){	/* if the numbers is 0 then move must be 0 */
		return 2*rec+(2*5);	
		}
	}	
	else if(shape==CIRCULAR){
		return 2*PI*sqrt(body_size/PI);	
	}
	else {
		return 0;
	}
}

int SetAttackPower(int lower_bound,int upper_bound){ /* this calculates attack power randomly */
int a;
		srand(time(NULL));
		a=rand()%upper_bound;	
		if(a<lower_bound){
			return lower_bound;	/* if lower bound is bigger than zero then if rand modulo of upper bound is less than lower bound then return lower bound */	
		}
		return a;
}

void ShowPokemon(int shape,double body_size,int color,double move_lenght,int attack_power){
	int n;
	int number=sqrt(body_size/PI);  /* this gives us the number */
	int i,j,k,a=0;
	int temp=number;		/* this is temporary number */
	double rec=(body_size)/5;	/* this is a lenght of rectangular */
	n=sqrt(body_size/PI);		/* this gives us the number */
	n=n%2;				/* this part calculate modulo 2 of number */
	

	if(shape==SQUARE){
		for(i=0;i<sqrt(body_size);i++){
			for(j=0;j<sqrt(body_size);j++){
				printf("X");
			}
			printf("\n");	
		}
		printf("Name: Square Pokémon\n");
	}
	else if(shape==RECTANGULAR){
		for(i=0;i<5;i++){
			for(j=0;j<rec;j++){
				printf("X");
			}
			printf("\n");	
		}
		printf("Name: Rectangular Pokémon\n");	
	}	
	else if(shape==CIRCULAR){
			if(number!=0){	/* if the number is 0 the program won't draw anything */
	
		switch(n){
			case 0: temp=number;   /* this is for even number */
				a=1;
				for(i=0;i<(number+1)/2;++i){	/* this is upside */
					if(i==0){
						for(j=0;j<(number-2)/2;j++){
							printf("\t");
						}
						printf("    ");
						printf("X");
						printf("\n");
					}
					for(j=0;j<(temp-1)/2;++j){
						printf("\t");
					}
					printf("X");
					temp=temp-2;
					for(j=0;j<a;j++){
						printf("\t");
					}
					printf("X");
					a=a+2;
					printf("\n");
				}
				temp=number;
				a=1;
				k=temp-3;
				for(i=0;i<(number-1)/2;i++){ /* this is downside */
					for(j=0;j<a;j++){
						printf("\t");
					}
					printf("X");
					a=a+1;
					for(j=0;j<k;j++){
						printf("\t");
					}
					printf("X");
					printf("\n");
					k=k-2;
					
					 					
				}
				if(number>2){
						for(j=0;j<(number-2)/2;j++){
							printf("\t");
						}
				}
						printf("    ");
						printf("X");
						printf("\n");
					
					
				
				break;
				

			case 1:	for(i=0;i<(number+1)/2;++i){  /* this is for odd number */
					for(j=0;j<(temp-1)/2;++j){ /* this part is upside */
						printf("\t");
					}	
					printf("X");
					temp=temp-2;
					if(i!=0){
						for(j=0;j<a;j++){
							printf("\t");			
						}
						printf("X");
					}	
					a=a+2;
					printf("\n");
				}
				temp=number;
				a=1;
				k=temp-3;
				for(i=0;i<(number-1)/2;i++){ /* this part is downside */
					for(j=0;j<a;j++){
						printf("\t");			
					}			
					printf("X");
					a=a+1;
					for(j=0;j<k;j++){
						printf("\t");
					}
					if(i!=(number-2)/2){
						printf("X");			
					}
					printf("\n");
					k=k-2;
				}
				break;
			}		
				
		
		
		printf("Name: Circular Pokémon\n");
		}	
	}
		printf("Size: %.2f\n",body_size);
	switch(color){			/* colors pre-defined at the top and their numbers called */
		case RED:
			printf("Color: Red\n");
			break;
		case YELLOW:
			printf("Color: Yellow\n");
			break;
		case BLUE:
			printf("Color: Blue\n");
			break;
		case BLACK:
			printf("Color: Black\n");
			break;
		case WHITE:
			printf("Color: White\n");
			break;
	}
			printf("Move: %.2f\n",move_lenght);
			printf("Attack Power: %d\n",attack_power);
	
}





int main(){
int shape,color,attack_power;
double size_of_body,move_lenght;

	
		shape=RECTANGULAR; /* You can change the shape as CIRCULAR or SQUARE or RECTANGULAR */
		size_of_body=CreateBody(shape);
		color=798;
		color=SetColor(color);
		move_lenght=LoadMoves(shape,size_of_body);
		attack_power=SetAttackPower(0,150);
		ShowPokemon(shape,size_of_body,color,move_lenght,attack_power);
	
return 0;
}





























