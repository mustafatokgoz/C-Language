#include<stdio.h>
#include<stdlib.h>
#include<time.h>
								/*Mustafa Tokgöz 171044077*/

typedef enum{
	Noone=0,Cap=1,Car=2			/*this is enumareter type for players*/
}player_type;

typedef enum{
	start=0,property=1,tax=2,punish=3		/*this is enumareter type for blocks*/
}block_type;

typedef struct{
	player_type type;
	int current_player_id;	
	int owned_block_ids[12];			/*this is struct for player that is given by the teacher*/
	int account;
	int turn_to_wait;
	char *name;
}player;

typedef struct{
	int block_id;
	char *name;
	int price;
	int rent;					/*this is struct for blocks that are given by the teacher*/
	int rent_1;
	int rent_2;
	int rent_3;
	int house_price;
	int house_count;
	player owner;
	block_type type;
}block;

void init_the_board(block board[20]){			/*this is fillin in the board all knowladge*/
int i;			
	board[0].price=0;
	board[1].price=16000;
	board[2].price=0;
	board[3].price=16500;
	board[4].price=17000;
	board[5].price=0;
	board[6].price=20000;
	board[7].price=23000;
	board[8].price=0;				
	board[9].price=30000;
	board[10].price=0;
	board[11].price=33000;
	board[12].price=0;
	board[13].price=35000;
	board[14].price=40000;
	board[15].price=0;
	board[16].price=43000;
	board[17].price=60000;
	board[18].price=0;
	board[19].price=70000;
	
	board[0].rent=0;
	board[1].rent=800;
	board[2].rent=1500;
	board[3].rent=850;
	board[4].rent=875;
	board[5].rent=2;
	board[6].rent=1000;
	board[7].rent=1100;
	board[8].rent=1750;
	board[9].rent=1350;
	board[10].rent=2000;
	board[11].rent=1500;
	board[12].rent=2250;
	board[13].rent=1600;
	board[14].rent=1750;
	board[15].rent=1;
	board[16].rent=1900;
	board[17].rent=2500;
	board[18].rent=5000;
	board[19].rent=3500;

	board[0].rent_1=0;
	board[1].rent_1=4000;
	board[2].rent_1=0;
	board[3].rent_1=4250;
	board[4].rent_1=4500;
	board[5].rent_1=0;
	board[6].rent_1=5000;
	board[7].rent_1=5500;
	board[8].rent_1=0;
	board[9].rent_1=7000;
	board[10].rent_1=0;
	board[11].rent_1=8000;
	board[12].rent_1=0;
	board[13].rent_1=8500;
	board[14].rent_1=9500;
	board[15].rent_1=0;
	board[16].rent_1=11000;
	board[17].rent_1=15000;
	board[18].rent_1=0;
	board[19].rent_1=20000;

	board[0].rent_2=0;
	board[1].rent_2=9000;
	board[2].rent_2=0;
	board[3].rent_2=9500;
	board[4].rent_2=10000;
	board[5].rent_2=0;
	board[6].rent_2=12000;
	board[7].rent_2=12500;
	board[8].rent_2=0;
	board[9].rent_2=15000;
	board[10].rent_2=0;
	board[11].rent_2=16000;
	board[12].rent_2=0;
	board[13].rent_2=17000;
	board[14].rent_2=19000;
	board[15].rent_2=0;
	board[16].rent_2=21500;
	board[17].rent_2=28000;
	board[18].rent_2=0;
	board[19].rent_2=35500;

	board[0].rent_3=0;
	board[1].rent_3=25000;
	board[2].rent_3=0;
	board[3].rent_3=26000;
	board[4].rent_3=28000;
	board[5].rent_3=0;
	board[6].rent_3=30000;
	board[7].rent_3=33000;
	board[8].rent_3=0;
	board[9].rent_3=40000;
	board[10].rent_3=0;
	board[11].rent_3=42000;
	board[12].rent_3=0;
	board[13].rent_3=45000;
	board[14].rent_3=48000;
	board[15].rent_3=0;
	board[16].rent_3=55000;
	board[17].rent_3=60000;
	board[18].rent_3=0;
	board[19].rent_3=65000;

	board[0].house_price=0;
	board[1].house_price=10000;
	board[2].house_price=0;
	board[3].house_price=12000;
	board[4].house_price=12000;
	board[5].house_price=0;
	board[6].house_price=13000;
	board[7].house_price=13000;
	board[8].house_price=0;
	board[9].house_price=15000;
	board[10].house_price=0;
	board[11].house_price=16000;
	board[12].house_price=0;
	board[13].house_price=17000;
	board[14].house_price=19000;
	board[15].house_price=0;
	board[16].house_price=23000;
	board[17].house_price=30000;
	board[18].house_price=0;
	board[19].house_price=35000;

	board[0].type=start;
	board[1].type=property;
	board[2].type=tax;
	board[3].type=property;
	board[4].type=property;
	board[5].type=punish;
	board[6].type=property;
	board[7].type=property;
	board[8].type=tax;
	board[9].type=property;
	board[10].type=tax;
	board[11].type=property;
	board[12].type=tax;
	board[13].type=property;
	board[14].type=property;
	board[15].type=punish;
	board[16].type=property;
	board[17].type=property;
	board[18].type=tax;
	board[19].type=property;

	board[0].block_id=0;
	board[1].block_id=1;
	board[2].block_id=2;
	board[3].block_id=3;
	board[4].block_id=4;
	board[5].block_id=5;
	board[6].block_id=6;
	board[7].block_id=7;
	board[8].block_id=8;
	board[9].block_id=9;
	board[10].block_id=10;
	board[11].block_id=11;
	board[12].block_id=12;
	board[13].block_id=13;
	board[14].block_id=14;
	board[15].block_id=15;
	board[16].block_id=16;
	board[17].block_id=17;
	board[18].block_id=18;
	board[19].block_id=19;
	
	board[0].name="Start";
	board[1].name="Esenyurt";
	board[2].name="Car Park";
	board[3].name="Tuzla";
	board[4].name="Arnavutkoy";
	board[5].name="Wait 2 Turn";
	board[6].name="Catalca";
	board[7].name="Beykoz";
	board[8].name="Car Fix";
	board[9].name="Maltepe";
	board[10].name="Bills";
	board[11].name="Sisli";
	board[12].name="Oil";
	board[13].name="Atasehir";
	board[14].name="Sariyer";
	board[15].name="Wait 1 Turn";
	board[16].name="Kadikoy";
	board[17].name="Besiktas";
	board[18].name="Vocation";
	board[19].name="Bebek";

	for(i=0;i<20;i++)	
		board[i].owner.type=Noone;		/*this is filling in owner type with Noone*/
	for(i=0;i<20;i++)	
		board[i].house_count=0;			/*this is filling in house counts with 0*/
}

