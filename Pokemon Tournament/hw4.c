#include<stdio.h>
#include<stdlib.h>
#include<time.h>
						/*MUSTAFA TOKGÖZ 171044077*/

		/*these are enumarater type of pokemons*/
typedef enum{
	Charmander=0,Pikachu=1,Squirtle=2,Bulbasaur=3,Pidgeotto=4,Ratata=5,Mug=6,Caterpie=7,Zubat=8,Krabby=9

}pokemon;
typedef enum{
	linear=0,quadratic=1

}attack_type;




void menu();
void oakslabrotary_menu();
void pokedex(char pokemon_name[][11],int range[],attack_type type[],int attack_power[],int stamina[]);
void oaks_laboratory(char pokemon_name[][11],pokemon pokemons[],pokemon *my_pocket);
void show_pokemons(char pokemon_name[][11],pokemon pokemons[],int pokemon_count);
void catch_a_pokemon(char pokemon_name[][11],pokemon pokemons[],pokemon *my_pocket);
void release_a_pokemon(char pokemon_name[][11],pokemon pokemons[],pokemon *my_pocket);
void battle(char pokemon_name[][11],int range[],attack_type type[],int attack_power[], int stamina[], pokemon user_pokemons[]);
void show_area (char pokemon_name[][11],int area[][8],int pokemon_staminas[][8]);
void move_function(int *x,int *y,int area[][8],int pokemon_staminas[][8],int move,int many,int current_pokemon);





int main(){
 int option;
 int range[10]={1,3,4,3,2,2,1,2,3,2};
 int attack_power[10]={500,350,300,400,250,250,350,200,350,300};
 int stamina[10]={2200,1500,1700,2500,1900,2500,3000,1200,1250,2600};
 char pokemon_name[10][11]={"Charmander","Pikachu","Squirtle","Bulbasaur","Pidgeotto","Ratata","Mug","Caterpie","Zubat","Krabby"};
 pokemon pokemons[10]={Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby};
 pokemon my_pocket[4]={-1,-1,-1,-1};
 attack_type type[10]={quadratic,linear,linear,linear,quadratic,linear,quadratic,quadratic,linear,linear};

	menu(range,attack_power,stamina,pokemon_name,pokemons,my_pocket,type);

return 0;

}


void menu(int range[],int attack_power[],int stamina[],char pokemon_name[][11],pokemon pokemons[],pokemon *my_pocket,attack_type type[]){
 int option=-1;
 int check=0;
 int i;

while(option!=0){
	printf("Please select an option to continue:\n");			/* This is our menu */
	printf("1) Open Pokedex\n");
	printf("2) Go to Oak’s Laboratory\n");
	printf("3) Enter the tournament\n");
	scanf("%d",&option);
			if(option==1){ pokedex(pokemon_name,range,type,attack_power,stamina);}
				
			if(option==2){ oaks_laboratory(pokemon_name,pokemons,my_pocket);}
				
			if(option==3){
				 for(i=0;i<4;i++){
					if(my_pocket[i]!=-1){
						check++;	
					}
				 }
				 if(check==4)
				 	battle(pokemon_name,range,type,attack_power,stamina,my_pocket);
				 else	
					printf("There is not 4 pokemon please first select 4 pokemon to enter tounament\n");	
				 check=0;		
			}

			if(option==0){break;}
			if(option!=0 && option!=1 && option!=2 && option!=3 ){
				printf("Try again\n");	
				}
		}

}

void pokedex(char pokemon_name[][11],int range[],attack_type type[],int attack_power[],int stamina[]){
 int i,j;
 int count=1;
 char which[11];
	
	which[0]==1;
	while(which[0]!='0'){
	printf("\nPlease type name of the Pokémon like Pikachu,Charmander(type exit to close Pokedex):\n");
		scanf("%s",which);
		if(which[0]=='e' && which[1]=='x' && which[2]=='i' && which[3]=='t'){		/*If you write exit then you will quit here */
			break;
		}
		for(i=0;i<10;i++){
			for(j=0;which[j]!=0;j++){
				if(pokemon_name[i][j]!=which[j]){		/*If taken word is equal to one of pokemon name then it'll print its characters*/
				count=0;				
					}
			}
			if(count==1){
				printf("Name: ");			/*then its id is our source after that we print its features*/
				for(j=0;pokemon_name[i][j]!=0;j++){
				printf("%c",pokemon_name[i][j]);
				}
				printf("\nA. Type :");
				if(type[i]==0){printf(" Linear \n");}
				if(type[i]==1){printf(" Quadratic \n");}
				printf("Range : %d block\n",range[i]);
				printf("A. Power : %d \n",attack_power[i]);
				printf("Stamina : %d \n",stamina[i]);
			}
			count=1;

		}		
	}
}
void oakslabrotary_menu(){
	printf("Welcome to Laboratory of Professor Oak. How can I help you?\n");
	printf("1) Show Pokémons\n");
	printf("2) Catch a Pokémon\n");
	printf("3) Release a Pokémon\n");				/*This is our second menu*/
	printf("4) Show my pocket\n");
	printf("5) Back\n");
}

void oaks_laboratory(char pokemon_name[][11],pokemon pokemons[],pokemon *my_pocket){
 int choice=-1;
 int pokemon_count=10;
	
	
	while(choice!=5){
	oakslabrotary_menu();
	scanf("%d",&choice);
	
		if(choice==1){ show_pokemons(pokemon_name,pokemons,pokemon_count);}
			
		if(choice==2){catch_a_pokemon(pokemon_name,pokemons,my_pocket);}
			
		if(choice==3){
			release_a_pokemon(pokemon_name,pokemons,my_pocket);
		}
			
		if(choice==4){
			pokemon_count=4;
			show_pokemons(pokemon_name,my_pocket,pokemon_count);
		}
		
		if(choice==5){
			printf("\n");
			break;
		}
		if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 ){ 
			printf("\nThis is an invalid option please try again\n\n");
			
		}	 
	}
		

}
void show_pokemons(char pokemon_name[][11],pokemon pokemons[],int pokemon_count){
 int i,j,k;

	printf("\n");
	for(i=0;i<pokemon_count;i++){
		k=pokemons[i];
		if(pokemons[i]!=-1){
		printf("%d - ",pokemons[i]);		/*this shows pokemons*/
		for(j=0;j<11;j++){
			
			
			printf("%c",pokemon_name[k][j]);
			}
		printf("\n");	
		}
		
		
	}	
	printf("\n");

}
void catch_a_pokemon(char pokemon_name[][11],pokemon pokemons[],pokemon *my_pocket){
 int pokemon_count=10;
 int i=0,t;
 int temp;
 int a=0,c;						/*this catch a pokemon then it assign to my_pocket*/
	
	if(my_pocket[0]==-1 || my_pocket[1]==-1 || my_pocket[2]==-1 || my_pocket[3]==-1){
	show_pokemons(pokemon_name,pokemons,pokemon_count);
	pokemon_count=4;
	printf("\n\n Please catch a pokemon,You can catch at most 4 time.If you want to quit press -1\n\n");
	
	for(i=0;i<4;i++){
		if(my_pocket[i]==-1){
		scanf("%d",&temp);
		if(temp==-1){
			break;			/*if entered number is -1 then loop will be broken*/
		}

			t=i;
	
			if(temp<10 && temp>=0){
			my_pocket[i]=temp;
			
			for(a=0;a<4;a++){
					if(a!=t){
						if(
						my_pocket[t]==my_pocket[a]){printf("please enter different pokemon\n");
						i=i-1; 
						my_pocket[t]=-1;		/*if caught pokemons are equal then it will make you catch again*/
						}
					}	
				}
			}
			else{
				printf("this is invalid choice\n");i--; 
			}
		}
		
			
	}
	
	printf("Your pokemons:\n");
	
	show_pokemons(pokemon_name,my_pocket,pokemon_count);
	
	}
	
	else{
	pokemon_count=4;
	printf("Your pokemons:\n");			/*If you have 4 pokemon then you cant catch again , if you want press 1 if you dont want press 0*/
	show_pokemons(pokemon_name,my_pocket,pokemon_count);
	printf("You were already chosen your pokemon ,if you wanna rechoose pokemon press 1 and come again catch pokemon  ,if dont , press 0\n");
		scanf("%d",&c);
		if(c==1){
			for(a=0;a<4;a++){
				my_pocket[a]=-1;		
			}		
		}		
	
	}

}
void release_a_pokemon(char pokemon_name[][11],pokemon pokemons[],pokemon *my_pocket){
 char released;
 int i;
 int pokemon_count=4;
	show_pokemons(pokemon_name,my_pocket,pokemon_count);
	printf("\n");
	printf("İf you want to release a pokemon you enter its id ,if you want to wuit  you should enter q\n");
	
	while(released!='q'){
		scanf("%c",&released);			/*This is releasing pokemons,if you press q then you will quit release part*/
		if(released=='q'){break;}
		else{
		released=released-48;
			for(i=0;i<4;i++){
				if(my_pocket[i]==released){
					my_pocket[i]=-1;
				}
			}	
		}
	}

	show_pokemons(pokemon_name,my_pocket,pokemon_count);

}