void show_board(block board[20],player player_one,player player_two){	/*this is showing the board*/
int i,j,k=0,a=6,b;
	for(i=0;i<6;i++){
		if(i<2 || i>4){
			for(j=0;j<145;j++)		/*this is for first row and last row */
				printf("-");
				printf("\n");
		}
		if(i==0){				/*for the first row*/
			
			for(j=0;j<6;j++){
				printf("|");
				printf("%15s",board[j].name);		/*this is showing names*/
				printf("\t");
			}
			printf("|");
			printf("\n");

			for(j=0;j<6;j++){
				printf("|");
				if(board[j].price!=0 && board[j].type==property){
					printf("%14d$",board[j].price);		/*this is showing price of properties*/
					printf("\t");
				}
				else if(board[j].type==tax){
					printf("%14d$",board[j].rent);
					printf("\t");
				}
				else{
					printf("\t\t\t");
				}
			}
			printf("|");
			printf("\n");			
			
			for(j=0;j<6;j++){			/*this is showing players names*/
				printf("|");
				if(player_one.current_player_id==j && player_two.current_player_id==j){
					printf("%10s",player_one.name);
					printf("%10s",player_two.name);		
					printf("   ");
				}
				else if(player_one.current_player_id==j){
					printf("%15s",player_one.name);
					printf("\t");
				
				}
				else if(player_two.current_player_id==j){
					printf("%15s",player_two.name);
					printf("\t");
				
				}
				else {
					printf("\t\t\t");
					
				}
			}
			printf("|");
			printf("\n");
			
		}
		else if(i>0 && i<5){			/*this is for second third fourth and fifth row */
				printf("|");
				printf("%15s",board[19-k].name);	/*this is for left side*/
				printf("\t");
				printf("|");
				
				for(j=0;j<95;j++){
					printf(" ");
				}
				printf("|");
				printf("%15s",board[6+k].name);		/*this is for right side*/
				printf("\t");
				printf("|");
				printf("\n");				/*k is increasing 1 by 1*/

				printf("|");
				if(board[19-k].price!=0 && board[19-k].type==property){
					printf("%14d$",board[19-k].price);		/*this is for left side's price*/
					printf("\t");
				}
				else if(board[19-k].type==tax){
					printf("%14d$",board[19-k].rent);
					printf("\t");
				}
				else{
					printf("\t\t\t");
				}
				printf("|");
				for(j=0;j<95;j++){
					printf(" ");
				}
				printf("|");
				if(board[6+k].price!=0 && board[6+k].type==property){
					printf("%14d$",board[6+k].price);	/*this is for right side's price*/
					printf("\t");
				}
				else if(board[6+k].type==tax){
					printf("%14d$",board[6+k].rent);
					printf("\t");
				}
				else{
					printf("\t\t\t");
				}
				printf("|\n");
				printf("|");
				if(player_one.current_player_id==19-k && player_two.current_player_id==19-k){
					printf("%10s",player_one.name);		/*this is showing players names for left  if there are 2 players*/
					printf("%10s",player_two.name);
					printf("   ");
				}
				
				else if(player_one.current_player_id==19-k){		/*if there is first player*/
					printf("%15s",player_one.name);
					printf("\t");
				}
				else if(player_two.current_player_id==19-k){
					printf("%15s",player_two.name);			/*if there is second player*/
					printf("\t");
				}
				else {
					printf("\t\t\t");
					
				}
				printf("|");
				for(j=0;j<95;j++){
						printf(" ");
				}
				
				printf("|");
				if(player_one.current_player_id==6+k && player_two.current_player_id==6+k){
					printf("%10s",player_one.name);		/*this is showing players names for right if there are 2 players*/
					printf("%10s",player_two.name);
					printf("   ");
				}
				else if(player_one.current_player_id==6+k){		/*if there is first player*/
					printf("%15s",player_one.name);
					printf("\t");
				
				}
				else if(player_two.current_player_id==6+k){		/*if there is second player*/
					printf("%15s",player_two.name);
					printf("\t");
				
				}
				else {
					printf("\t\t\t");
					
				}
				printf("|\n");
				k++;
				if(i!=4){
					for(j=0;j<25;j++){
						printf("-");		/*this is printing middle side*/
					}
					for(j=0;j<95;j++){
						printf(" ");
					}
					for(j=0;j<25;j++){
						printf("-");
					}
					printf("\n");
				}
		}	
		if(i==5){			/*this is for last row*/
			
			for(j=15;j>9;j--){
				printf("|");
				printf("%15s",board[j].name);
				printf("\t");
			}
			printf("|");
			printf("\n");

			for(j=15;j>9;j--){
				printf("|");
				if(board[j].price!=0 && board[j].type==property){
					printf("%14d$",board[j].price);	/*this is printing prices*/
					printf("\t");
				}
				else if(board[j].type==tax){
					printf("%14d$",board[j].rent); /*if this is tax then printing rent*/
					printf("\t");
				}
				else{
					printf("\t\t\t");
				}
			}
			printf("|");
			printf("\n");			
			
			for(j=15;j>9;j--){
				printf("|");
				if(player_one.current_player_id==j && player_two.current_player_id==j){	/*this is prrinting names with decresing order 15th id 14th id*/
					printf("%10s",player_one.name);
					printf("%10s",player_two.name);
					printf("   ");
				}
				else if(player_one.current_player_id==j){
					printf("%15s",player_one.name);
					printf("\t");
				
				}
				else if(player_two.current_player_id==j){
					printf("%15s",player_two.name);
					printf("\t");
				
				}
				else {
					printf("\t\t\t");
					
				}
			}
			printf("|");
			printf("\n");
			
		}
	}
	for(j=0;j<145;j++)
		printf("-");	/*this is for last row's downside*/
	printf("\n");
}