void battle(char pokemon_name[][11],int range[],attack_type type[],int attack_power[], int stamina[], pokemon user_pokemons[]){
 int x,y,i,j,finish=1,move,many,count;
 int current_pokemon;
 int area[8][8],new_area[8][8];
 int pokemon_staminas[8][8];				/*This is our battle partials*/
 int pokemon_count=4;
 int ai_pokemons_x,ai_pokemons_y,ai_pokemons[4]={-1,-1,-1,-1},t;
 int p_range=0,a,random_ai=0;
 srand(time(NULL));
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			area[i][j]=-1;			/*this si filling -1 to all area */
		}
	}
printf("Firstly, you should locate your pokemons\n");
show_pokemons(pokemon_name,user_pokemons,pokemon_count);
	for(i=0;i<pokemon_count;i++){
	current_pokemon=user_pokemons[i];
		if(current_pokemon!=-1){		/*if user's pokemon isnt -1 then you locate it */
				printf("locate your %d. pokemon : \n",i+1);
				printf("Enter its x location 0 to 7\n");
				scanf("%d",&x);
				if(x>=0 && x<8){
					printf("if you want it be first row press 0 , if you want it be second row press 1, If you press other number , it will take modulo of 2 \n");		
					scanf("%d",&y);
					y=y%2;
					if(area[y][x]==-1){
					area[y][x]=current_pokemon;
					}
					else{
					printf("please enter different location\n");i=i-1;
					
					}
					
									
				}
				else{
					printf("Please enter  number in the range of 0 to 7\n");
					i--;
				}
		}
	}
	for(i=0;i<4;i++){
		t=i;
		ai_pokemons[i]=(rand()%10)+10;		/*this is random enemy pokemon , I  add +10 becouse thanks to this,i understand who is enemy or not ,If number is bigger than 10 , it will be enemy*/
		for(j=0;j<4;j++){
			if(j!=t){
				if(ai_pokemons[j]==ai_pokemons[t]){
					i--;
				}			
			}
		}
	}
		
	for(i=0;i<4;i++){		
			ai_pokemons_x=rand()%8;
			ai_pokemons_y=rand()%2;		/*this is locating randomly*/
			if(area[ai_pokemons_y+6][ai_pokemons_x]==-1){	/*if there isnt any pokemon ,then it will locate , If there is ,then it will locate same pokemon again*/
			area[ai_pokemons_y+6][ai_pokemons_x]=ai_pokemons[i];
			}
			else{i--;}
	}
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			pokemon_staminas[i][j]=-1;	/*this assign -1 to all pokemons staminas */
		}
	}		
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(area[i][j]<10){
			current_pokemon=area[i][j];
			}
			if(area[i][j]>=10){
			current_pokemon=area[i][j]-10; /*if number is bigger than 10 (this is enemy) , I subtact -10 */
			}
			if(current_pokemon!=-1){
				pokemon_staminas[i][j]=stamina[current_pokemon]; /*And I assign staminas current pokemon*/
			}		
				
		
		}
	}
		
		
	while(finish!=0){	/*If finish is 0 than game is finish*/
		count=0;
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						new_area[i][j]=area[i][j];	
					}
						}
		show_area(pokemon_name,new_area,pokemon_staminas);		
		printf("Pick one of them with its location\n");
		printf("Now enter its x-axis number \n");
		scanf("%d",&x);
		printf("Now enter its y-axis number \n");	/*You choose your pokemon*/
		scanf("%d",&y);
		current_pokemon=area[y][x];
		if(area[y][x]!=-1 && area[y][x]<10){
				printf("Now enter your move (2=down,4=left,6=right,8=up)\n");
				scanf("%d",&move);
				printf("Do you move 1 or 2? enter 1 or 2\n");
				scanf("%d",&many);
				many=many%2;
				move_function(&x,&y,area,pokemon_staminas,move,many,current_pokemon); /*this is move function*/

		}	
		else{
			printf("The location has no your pokemon , try again\n ");
		}
					
						if(type[current_pokemon]==linear){ /*this is linear attack and i find enemy with respect to player*/
						p_range=range[current_pokemon];
							
							for(a=0;a<p_range+1;a++){
							
								if(area[y+a][x]>9){
									pokemon_staminas[y+a][x]=pokemon_staminas[y+a][x]-attack_power[current_pokemon];
									break;
								}
								if(area[y-a][x]>9){
									pokemon_staminas[y-a][x]=pokemon_staminas[y-a][x]-attack_power[current_pokemon];
									break;
								}
								if(area[y][x+a]>9){
									pokemon_staminas[y][x+a]=pokemon_staminas[y][x+a]-attack_power[current_pokemon];
									break;
								}
								if(area[y][x-a]>9){
									pokemon_staminas[y][x-a]=pokemon_staminas[y][x-a]-attack_power[current_pokemon];
									break;
								}
							}
			
						}
						if(type[current_pokemon]==quadratic){  /*this is quadratic attack and i find enemy with respect to player*/
						p_range=range[current_pokemon];
						for(a=0;a<p_range+1;a++){
								
								if(area[y+a][x]>9){
									pokemon_staminas[y+a][x]=pokemon_staminas[y+a][x]-attack_power[current_pokemon];
									
								}
								if(area[y-a][x]>9){
									pokemon_staminas[y-a][x]=pokemon_staminas[y-a][x]-attack_power[current_pokemon];
									
								}
								if(area[y][x+a]>9){
									pokemon_staminas[y][x+a]=pokemon_staminas[y][x+a]-attack_power[current_pokemon];
									
								}
								if(area[y][x-a]>9){
									pokemon_staminas[y][x-a]=pokemon_staminas[y][x-a]-attack_power[current_pokemon];
									
								}
							}

						}	

				random_ai=rand()%4;
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						if(area[i][j]==ai_pokemons[random_ai]){ /*I find enemy then i implement it*/
							y=i;
							x=j;
						}
					}

				}
				current_pokemon=area[y][x];
		if(area[y][x]!=-1 && area[y][x]>9){
				move=(rand()%4)+1;
				move=move*2;
				many=rand(); /*i give random numbers*/
				many=many%2;
				move_function(&x,&y,area,pokemon_staminas,move,many,current_pokemon);
						current_pokemon=current_pokemon-10;		
						if(type[current_pokemon]==linear){
						p_range=range[current_pokemon];
							
							for(a=0;a<p_range+1;a++){ /*this is linear attack and i find enemy with respect to enemy*/
								 
								if(area[y+a][x]<10 && area[y+a][x]>-1){
									pokemon_staminas[y+a][x]=pokemon_staminas[y+a][x]-attack_power[current_pokemon];
									break;
								}
								if(area[y-a][x]<10 &&  area[y-a][x]>-1){
									pokemon_staminas[y-a][x]=pokemon_staminas[y-a][x]-attack_power[current_pokemon];
									break;
								}
								if(area[y][x+a]<10 && area[y][x+a]>-1){
									pokemon_staminas[y][x+a]=pokemon_staminas[y][x+a]-attack_power[current_pokemon];
									break;
								}
								if(area[y][x-a]<10 && area[y][x-a]>-1){
									pokemon_staminas[y][x-a]=pokemon_staminas[y][x-a]-attack_power[current_pokemon];
									break;
								}
							}
			
						}
						if(type[current_pokemon]==quadratic){ /*this is quadratic attack  and i find enemy with respect to enemy*/
						p_range=range[current_pokemon];
						for(a=0;a<p_range+1;a++){
								
								if(area[y+a][x]<10 && area[y+a][x]>-1){
									pokemon_staminas[y+a][x]=pokemon_staminas[y+a][x]-attack_power[current_pokemon];
									
								}
								if(area[y-a][x]<10  && area[y-a][x]>-1){
									pokemon_staminas[y-a][x]=pokemon_staminas[y-a][x]-attack_power[current_pokemon];
									
								}
								if(area[y][x+a]<10 && area[y][x+a]>-1){
									pokemon_staminas[y][x+a]=pokemon_staminas[y][x+a]-attack_power[current_pokemon];
									
								}
								if(area[y][x-a]<10 && area[y][x-a]>-1){
									pokemon_staminas[y][x-a]=pokemon_staminas[y][x-a]-attack_power[current_pokemon];
									
								}
							}

						}

			
		 }
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if(pokemon_staminas[i][j]<=0){
						area[i][j]=-1;  /*If stamina is less or equal to 0 then it will lost*/
						pokemon_staminas[i][j]=-1;
					}
				}

			}

			
		
	
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if(area[i][j]!=-1){
					count=count+1;			/*if there is only 1 pokemon then game is over*/
					}
				}			


			}
		if(count==1){
			finish=0;		/*if finish is 0 then game is over*/
		}
		


	}	
	


}
void move_function(int *x,int *y,int area[][8],int pokemon_staminas[][8],int move,int many,int current_pokemon){

				if(many==0){					/*this is move function , it changing locates with respect to move */
						many=2;	
						}
				if(many==1){
						many=1;
					}
			switch (move){
				case 2: if(*y!=7){
						if(many==1){
							if(area[*y+many][*x]==-1){
								area[*y][*x]=-1;
								area[*y+many][*x]=current_pokemon;
								pokemon_staminas[*y+many][*x]=pokemon_staminas[*y][*x];
								pokemon_staminas[*y][*x]=-1;
								*y=*y+many;
							}
							else{
							printf("Player hit the pokemon and you lost your right now your turn\n");
							}
						}
						if(many==2){
							if(*y!=6){
								if(area[*y+many][*x]==-1){
									area[*y][*x]=-1;
									area[*y+many][*x]=current_pokemon;
									pokemon_staminas[*y+many][*x]=pokemon_staminas[*y][*x];
									pokemon_staminas[*y][*x]=-1;
									*y=*y+many;
								}
								else{
									printf("Player hit the pokemon and you lost your right now your turn\n");
									}
							}
							else{
							printf("Player hit the pokemon and you lost your right now your turn\n");
							}					
							
						}


					}
					else{
					printf("Player hit the wall and you lost your right now your turn\n");
					}	
					break;
				case 4: if(*x!=0){
						if(many==1){
							if(area[*y][*x-many]==-1){
								area[*y][*x]=-1;
								area[*y][*x-many]=current_pokemon;
								pokemon_staminas[*y][*x-many]=pokemon_staminas[*y][*x];
								pokemon_staminas[*y][*x]=-1;
								*x=*x-many;
								
							}
							else{
							printf("Player hit the pokemon and you lost your right now your turn\n");
							}
						}
						if(many==2){
							if(*x!=1){
								if(area[*y][*x-many]==-1){
								area[*y][*x]=-1;
								area[*y][*x-many]=current_pokemon;
								pokemon_staminas[*y][*x-many]=pokemon_staminas[*y][*x];
								pokemon_staminas[*y][*x]=-1;
								*x=*x-many;
								
								}
								else{
								printf("Player hit the pokemon and you lost your right now your turn\n");
								}
							
							}
							else{
							printf("Player hit the pokemon and you lost your right now your turn\n");
							}

						}
	
					}
					else{
					printf("Player hit the wall and you lost your right now your turn\n");
					}
					break;
				case 6: if(*x!=7){
						if(many==1){
							if(area[*y][*x+many]==-1){
								area[*y][*x]=-1;
								area[*y][*x+many]=current_pokemon;
								pokemon_staminas[*y][*x+many]=pokemon_staminas[*y][*x];
								pokemon_staminas[*y][*x]=-1;	
								*x=*x+many;
							}
							else{
							printf("Player hit the pokemon and you lost your right now your turn\n");
							}
						}
						if(many==2){
							if(*x!=6){
								if(area[*y][*x+many]==-1){
								area[*y][*x]=-1;
								area[*y][*x+many]=current_pokemon;
								pokemon_staminas[*y][*x+many]=pokemon_staminas[*y][*x];
								pokemon_staminas[*y][*x]=-1;	
								*x=*x+many;
								}
								else{
								printf("Player hit the pokemon and you lost your right now your turn\n");
								}
							}
							printf("Player hit the pokemon and you lost your right now your turn\n");
						}
 
					}
					else{
					printf("Player hit the wall and you lost your right now your turn\n");
					}
					break;
				case 8: if(*y!=0){
						if(many==1){
							if(area[*y-many][*x]==-1){
								area[*y][*x]=-1;
								area[*y-many][*x]=current_pokemon;
								pokemon_staminas[*y-many][*x]=pokemon_staminas[*y][*x];
								pokemon_staminas[*y][*x]=-1;
								*y=*y-many;
							}
							else{
							printf("Player hit the pokemon and you lost your right now your turn\n");
							}
						}
						if(many==2){
							if(*y!=1){
								if(area[*y-many][*x]==-1){
								area[*y][*x]=-1;
								area[*y-many][*x]=current_pokemon;
								pokemon_staminas[*y-many][*x]=pokemon_staminas[*y][*x];
								pokemon_staminas[*y][*x]=-1;
								*y=*y-many;
								}
								else{
								printf("Player hit the pokemon and you lost your right now your turn\n");
								}

							}
							else{
								printf("Player hit the pokemon and you lost your right now your turn\n");
								}
						}
					}
					else{
					printf("Player hit the wall and you lost your right now your turn\n");
					}
					break;
				default: printf("Player lost your right due to entering wrong direction\n");
			}


}