void show_properties(block board[20]){		/*this is showing properties*/
int select=1,i;
		
	while(select!=0){
		printf("\nPlease select a property to see details:\n");
		for(i=0;i<20;i++){
			if(board[i].type==property){
				printf("%d - %s",i,board[i].name);
				printf("\n");		
			}
		}
		printf("0 - Exit\n");
		scanf("%d",&select);
		if(board[select].type==property){
			for(i=0;i<35;i++){		
				printf("-");
			}
			printf("\n|");
			printf("%21s",board[select].name);
			printf("\t\t  ");
			printf("|\n|");
			printf("\t Rent %14d$     ",board[select].rent);
			printf("|\n|");
			printf("\t Rent 1 H %10d$     ",board[select].rent_1);
			printf("|\n|");
			printf("\t Rent 2 H %10d$     ",board[select].rent_2);
			printf("|\n|");
			printf("\t Rent 3 H %10d$     ",board[select].rent_3);
			printf("|\n");
			for(i=0;i<35;i++){		
				printf("-");
			}
			printf("\n|");
			printf("\t House Price %10d$  ",board[select].house_price);
			printf("|\n");
			for(i=0;i<35;i++){		
				printf("-");
			}
		}		

	}

}
void menu(){					/*this is menu*/
	printf("1 - Roll the dice\n");
	printf("2 - Show my account\n");
	printf("3 - Show my properties\n");
	printf("4 - Show property deeds\n");
	printf("5 - Buy property\n");
	printf("6 - Buy house\n");
	printf("7 - Sell property\n");
	printf("Please select an option to continue:\n");	
}
void buy_property(block *current_block,player *current_player){ /*this is function for buying properties*/
int house=0;
	if(current_block->owner.type==Noone){		/*If this property is noone then it is working*/
		if(current_block->type==property){
			if(current_player->account>=current_block->price){
				current_block->owner.type=current_player->type;
				current_player->account=current_player->account-current_block->price;
				printf("You just only bought property \n Do you want to buy house\n İf yes enter 1  , If no enter  0\n");
				scanf("%d",&house);
				if(house==1){
					printf("How many house do you want (at most 3 house)\n");
					scanf("%d",&current_block->house_count);
					if(current_block->house_count<1 || current_block->house_count>3){
						printf("That is too much or too less to buy house so you bought only property\n");
						current_block->house_count=0;
					}
					else{
						if(current_player->account>=current_block->house_count*current_block->house_price){					
							current_player->account=current_player->account-(current_block->house_count*current_block->house_price);
						}
						else{
							current_block->house_count=0;
							printf("Your money is not enough!\n");				
						}
					}
				}
				else{
					printf("You just have bought only property , you haven't bought any house\n");
					}
			}
			else{
					printf("Your money is not enough!\n");			
			}		
		}
		else{
			printf("This is not property.\n");			
		}
	}
	else {
		printf("This is already bought\n");
	}

}