void show_area(char pokemon_name[][11],int area[][8],int pokemon_staminas[][8]){
 int i,j,p;
 int current;			/*this is show area function */

	for(i=0;i<8;i++){
		for(p=0;p<8*8+1;p++){
			printf("-");
			}
		printf("\n");		
			for(j=0;j<8;j++){
				if(area[i][j]>=10){
					area[i][j]=area[i][j]-10;
				}
				current=area[i][j];
				printf("|");
				if(area[i][j]==-1){
					printf("\t");			
				}
				if(area[i][j]!=-1 && area[i][j]<10){
					printf("  ");
					printf("%c",pokemon_name[current][0]);
					if(area[i][j]==4){
						printf("%c",pokemon_name[current][2]);
					}
					else{
					printf("%c",pokemon_name[current][1]);
					}
					printf("   ");
				}
			}
			printf("|");
			printf("\n");
			for(j=0;j<8;j++){
			current=pokemon_staminas[i][j];
				printf("|");
			if(pokemon_staminas[i][j]==-1){
					printf("\t");			
				}
				if(pokemon_staminas[i][j]!=-1){
					printf(" ");
					printf("(%4d)",pokemon_staminas[i][j]);
				}
			}
			printf("|");
			printf("\n");
	}
	for(p=0;p<8*8+1;p++){
			printf("-");
			}
	printf("\n");


}