void sell_property(block board[20],player *current_player){ /*this is selling 1 property*/
int choice,i;
	printf("Which one property do you sell?\nEnter its id.\nIf you don't have any property enter 0\n");
	scanf("%d",&choice);
	if(choice==0)
		return;
	if(board[choice].owner.type==current_player->type){		/*If types are equal ,If this property is current's player property then*/
		board[choice].owner.type=Noone;				/*this means that this block is noone anymore*/
		current_player->account=current_player->account+(board[choice].price)/2+(board[choice].house_count)*(board[choice].house_price)/2;
		for(i=0;i<12;i++){
			if(current_player->owned_block_ids[i]==choice){		/*If owned block is equal to choice then it is doing -1  */
				current_player->owned_block_ids[i]=-1;
				break;
			}
		}
	}	
	else{
		printf("This id is not your properties' id\n");
	}




}
	
void buy_house(block *current_block,player *current_player){		/*this is buying a house*/
	if(current_block->owner.type==current_player->type){
		if(current_player->account>current_block->house_price){
			if(current_block->house_count<3){
				current_block->house_count=current_block->house_count+1;
				current_player->account=current_player->account-current_block->house_price;
				printf("You have bought a house \n");
			}
			else{
				printf("This has already maximum amount of house.\n");
			}
		}
		else{
			printf("Your money is not enough!\n");
			}
	}
	else{
			printf("This is not your property\n");
		}


}

void gameplay(block board[20],player player_one,player player_two){
int dice=-1;
int current_dice;
int selection=-1;				/*I did the game with one dice with 6 number*/
int i;
int temp_account;
int one_owned=0;		/*this is counting owned blocks  for putting properties to owned block ids[] array*/
int two_owned=0;		/*this is counting owned blocks  for putting properties to owned block ids[] array*/
int count_pun_1=0;			/*this is counting amount of punish*/
int count_pun_2=0;			/*this is counting amount of punish*/
int prop;
int a;			/*this is for that if the player has not enought money then it is selling properties ,this is counting properties*/
	show_board(board,player_one,player_two);		/*this is showing board*/
	while(player_one.account>0 && player_one.account>0){	/*if two players have enough money*/
		while(selection!=0){
			if(selection!=0){			
			menu();
			scanf("%d",&selection);
			}
			switch (selection){
				
				case 0:break;
				case 1: if(dice!=0){		/*this is rolling dice*/
						dice=(rand()%6)+1;					
						current_dice=dice;
						player_one.current_player_id=player_one.current_player_id+dice;	/*this is players current id*/
						
						if(player_one.current_player_id>19){	/*if player go start point then it gains 10000 money*/
							player_one.current_player_id=player_one.current_player_id%20; /*this is for current id*/
							player_one.account=player_one.account+10000;
						}
						
						if(board[player_one.current_player_id].owner.type==player_two.type){	/*if place is other's place then  it will pay */
							if(board[player_one.current_player_id].house_count==0){		/*if there is 0 house*/
								player_one.account=player_one.account-board[player_one.current_player_id].rent;
								player_two.account=player_two.account+board[player_one.current_player_id].rent; /*second player gains the manoy*/
							}
							if(board[player_one.current_player_id].house_count==1){ /*if there is 1 house*/
								player_one.account=player_one.account-board[player_one.current_player_id].rent_1;
								player_two.account=player_two.account+board[player_one.current_player_id].rent_1;
							}
							if(board[player_one.current_player_id].house_count==2){ /*if there is 2 house*/
								player_one.account=player_one.account-board[player_one.current_player_id].rent_2;
								player_two.account=player_two.account+board[player_one.current_player_id].rent_2;
							}
							if(board[player_one.current_player_id].house_count==3){ /*if there is 3 house*/
								player_one.account=player_one.account-board[player_one.current_player_id].rent_3;
								player_two.account=player_two.account+board[player_one.current_player_id].rent_3;
							}
							
						}
						else if(board[player_one.current_player_id].type==tax){
							player_one.account=player_one.account-board[player_one.current_player_id].rent; /*if place is tax then you must pay*/
						}
						
						if(player_one.account<0){
							do{
								prop=0;		/*if player one has not enough money then it is selling properties*/
								for(i=0;i<12;i++){
									if(player_one.owned_block_ids[i]!=-1){
										prop=prop+1;  /*this is counting properties*/
									}								
								}
								if(prop==0){  /*if there is any property then player is loosing*/
									break;
								}
							for(i=0;i<12;i++){
						if(player_one.owned_block_ids[i]!=-1){
		printf("%d - %s  with %d-House\n",player_one.owned_block_ids[i],board[player_one.owned_block_ids[i]].name,board[player_one.owned_block_ids[i]].house_count);
						}
							}
							sell_property(board,&player_one);
								
							}
							while(player_one.account<0 && prop>0);

						}
						if(board[player_one.current_player_id].owner.type==player_one.type){
							show_board(board,player_one,player_two);
							for(i=0;i<3;i++){
								printf("Do you want to buy a house\n");
								printf("If yes enter 1 ,else enter 0\n");
								scanf("%d",&a);
								if(a==1){
									buy_house(&board[player_one.current_player_id],&player_one);
								}
								else{
									break;
								}
							}							
	
						}
						
						if(board[player_one.current_player_id].owner.type==Noone && board[player_one.current_player_id].type==property){
							show_board(board,player_one,player_two);
							printf("Do you want to  buy property\n");
							printf("If yes enter 1 , else enter 0\n");
							scanf("%d",&a);
							if(a==1){
							
					temp_account=player_one.account;		/*if player one has diffent money than previus , that means player buy the property*/
					buy_property(&board[player_one.current_player_id],&player_one);
						if(player_one.account!=temp_account){		/*so it puts to players owned block ids[] arrays */
							player_one.owned_block_ids[one_owned]=board[player_one.current_player_id].block_id;
							one_owned=one_owned+1; /*then it increase arrays number*/
						}
							selection=0;
							if(count_pun_1==0){
									break;
								}
							}
							else{
								selection=0;
								if(board[player_two.current_player_id].type!=punish){
									break;
								}
								}

						}
						if(board[player_one.current_player_id].type==punish && board[player_two.current_player_id].type==punish){
							
							count_pun_1=count_pun_1+board[player_two.current_player_id].rent;/*if thay are in the wait turns*/

						}
						if(board[player_two.current_player_id].type==punish){		/*if second player take punish then first player is playing  again*/
							if(board[player_one.current_player_id-current_dice].type==punish || board[player_one.current_player_id].type==punish){
									count_pun_1=count_pun_1+board[player_two.current_player_id].rent;
							}
								dice=-1;
								count_pun_1=count_pun_1+1;
								selection=1;
								if(count_pun_1>=board[player_two.current_player_id].rent+1){
									dice=0;
									count_pun_1=0;
									selection=0;				
								}
						}
						else{
								selection=0;
								break;
						}
					}
					else{
						selection=0;
					}
					
					break;
				case 2: printf("my account is= %d$\n",player_one.account); /*this is showing account*/
					break;
				case 3: for(i=0;i<12;i++){
						if(player_one.owned_block_ids[i]!=-1){
		printf("%d - %s  with %d-House\n",player_one.owned_block_ids[i],board[player_one.owned_block_ids[i]].name,board[player_one.owned_block_ids[i]].house_count);
						}		/*this is showing properties that player has*/
					}
					break;
				case 4:show_properties(board);		/*this is showing properties*/
					break;
				case 5: temp_account=player_one.account;		/*if player one has diffent money than previus , that means player buy the property*/
					buy_property(&board[player_one.current_player_id],&player_one);
					if(player_one.account!=temp_account){		/*so it puts to players owned block ids[] arrays */
						player_one.owned_block_ids[one_owned]=board[player_one.current_player_id].block_id;
						one_owned=one_owned+1; /*then it increase arrays number*/
					}
					break;
				case 6: buy_house(&board[player_one.current_player_id],&player_one);	/*this is buying a house */
					break;
				case 7: for(i=0;i<12;i++){
						if(player_one.owned_block_ids[i]!=-1){
		printf("%d - %s  with %d-House\n",player_one.owned_block_ids[i],board[player_one.owned_block_ids[i]].name,board[player_one.owned_block_ids[i]].house_count);
						}
					}
					sell_property(board,&player_one); /*this is selling properties*/
					break;
				default:printf("only  select 0 to 7 \n");
			}
				show_board(board,player_one,player_two);
				if(player_one.account<0 || player_two.account<0){
					break;		/*if player is lost*/
				}
					
		}
		if(player_one.account<0){
			printf("The Winner Is %s\n",player_two.name);
			break;		/*this is saying winner*/
		}
		else if(player_two.account<0){
			printf("The Winner Is %s\n",player_one.name);
			break;
		}
		dice=-1;
		selection=1;
		printf("Now Turn is Car player\n");
		
		while(selection!=0){  /*this is provide that turn is others turn */
				
				if(selection!=0){			
			menu();
			scanf("%d",&selection);
			}
					
			switch (selection){			/*these are reverse of upper player one's features*/
				
				case 0:break;
				case 1: if(dice!=0){
						dice=(rand()%6)+1;	
						current_dice=dice;
						player_two.current_player_id=player_two.current_player_id+dice;
						if(player_two.current_player_id>19){
							player_two.current_player_id=player_two.current_player_id%20;
							player_two.account=player_two.account+10000;
						}
					if(board[player_two.current_player_id].owner.type==player_one.type){
							if(board[player_two.current_player_id].house_count==0){
								player_two.account=player_two.account-board[player_two.current_player_id].rent;
								player_one.account=player_one.account+board[player_two.current_player_id].rent;
							}
							if(board[player_two.current_player_id].house_count==1){
								player_two.account=player_two.account-board[player_two.current_player_id].rent_1;
								player_one.account=player_one.account+board[player_two.current_player_id].rent_1;
							}
							if(board[player_two.current_player_id].house_count==2){
								player_two.account=player_two.account-board[player_two.current_player_id].rent_2;
								player_one.account=player_one.account+board[player_two.current_player_id].rent_2;
							}
							if(board[player_two.current_player_id].house_count==3){
								player_two.account=player_two.account-board[player_two.current_player_id].rent_3;
								player_one.account=player_one.account+board[player_two.current_player_id].rent_3;
							}
							
						}
						else if(board[player_two.current_player_id].type==tax){
							player_two.account=player_two.account-board[player_two.current_player_id].rent;
						}
						if(player_two.account<0){
							do{
								prop=0;
								for(i=0;i<12;i++){
									if(player_one.owned_block_ids[i]!=-1){
										prop=prop+1;
									}								
								}
								if(prop==0){
									break;
								}
								
							for(i=0;i<12;i++){
						if(player_two.owned_block_ids[i]!=-1){
		printf("%d - %s  with %d-House\n",player_two.owned_block_ids[i],board[player_two.owned_block_ids[i]].name,board[player_two.owned_block_ids[i]].house_count);
						}
							}
							sell_property(board,&player_two);
								
							}
							while(player_one.account<0 && prop>0);
							

						}
						if(board[player_two.current_player_id].owner.type==player_two.type){
							show_board(board,player_one,player_two);
							for(i=0;i<3;i++){
								printf("Do you want to buy a house\n");
								printf("If yes enter 1 ,else enter 0\n");
								scanf("%d",&a);
								if(a==1){
									buy_house(&board[player_two.current_player_id],&player_two);
								}
								else{
									break;
								}
							}							
	
						}
						if(board[player_two.current_player_id].owner.type==Noone && board[player_two.current_player_id].type==property){
							show_board(board,player_one,player_two);
							printf("Do you want to buy property\n");
							printf("If yes enter 1 , else enter 0\n");
							scanf("%d",&a);
							if(a==1){
								
								temp_account=player_two.account;
								buy_property(&board[player_two.current_player_id],&player_two);
								if(player_two.account!=temp_account){
									player_two.owned_block_ids[two_owned]=board[player_two.current_player_id].block_id;
									two_owned=two_owned+1;
								}
								selection=0;
								if(board[player_one.current_player_id].type!=punish){
									break;
								}
							}
							else{
								selection=0;
								if(board[player_one.current_player_id].type!=punish){
									break;
								}
								}	
							}
						if(board[player_one.current_player_id].type==punish && board[player_two.current_player_id].type==punish){
							
							count_pun_2=count_pun_2+board[player_one.current_player_id].rent;

						}
						if(board[player_one.current_player_id].type==punish){
							if(board[player_two.current_player_id-current_dice].type==punish || board[player_two.current_player_id].type==punish){
									count_pun_2=count_pun_2+board[player_one.current_player_id].rent;
							}
								dice=-1;
								count_pun_2=count_pun_2+1;
								selection=1;
								if(count_pun_2>=board[player_one.current_player_id].rent+1){
									dice=0;
									selection=0;
									count_pun_2=0;				
								}
								
						}
						else {
								selection=0;
								break;
						}	

					}
						
					
					else {	
						selection=0;
					}
					break;
				case 2: printf("my account is= %d$\n",player_two.account);
					break;
				case 3: for(i=0;i<12;i++){
						if(player_two.owned_block_ids[i]!=-1){
		printf("%d - %s  with %d-House\n",player_two.owned_block_ids[i],board[player_two.owned_block_ids[i]].name,board[player_two.owned_block_ids[i]].house_count);
						}
					}
					break;
				case 4:show_properties(board);
					break;
				case 5: temp_account=player_two.account;
					buy_property(&board[player_two.current_player_id],&player_two);
					if(player_two.account!=temp_account){
						player_two.owned_block_ids[two_owned]=board[player_two.current_player_id].block_id;
						two_owned=two_owned+1;
					}
					break;
				case 6: buy_house(&board[player_two.current_player_id],&player_two);
					break;
				case 7:	for(i=0;i<12;i++){
						if(player_two.owned_block_ids[i]!=-1){
		printf("%d - %s  with %d-House\n",player_two.owned_block_ids[i],board[player_two.owned_block_ids[i]].name,board[player_two.owned_block_ids[i]].house_count);
						}
					}
					sell_property(board,&player_two);
					break;
				default:printf("only  select 0 to 7 \n");
			}
				
			show_board(board,player_one,player_two);
			if(player_two.account<0 || player_one.account<0){
					break;
				}
			
				
		}
		if(player_one.account<0){
			printf("The Winner Is %s\n",player_two.name);
			break;
		}
		else if(player_two.account<0){
			printf("The Winner Is %s\n",player_one.name);
			break;
		}
		selection=1;			/*this provides values to be previus 's*/
		dice=-1;
		printf("Now Turn is Cap player\n");
	}

	


}
int main(){
int i;
srand(time(NULL));			/*this is for random number*/
block board[20];
player player_one;
player player_two;
player_one.type=Cap;
player_two.type=Car;
	player_one.name="Cap";		/*this is first players name*/
	player_two.name="Car";		/*this is second players name*/
	player_one.current_player_id=0;		/*initials current ids*/
	player_two.current_player_id=0;
	player_one.account=100000;		/*this is amount of money of players*/
	player_two.account=1000;
		
	for(i=0;i<12;i++)
		player_one.owned_block_ids[i]=-1;	/*this is filling -1 for initial */
	for(i=0;i<12;i++)
		player_two.owned_block_ids[i]=-1;	/*this is filling -1 for initial */
	init_the_board(board);				/*this is init funtion*/
	gameplay(board,player_one,player_two);		/*this is gameplay function*/

}
