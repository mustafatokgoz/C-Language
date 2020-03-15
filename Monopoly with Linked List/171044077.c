#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define PROPERTY_COUNT 13			/*Mustafa Tokgöz 171044077*/
typedef enum block_type{start=0,property,fortune,tax,punish}b_type;  /*this is block enumarater types*/
typedef enum player_type{none=-1,car,cap}player_type;   		/*this is player enumarater types*/

typedef struct
{
	player_type type;
	int current_block_id;
	int owned_blocks[PROPERTY_COUNT];		/*this is strruct for player*/
	int account;
	int turn_to_wait;
	char *player_name;
} player;

typedef struct block
{
    int id;
    char * name;
    int price;				/*this is struct for blocks*/
    int rent;
    int rent_1;
    int rent_2;
    int rent_3;
    int house_price;
    int h_count;
	struct block *next;		/*this is for linklist*/
    player owner;
    b_type type;
} block;

typedef struct fortune_card{
	char *name;			/*this is fortune card struct*/
	struct fortune_card *next;
}fortune_card;

int roll_dice()
{

    int i=rand()%6+1;
    return i;
}

void show_property_deed(block *board)			/*this function shows property deeds*/
{
block *temp=board;

    int exit_flag=0,i,selection;
    while (exit_flag==0)
    {
        printf("Please select a property to see details:\n");
        for (i = 0; i < 24; ++i) {
            if (temp->type==property)
                printf("%d -\t%s \n",temp->id,temp->name);
		temp=temp->next;
        }
	temp=board;
        printf("0 -\tExit\n");
        scanf("%d",&selection);
	for(i=0;i<selection;i++){
		temp=temp->next;
	}
        if (selection==0)
            exit_flag=1;
        else {
            if (selection > 0 && selection < 24 && temp->type == property) {
                printf("\n\n---------------------------------\n");
                if (strlen(temp->name) < 8)
                    printf("|\t\t%s\t\t|\n", temp->name);
                else
                    printf("|\t    %s\t\t|\n", temp->name);
                printf("---------------------------------\n");
                printf("|\tRent \t\t%d$\t|\n", temp->rent);
                printf("|\tRent 1 H \t%d$\t|\n", temp->rent_1);
                printf("|\tRent 2 H \t%d$\t|\n", temp->rent_2);
                printf("|\tRent 3 H \t%d$\t|\n", temp->rent_3);
                printf("---------------------------------\n");
                printf("|\tHouse Price \t%d$\t|\n", temp->house_price);
                printf("|\tHouse count \t%d\t|\n", temp->h_count);
                printf("---------------------------------\n\n\n");
            } else printf("\nWrong Selection! Please Try Again.\n\n");
        }
	temp=board;
    }
}

void show_board(block *board, player player_one, player player_two) /*this is showing board with LINKEDLIST*/
{
block *temp=board;
block *temp2=board;	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int i=0,space_flag=0,j,k=0;
	for (i=0;i<7;i++)		
	{
		
        if (strlen(temp->name)<8)
		    printf("|\t%s\t\t",temp->name);	/*this is for first row*/
        else
            printf("|\t%s\t",temp->name);
	temp=temp->next;			/*this is showing  list's next*/
	}
	printf("|\n");
	temp=board;				/*this is beginning adress for list */
	for (i=0;i<7;i++)
	{
		if (temp->type==property || temp->type==tax)
		    printf("|\t%d$ \t\t",temp->price);
		else if (strlen(temp->name)<8)			/*this is showing prices*/
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
	temp=temp->next;
	}
    printf("|\n");
	temp=board;
    for (i=0;i<7;i++)
    {
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.player_name);		/*this is showing player names*/
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(temp->name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }
	temp=temp->next;
    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	temp=board;
	temp2=board;
    /* this is Middle part */
    for (i=0;i<5;i++)
    {
        				/* these are block names  for left side*/
        for(j=0;j<23-i;j++){
		temp2=temp2->next;		/*this is going when it reaches the current block*/
	}
        if (strlen(temp2->name)<8)
            printf("|\t%s\t\t|",temp2->name);
        else
            printf("|\t%s\t|",temp2->name);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	for(j=0;j<i+7;j++){
		temp=temp->next;			/*these thing is part of linked list*/
	}

        if (strlen(temp->name)<8)
            printf("|\t%s\t\t|",temp->name);
        else
            printf("|\t%s\t|",temp->name);
        printf("\n");
        					/*these are prices for middle */
        if (temp2->type==property || temp2->type==tax)
            printf("|\t%d$ \t\t|",temp2->price);
        else if (strlen(temp2->name)<8)
            printf("|\t     \t|");
        else
            printf("|\t\t \t|");


        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        if (temp->type==property || temp->type==tax)
            printf("|\t%d$ \t\t",temp->price);
        else if (strlen(temp->name)<8)
            printf("|\t     \t");
        else
            printf("|\t\t \t");

        printf("|\n");
        					/* these are spaces */

        space_flag=0;
        printf("|\t");
        if (23-i==player_one.current_block_id && 23-i==player_two.current_block_id)
        {
            printf("%s, %s \t|",player_one.player_name,player_two.player_name);
            space_flag=1;						/*these are players names for left side*/
        }
        else {
            if (23 - i == player_one.current_block_id) {
                printf("%s \t\t|", player_one.player_name);
                space_flag = 1;
            }
            if (23 - i == player_two.current_block_id) {
                printf("%s \t\t|", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(temp2->name)<8)
                printf("\t\t|");
            else
                printf("    \t\t|");
        }

        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        space_flag=0;
        printf("|\t");
        if (7+i==player_one.current_block_id && 7+i==player_two.current_block_id)   /* these are block names  for right side*/
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {

            if (7+i==player_one.current_block_id)
            {
                printf("%s \t\t",player_one.player_name);
                space_flag=1;
            }
            if (7+i==player_two.current_block_id)
            {
                printf("%s \t\t",player_two.player_name);
                space_flag=1;
            }
        }

        if (space_flag==0) {
            if (strlen(temp->name)<8)
                printf("\t\t");
            else
                printf("    \t\t");
        }

        printf("|\n");
        if (i!=4) {
            printf("-------------------------");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            printf("-------------------------");
            printf("\n");
        }
	temp=board;
	temp2=board;

    }

    /*this is bottom row */
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	temp=board;
	temp2=board;		/*this is begining  adress of board*/
    for (i=18;i>=12;i--)
    {
	for(k=0;k<i;k++){
		temp=temp->next;			/*this is linkedlist's part*/				
	}					/*this is going when it reaches the current block*/
        if (strlen(temp->name)<8)
            printf("|\t%s\t\t",temp->name);
        else
            printf("|\t%s\t",temp->name);
	temp=board;
    }
	temp2=board;
    printf("|\n");
    for (i=18;i>=12;i--)
    {
	for(k=0;k<i;k++){
		temp2=temp2->next;  		/*this is going when it reaches the current block*/
	}
        if (temp2->type==property || temp2->type==tax)
            printf("|\t%d$ \t\t",temp2->price);
        else if (strlen(temp2->name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
	temp2=board;
    }
    printf("|\n");
	temp2=board;
    for (i=18;i>=12;i--)
    {
	for(k=0;k<i;k++){
		temp2=temp2->next;			/*this is going when it reaches the current block*/
	}
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.player_name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(temp2->name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }
	temp2=board;

    }
    printf("|\n");  
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void init_board(block *board)		/*this is filling board with LINKEDLIST*/
{
    block *temp=board;
	int i;
	
    temp->id=0;
    temp->name="Start";
    temp->price=0;
    temp->rent=0;
    temp->rent_1=0;
    temp->rent_2=0;
    temp->rent_3=0;
    temp->house_price=0;
    temp->h_count=0;
    temp->type=start;
    
    
    temp->next=(block *)malloc(sizeof(block));		/*this is allocating  for board*/
    temp=temp->next;					/*board's next is board so that it fills in order*/
    temp->type=property;

    temp->id=1;
    temp->name="Esenyurt";
    temp->price=16000;
    temp->rent=800;
    temp->rent_1=4000;
    temp->rent_2=9000;
    temp->rent_3=25000;
    temp->house_price=10000;
    temp->h_count=0;
	

    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=tax;
    temp->name="Car park";
    temp->id=2;
    temp->price=1500;
   
    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
	 temp->type=fortune;
	    temp->id=3;
	    temp->name="Fortune Card";
	    temp->price=0;
	    temp->rent=0;
	    temp->rent_1=0;
	    temp->rent_2=0;
	    temp->rent_3=0;
	    temp->house_price=0;
	    temp->h_count=0;
    
     temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property;
	  temp->id=4;
    temp->name="Tuzla";
    temp->price=16500;
    temp->rent=850;
    temp->rent_1=4250;
    temp->rent_2=9500;
    temp->rent_3=26000;
    temp->house_price=12000;
    temp->h_count=0;
  
    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property;
    temp->id=5;
    temp->name="Arnavutkoy";
    temp->price=17000;
    temp->rent=850;
    temp->rent_1=4500;
    temp->rent_2=10000;
    temp->rent_3=28000;
    temp->house_price=12000;
    temp->h_count=0;
   

    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
     temp->type=punish;
    temp->name="Wait 2 turn";
    temp->price=2;
    temp->id=6;


    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property;  
    temp->id=7;
    temp->name="Catalca";
    temp->price=20000;
    temp->rent=1000;
    temp->rent_1=5000;
    temp->rent_2=12000;
    temp->rent_3=30000;
    temp->house_price=13000;
    temp->h_count=0;
    

    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property;  
    temp->id=8;
    temp->name="Beykoz";
    temp->price=23000;
    temp->rent=1100;
    temp->rent_1=5500;
    temp->rent_2=12500;
    temp->rent_3=33000;
    temp->house_price=13000;
    temp->h_count=0;
    

	temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=fortune;
    temp->id=9;
    temp->name="Fortune Card";
    temp->price=0;
    temp->rent=0;
    temp->rent_1=0;
    temp->rent_2=0;
    temp->rent_3=0;
    temp->house_price=0;
    temp->h_count=0;

    temp->next=(block *)malloc(sizeof(block));
   temp=temp->next;
	temp->type=tax;
    temp->name="Car fix";
    temp->id=10;
    temp->price=1750;
	 

    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property; 
    temp->id=11;
    temp->name="Maltepe";
    temp->price=30000;
    temp->rent=1350;
    temp->rent_1=7000;
    temp->rent_2=15000;
    temp->rent_3=40000;
    temp->house_price=15000;
    temp->h_count=0;


    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=tax; 
    temp->name="Bills";
    temp->id=12;
    temp->price=2000;
    

    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property; 
    temp->id=13;
    temp->name="Sisli";
    temp->price=33000;
    temp->rent=1500;
    temp->rent_1=8000;
    temp->rent_2=16000;
    temp->rent_3=42000;
    temp->house_price=16000;
    temp->h_count=0;
    


      temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=tax; 
    temp->name="Oil";
    temp->id=14;
    temp->price=2250;
 

    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=fortune;
    temp->id=15;
    temp->name="Fortune Card";
    temp->price=0;
    temp->rent=0;
    temp->rent_1=0;
    temp->rent_2=0;
    temp->rent_3=0;
    temp->house_price=0;
    temp->h_count=0;
    
	temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property; 
    temp->id=16;
    temp->name="Atasehir";
    temp->price=35000;
    temp->rent=1600;
    temp->rent_1=8500;
    temp->rent_2=17000;
    temp->rent_3=45000;
    temp->house_price=17000;
    temp->h_count=0;
    
    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property; 
    temp->id=17;
    temp->name="Sariyer";
    temp->price=40000;
    temp->rent=1750;
    temp->rent_1=9500;
    temp->rent_2=19000;
    temp->rent_3=48000;
    temp->house_price=19000;
    temp->h_count=0;
    
    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=punish;
	temp->name="Wait 1 turn";
	temp->price=1;
    temp->id=18;

    
    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property;
    temp->id=19;
    temp->name="Kadikoy";
    temp->price=43000;
    temp->rent=1900;
    temp->rent_1=11000;
    temp->rent_2=21500;
    temp->rent_3=55000;
    temp->house_price=23000;
    temp->h_count=0;
    
    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property;
    temp->id=20;
    temp->name="Besiktas";
    temp->price=60000;
    temp->rent=2500;
    temp->rent_1=15000;
    temp->rent_2=28000;
    temp->rent_3=60000;
    temp->house_price=30000;
    temp->h_count=0;
    

     temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=fortune;
     temp->id=21;
    temp->name="Fortune Card";
    temp->price=0;
    temp->rent=0;
    temp->rent_1=0;
    temp->rent_2=0;
    temp->rent_3=0;
    temp->house_price=0;
    temp->h_count=0;

    
    
	temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
	temp->type=tax;
	temp->name="Vocation";
    temp->id=22;
    temp->price=5000;

    temp->next=(block *)malloc(sizeof(block));
    temp=temp->next;
    temp->type=property;
   temp->id=23;
    temp->name="Bebek";
    temp->price=70000;
    temp->rent=3500;
    temp->rent_1=20000;
    temp->rent_2=35500;
    temp->rent_3=65000;
    temp->house_price=35000;
    temp->h_count=0;
    
    temp->next=(block *)malloc(sizeof(block));
    temp->next=NULL;
	
	temp=board;
	for(i=0;i<24;i++){	
		temp->owner.type=none;
		temp=temp->next;
	}		/*this is filling in owner type with Noone*/
	temp=board;
	for(i=0;i<24;i++){	
		temp->h_count=0;			/*this is filling in house counts with 0*/
		temp=temp->next;	
	}
	
}

void show_player_properties(block *board, player current_player) /*this is showing player's properties*/
{
    int i,counter=0,selection,j;
    block *temp=board;
    while (selection!=0) {
        printf("----------------------------------------\n");
        for (i = 0; i < PROPERTY_COUNT; i++) {
            if (current_player.owned_blocks[i] != -1) {
		for(j=0;j<current_player.owned_blocks[i];j++){
				temp=temp->next;
		}
                printf("%d - %s\n", temp->id,temp->name);
                counter++;
            }
	    temp=board;

        }
        if (counter == 0)
        {
            printf("You have not owned any property yet.\n");
            printf("----------------------------------------\n");
            selection=0;
        }
        else
        {   
	    temp=board;
            printf("0 - Back \n");
            printf("----------------------------------------\n");
            printf("Please select an property to see details.\n");
            scanf("%d", &selection);
	    for(j=0;j<selection;j++){
			temp=temp->next;
		}

            if (selection!=0) {
                if (temp->owner.type != current_player.type)
                    printf("You made a wrong selection!\n");
                else {
                    printf("\n\n---------------------------------\n");
                    if (strlen(temp->name) < 8)
                        printf("|\t\t%s\t\t|\n", temp->name);
                    else
                        printf("|\t    %s\t\t|\n", temp->name);
                    printf("---------------------------------\n");
                    printf("|\tRent \t\t%d$\t|\n", temp->rent);
                    printf("|\tRent 1 H \t%d$\t|\n", temp->rent_1);
                    printf("|\tRent 2 H \t%d$\t|\n", temp->rent_2);
                    printf("|\tRent 3 H \t%d$\t|\n", temp->rent_3);
                    printf("---------------------------------\n");
                    printf("|\tHouse Price \t%d$\t|\n", temp->house_price);
                    printf("|\tHouse count \t%d\t|\n", temp->h_count);
                    printf("---------------------------------\n\n\n");
                }
            }
	  temp=board;
        }

	temp=board;
    }

}

int build_house(block* current_block, player* current_player)		/*this is building house*/
{
    int flag=0;
    if (current_player->type==current_block->owner.type)
    {
        if (current_block->h_count<3)
        {
            if (current_block->house_price<=current_player->account)
            {
                flag=1;
                current_player->account-=current_block->house_price;
                current_block->h_count+=1;
            }
            else
                printf("You don't have enough money to build house!\n");
        }
        else
            printf("You can't buy more than 3 houses in a property!\n");
    }
    else
        printf("You don't have permission to build house on this property!\n ");
    return flag;
}

int count_properties(player current_player)		/*this is counting properties*/
{
    int i,count=0;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        if (current_player.owned_blocks[i]!=-1)
            count++;
    }
    return count;
}

void sell_property(block *board, player* current_player) /*this is selling properties*/
{
    int property_id,flag=0,is_owned=-1,i,index,counter=0,j;
    block *t_b=board;				/*this is for linkedlist*/
        if (count_properties(*current_player)!=0)
        {
            for (i = 0; i < PROPERTY_COUNT; i++) {
		for(j=0;j<current_player->owned_blocks[i];j++){
			t_b=t_b->next;			/*this is going when it reaches the current block*/
		}
                if (current_player->owned_blocks[i] != -1) {
                    printf("%d - %s\n", t_b->id,t_b->name);
                    counter++;
                }
		t_b=board;

            }
            printf("0 - Back\n");
            printf("Please select to sell the property:\n");

            scanf("%d",&property_id);
            if (property_id!=0)
            {
                for(i=0;i<PROPERTY_COUNT;i++)
                {
                    if (current_player->owned_blocks[i]==property_id)
                    {
                        is_owned=1;
                        index=i;
                        break;
                    }
                }
		t_b=board;
                if(is_owned!=-1)
                {
		    for(j=0;j<property_id;j++){
			t_b=t_b->next;
		    }
                    current_player->owned_blocks[index]=-1;
                    player temp;
                    t_b->owner.type=none;
                    if(t_b->h_count==0)current_player->account+=t_b->price/2;
                    if(t_b->h_count==1)
                    {
                        current_player->account+=(t_b->price+t_b->house_price)/2;
                    }
                    if(t_b->h_count==2)
                    {
                        current_player->account+=(t_b->price+(2*t_b->house_price))/2;
                    }
                    if(t_b->h_count==3)
                    {
                        current_player->account+=(t_b->price+(3*t_b->house_price))/2;
                    }
                }
		t_b=board;
            }
	t_b=board;
        } else
        {
            printf("You don't have any property to sell.\n");
        }

}

int insufficient_fund(block *board, player* current_player,int required_money)	/*this is when money is not enough*/
{
    int selection,flag=1,i,number=24,j,is_owned=-1,index;
	block *temp=board;
if(current_player->type==car){			/*this is for player that conrols us*/
    while (selection!=4 && current_player->account<required_money && count_properties(*current_player)!=0)
    {
        printf("You don't have enough money to continue your transaction.You need %d$ more. Please select an option to continue: \n",required_money-current_player->account);
        printf("1- Sell Property\n");
        printf("2- Show my Properties\n");
        printf("3- Show my Account\n");
        printf("0- Back\n");
        scanf("%d",&selection);
        switch (selection)
        {
            case 1:
                sell_property(board,current_player);
                break;
            case 2:
                show_player_properties(board,*current_player);
                break;
            case 3:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 0:
                flag=0;
                break;
            default:
                printf("You made a wrong selection!\n");
                break;

        }
    }
}
else{			/*this is for computer player*/
	while(current_player->account<required_money && count_properties(*current_player)!=0){
			for(j=0;j<24;j++){		/*It sells highest price property that it has*/
				temp=board;		
				for(i=0;i<number;i++){		/*So I decreases number one by one */
					temp=temp->next;	/*this is going when it reaches the current block*/
				}
					for(i=0;i<PROPERTY_COUNT;i++)
					{
					    if (current_player->owned_blocks[i]==number)
					    {
						is_owned=1;
						index=i;
						break;
					    }
					}
					if(is_owned!=-1)
					{
					    current_player->owned_blocks[index]=-1;
					    temp->owner.type=none;
					    if(temp->h_count==0)current_player->account+=temp->price/2;
					    if(temp->h_count==1)
					    {
						current_player->account+=(temp->price+temp->house_price)/2;
					    }
					    if(temp->h_count==2)
					    {
						current_player->account+=(temp->price+(2*temp->house_price))/2;
					    }
					    if(temp->h_count==3)
					    {
						current_player->account+=(temp->price+(3*temp->house_price))/2;
					    }
						printf("\nComputer sold his property %s \n",temp->name);
					   break;
					}
			temp=board;
			number--;
			}
		}
	


}

    return flag;

}

void pay_rent(block *board, player* current_player,player * owner) /*this is for rents*/
{
    int rent=0,owned_property_count,i;
    block *temp=board;
    for(i=0;i<current_player->current_block_id;i++){
       		temp=temp->next;			/*this is going when it reaches the current block with linkedlist*/
    }
    rent=temp->rent;
    if (temp->h_count==1)rent=temp->rent_1;
    if (temp->h_count==2)rent=temp->rent_2;
    if (temp->h_count==3)rent=temp->rent_3;
    if (rent>current_player->account)
    {
        owned_property_count=count_properties(*current_player);
        while(rent>current_player->account && owned_property_count!=0)
        {
            insufficient_fund(board,current_player,rent);
            owned_property_count=count_properties(*current_player);
        }
    }
    if (rent<current_player->account)
    {
        current_player->account-=rent;
        owner->account+=rent;
    } else
        current_player->account=0;
}

void add_to_owned(player* current_player)	/*this is adding owned blocks's array*/
{
int i;
    for (i = 0; i < PROPERTY_COUNT; ++i) {
        if (current_player->owned_blocks[i]==-1) {
            current_player->owned_blocks[i] = current_player->current_block_id;
            printf("Current block id %d\n",current_player->current_block_id);
            break;
        } else
            printf("%d ",current_player->owned_blocks[i]);
    }
    printf("\n");
}

void copy_owner(player* old, player* new)	/*this is copying new to old*/
{
int i;
    old->type=new->type;
    old->account=new->account;
    old->turn_to_wait=new->turn_to_wait;
    old->player_name=new->player_name;
    old->current_block_id=new->current_block_id;
    for (i = 0; i < PROPERTY_COUNT; ++i) {
        old->owned_blocks[i]=new->owned_blocks[i];
    }
}

void buy_property(block* current_block, player* current_player) 	/*this is buying property*/
{
    if (current_block->price<=current_player->account)
    {
        current_player->account-=current_block->price;
        copy_owner(&current_block->owner,current_player);
        add_to_owned(current_player);

        printf("Congratiulations! You have buy %s.\n",current_block->name);
        printf("You left %d$ in your account.\n",current_player->account);

    }
    else
        printf("You don't have enough money to buy this property!\n");
}

void house_dialog(block *board, player* current_player)		/*this is for buying house*/
{
    int house_flag=1,selection,insuf_flag=1,build_flag=1,i;
    block *temp=board;
    for(i=0;i<current_player->current_block_id;i++){
		temp=temp->next;
	}
    while (house_flag && build_flag) {
        printf("Do you want to build house on %s ?\n",temp->name);
        printf("1- Yes\n");
        printf("2- No\n");
        scanf("%d", &selection);
        if (selection == 1) {
            if (current_player->account >= temp->house_price)
                build_flag=build_house(temp,current_player);
            else{
		printf("You don't have enough money\n");
                house_flag=0;
		}
        } else{
            house_flag=0;
		} 
   }
}

void after_dice_menu(block *board, player* current_player, player* other,fortune_card *cards)/*this is for player that controls by us */
{
    int selection,insuf_flag=1,i,random,select=1,j,time_travel,next_block;
    block *temp=board;
    for(i=0;i<current_player->current_block_id;i++){
		temp=temp->next;		/*this is going when it reaches the current block with linkedlist*/

    }
    switch (temp->type)
    {
        case property:		/*If place is a property block...*/
            printf("%s has arrived %s \n",current_player->player_name,temp->name);
            if (temp->owner.type==none)
            {
                printf("Do you want to buy %s ?\n",temp->name);
                printf("1- Yes\n");
                printf("2- No\n");
                scanf("%d",&selection);
                if (selection==1)
                {
                    buy_property(temp,current_player);
                    if (current_player->type==temp->owner.type)
                    {
                        house_dialog(board,current_player);
                    }

                }

            }
	    else if(current_player->type==temp->owner.type){
			house_dialog(board,current_player);
		}
	    else
            {
                pay_rent(board,current_player,other);
            }
            break;
        case tax:	/*If place is a tax block...*/
            printf("%s has arrived tax block(%s)\n",current_player->player_name,temp->name);
            while (count_properties(*current_player)!=0 && current_player->account<temp->price) {
                insuf_flag = insufficient_fund(board, current_player,temp->price);
                if (insuf_flag == 0 && current_player->account < temp->price)
                    printf("You must pay your tax!\n");
            }
            if (current_player->account>temp->price)
                current_player->account=current_player->account-temp->price;
            else
            {
                current_player->account=0;
            }
            break;
        case punish:	/*If place is a punish block...*/
            printf("%s has punished for %d turn. \n",current_player->player_name,temp->price);
            current_player->turn_to_wait+=temp->price;
            break;
	case fortune:	/*If place is a forutne block...*/
			random=rand()%5;
			switch (random)
			{
				case 0: printf("You came to the fortune card block : %s\n",cards->name);
					 while(select!=0){
						printf("You can build a house for free!,So Select a  property id that has less than 3 house\n");
						printf("0-Back\n");
						temp=board;
						printf("----------------------------------------\n");
						for (i = 0; i < PROPERTY_COUNT; i++) {
						    if (current_player->owned_blocks[i] != -1) {
							for(j=0;j<current_player->owned_blocks[i];j++){
									temp=temp->next;
							}
							printf("%d - %s\n", temp->id,temp->name);
						    }
						    temp=board;
						}
						temp=board;		/*this case is buying a house for free*/
						scanf("%d",&select);
						for(i=0;i<select;i++){
							temp=temp->next;
						}
						if(temp->owner.type==current_player->type && temp->h_count<3){
								temp->h_count++;
								break;
						}
						else{
							printf("This is not your property\n");
						}
						temp=board;
					}
					break;
				case 1: printf("You came to the fortune card block : %s\n",cards->next->name);
					time_travel=roll_dice();
					if(time_travel>=1 && time_travel<=3){		/*this case is time travel case*/
						next_block=(current_player->current_block_id + 2);
						 if (next_block>=24)current_player->account+=10000;
						 current_player->current_block_id = next_block % 24;

					}
					else{
						next_block=(current_player->current_block_id - 2);
						 if (next_block>=24)current_player->account+=10000;
						 current_player->current_block_id = next_block % 24;
						}
					temp=board;
					 for(i=0;i<current_player->current_block_id;i++){
					 temp=temp->next;		/*this is going when it reaches the current block with linkedlist*/

   					 }
					printf("%s has arrived %s \n",current_player->player_name,temp->name);
					    if (temp->owner.type==none)
					    {
						printf("Do you want to buy %s ?\n",temp->name);
						printf("1- Yes\n");
						printf("2- No\n");
						scanf("%d",&selection);
						if (selection==1)
						{
						    buy_property(temp,current_player);
						    if (current_player->type==temp->owner.type)
						    {
							house_dialog(board,current_player);
						    }

						}

					    }
					    else if(current_player->type==temp->owner.type){
							house_dialog(board,current_player);
						}
					    else
					    {
						pay_rent(board,current_player,other);
					    }
					
					break;
				case 2: printf("You came to the fortune card block : %s\n",cards->next->next->name);
					while (count_properties(*current_player)!=0 && current_player->account<5000) {
					insuf_flag = insufficient_fund(board, current_player,temp->price);	/*If it hasn't enough money*/
					if (insuf_flag == 0 && current_player->account < 5000)
					    printf("You must pay 5000$!\n");
					}
					if (current_player->account>5000)	/*this case is garnishment case*/
					current_player->account=current_player->account-5000;
					else
					{
						current_player->account=0;
					}
					break;
				case 3: printf("You came to the fortune card block : %s\n",cards->next->next->next->name);
					while (count_properties(*current_player)!=0 && current_player->account<10000) {
					insuf_flag = insufficient_fund(board, current_player,temp->price);	/*If it hasn't enough money*/
					if (insuf_flag == 0 && current_player->account < 10000)	
					    printf("You must pay 10000$ to your opponent!\n");
					}
					
					if (current_player->account>10000){
					current_player->account=current_player->account-10000;
					other->account=other->account+10000;	/*this case is generocity case*/
					}
					else{
						current_player->account=0;
					}
					break;
				case 4: printf("You came to the fortune card block : %s\n",cards->next->next->next->next->name);
					current_player->account=current_player->account+20000;  /*this case is treasure hunter case*/
					break;

			}

		break;
	case start:
		break;
    }
}

void turn(block *board, player* current_player, player * other, fortune_card cards[]) /*this is menu for player that controls by us and player's turn*/
{
    int flag=1,next_block,i;
    block *temp=board;
    while(flag)
    {
	temp=board;
        int selection;
        printf("1 - Roll the dice\n");
        printf("2 - Show my account\n");
        printf("3 - Show my properties\n");
        printf("4 - Show property deeds\n");
        printf("5 - Buy Property\n");
        printf("6 - Buy house \n");
        printf("7 - Sell property\n");
        printf("Please select an option to continue (%s):\n",current_player->player_name);
        scanf("%d",&selection);
        switch(selection)
        {
            case 1:
                if (current_player->turn_to_wait==0) {
                    next_block=(current_player->current_block_id + roll_dice());
                    if (next_block>=24)current_player->account+=10000;
                    current_player->current_block_id = next_block % 24;
		
                    after_dice_menu(board,current_player,other,cards);
                    flag = 0;
		   
	
                } else
                {
                    printf("You need to wait %d turn to continue.\n",current_player->turn_to_wait);
                    current_player->turn_to_wait-=1;
                    flag=0;
                }
                break;
            case 2:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 3:
                show_player_properties(board,*current_player);
                break;
            case 4:
                show_property_deed(board);
                break;
            case 5:
		 for(i=0;i<current_player->current_block_id;i++){
				temp=temp->next;

			}
                if (temp->type==property && temp->owner.type==-1)
                buy_property(temp,current_player);
                else
                {

                    printf("You don't have permission to buy this block!\n");
                }
		temp=board;
                break;
            case 6:
		    for(i=0;i<current_player->current_block_id;i++){
				temp=temp->next;

			}
                if (current_player->type==temp->owner.type) {
                    house_dialog(board,current_player);
                }else
                {
                    printf("You don't have permission to build house on this block!\n");
                }
		temp=board;
                break;
            case 7:
                sell_property(board,current_player);
                break;
            default:
                printf("Wrong selection!\n");
        }
    }
}

void turn_computer(block *board, player* current_player, player * other, fortune_card *cards) /*this is for compter turn */
{
int flag=1,next_block,i,dice,adding=0,c_property=0,dialog,random,time_travel,j;
    block *temp=board;	/*this is beginning adress*/
	while(flag){
		temp=board;
		if (current_player->turn_to_wait==0) {		/*it rolls a dice*/
		    dice=roll_dice();
                    next_block=(current_player->current_block_id + dice);
		    printf("Computer rolled the dice:%d\n",dice);
                    if (next_block>=24)current_player->account+=10000;
                    current_player->current_block_id = next_block % 24;
		    for(i=0;i<current_player->current_block_id;i++){
				temp=temp->next;

		    }
		
                    if (temp->type==property && temp->owner.type==-1){	/*If property is none then */
			    temp=board;
			    for(i=0;i<24;i++){
				if(temp->type==property){
				adding+=temp->price;
				}
				temp=temp->next;	/*this is going when it reaches current block*/
			    }	
			    adding=adding/(PROPERTY_COUNT-1);		
			    temp=board;	
			    for(i=0;i<current_player->current_block_id;i++){
					temp=temp->next;
				}			/*If the property price is below avarege price */
			  if(temp->price<adding){		/*Then It buy the property*/
					  if (temp->price<=current_player->account)
					  {
					current_player->account-=temp->price;
					copy_owner(&temp->owner,current_player);
					add_to_owned(current_player);

					printf("Congratiulations! Computer bought %s.\n",temp->name);
					printf("Computer left %d$ in its account.\n",current_player->account);

				        }
				        else
					printf("Computer doesn't have enough money to buy this property!\n");
			 }
			 else{			/*ELSE */
			     dice=roll_dice();
			     printf("Computer rolled lucky dice to buy %s and dice is =%d\n",temp->name,dice);
			     if(dice>=1 && dice<=3){
				 if (temp->price<=current_player->account)
					  {
					current_player->account-=temp->price;
					copy_owner(&temp->owner,current_player);
					add_to_owned(current_player);

					printf("Congratiulations! Computer bought %s.\n",temp->name);
					printf("Computer left %d$ in your account.\n",current_player->account);

				        }
				        else
					printf("Computer doesn't have enough money to buy this property!\n");
			     }
			     else{
					printf("So,Computer didn't buy the property\n");
					flag=0;
			     }
			}
		    }
		    else if (temp->type==property && temp->owner.type==current_player->type){	/*This is for buying house */
				c_property=count_properties(*current_player);
				if(c_property>=(PROPERTY_COUNT/3)){		/*If it hase 1/3 property of total property*/
					dice=roll_dice();
			     		printf("Computer rolled lucky dice to buy house on %s and dice is =%d\n",temp->name,dice);
					if(dice>=1 && dice<=3){
						dialog=build_house(temp,current_player);	
						if(dialog==0)printf("\nThe bank said to Computer\n");
					}
					else{
						printf("Becouse of number of dice,It didn't buy a house\n");
							flag=0;
					}
				}
				else{
					printf("Computer came to own place but [ Becouse it hasn't property more than 1/3 of all properties] It didn't build a house\n");
					flag=0;
				}

		    }
		    else if (temp->type==property && temp->owner.type==other->type){
				pay_rent(board,current_player,other);		/*this is for paying rent*/
			}
		    else if (temp->type==tax){		/*this is for tax block*/
				printf("%s has arrived tax block(%s)\n",current_player->player_name,temp->name);
				    while (count_properties(*current_player)!=0 && current_player->account<temp->price) {
					insufficient_fund(board, current_player,temp->price);	/*If it hasn't enough money*/
				    }
				    if (current_player->account>temp->price)
					current_player->account=current_player->account-temp->price;
				    else
				    {
					current_player->account=0;
				    }
			}
		    else if(temp->type==punish){
				printf("%s has punished for %d turn. \n",current_player->player_name,temp->price);
            			current_player->turn_to_wait+=temp->price;
			}
		    else if(temp->type==fortune){
				random=rand()%5;
			switch (random)		/*this is for fortune cards*/
			{
				case 0: printf("Computer came to the fortune card block : %s\n",cards->name);
						printf("Computer can build a house for free! If It has a property !\n");
						temp=board;
						printf("----------------------------------------\n");
						for (i = 0; i < PROPERTY_COUNT; i++) {
						    if (current_player->owned_blocks[i] != -1) {
							for(j=0;j<current_player->owned_blocks[i];j++){
									temp=temp->next;
							}
							
							if(temp->h_count<3){
								temp->h_count++;
								printf("It built a house to \n %d - %s\n", temp->id,temp->name);
								break;
							}
						    }
						    temp=board;
						}
						temp=board;
					break;
				case 1: printf("Computer came to the fortune card block : %s\n",cards->next->name);
					time_travel=roll_dice();
					if(time_travel>=1 && time_travel<=3){
						next_block=(current_player->current_block_id + 2);
						 if (next_block>=24)current_player->account+=10000;
						 current_player->current_block_id = next_block % 24;

					}
					else{
						next_block=(current_player->current_block_id - 2);
						 if (next_block>=24)current_player->account+=10000;
						 current_player->current_block_id = next_block % 24;
						}
					 temp=board;
					 for(i=0;i<current_player->current_block_id;i++){
						temp=temp->next;		/*this is going when it reaches the current block with linkedlist*/

   					 }					
					if (temp->type==property && temp->owner.type==-1){	/*If property is none then */
					    temp=board;
					    for(i=0;i<24;i++){
						if(temp->type==property){
						adding+=temp->price;
						}
						temp=temp->next;	/*this is going when it reaches current block*/
					    }	
					    adding=adding/(PROPERTY_COUNT-1);		
					    temp=board;	
					    for(i=0;i<current_player->current_block_id;i++){
							temp=temp->next;
						}			/*If the property price is below avarege price */
					  if(temp->price<adding){		/*Then It buy the property*/
							  if (temp->price<=current_player->account)
							  {
							current_player->account-=temp->price;
							copy_owner(&temp->owner,current_player);
							add_to_owned(current_player);

							printf("Congratiulations! Computer bought %s.\n",temp->name);
							printf("Computer left %d$ in its account.\n",current_player->account);

							}
							else
							printf("Computer doesn't have enough money to buy %s!\n",temp->name);
					 }
					 else{			/*ELSE */
					     dice=roll_dice();
					     printf("Computer rolled lucky dice to buy %s and dice is =%d\n",temp->name,dice);
					     if(dice>=1 && dice<=3){
						 if (temp->price<=current_player->account)
							  {
							current_player->account-=temp->price;
							copy_owner(&temp->owner,current_player);
							add_to_owned(current_player);

							printf("Congratiulations! Computer bought %s.\n",temp->name);
							printf("Computer left %d$ in your account.\n",current_player->account);

							}
							else
							printf("Computer doesn't have enough money to buy this property!\n");
					     }
					     else{
							printf("So,Computer didn't buy the property\n");
							flag=0;
					     }
					}
					}
					break;
				case 2: printf("Computer came to the fortune card block : %s\n",cards->next->next->name);
					while (count_properties(*current_player)!=0 && current_player->account<5000) {
						insufficient_fund(board, current_player,temp->price);
						}
					if (current_player->account>5000)
					current_player->account=current_player->account-5000;
					else
					{
						current_player->account=0;
					}
					break;
				case 3: printf("Computer came to the fortune card block : %s\n",cards->next->next->next->name);
					while (count_properties(*current_player)!=0 && current_player->account<10000) {
						insufficient_fund(board, current_player,temp->price);
					}
					if (current_player->account>10000){
					current_player->account=current_player->account-10000;
					other->account=other->account+10000;
					}
					else
					{
						current_player->account=0;
					}
					break;
				case 4: printf("Computer came to the fortune card block : %s\n",cards->next->next->next->next->name);
					current_player->account=current_player->account+20000;
					break;

			}



			}	
                    flag = 0;	
                } else
                {
                    printf("Computer need to wait %d turn to continue.\n",current_player->turn_to_wait);
                    current_player->turn_to_wait-=1;
                    flag=0;
                }
	}

}

int check_end(player current_player)		/*this is checking end*/
{
    int owned_property_count=count_properties(current_player);
    if (current_player.account<=0 && owned_property_count==0)return 1;
    else return 0;
}


void gameplay(block *board, player* player_one, player* computer)	/*this is gameplay*/
{
    int is_end=0;
    fortune_card *cards;
    fortune_card *b_card;
    cards=(fortune_card*)malloc(sizeof(fortune_card));
    b_card=cards;
    cards->name="Free House";
    cards->next=(fortune_card*)malloc(sizeof(fortune_card));
    cards=cards->next;
    cards->name="Time Travel";
    cards->next=(fortune_card*)malloc(sizeof(fortune_card));			/*this is fortune card's linkedlist*/
    cards=cards->next;
    cards->name="Garnishment";
    cards->next=(fortune_card*)malloc(sizeof(fortune_card));
    cards=cards->next;
    cards->name="Generosity";
    cards->next=(fortune_card*)malloc(sizeof(fortune_card));
    cards=cards->next;
    cards->name="Treasure Hunter";
    cards->next=(fortune_card*)malloc(sizeof(fortune_card));
    cards->next=NULL;

    printf("Welcome to Monopoly! %s will roll the dice first.\n",player_one->player_name);
    while(is_end!=1)
    {
        printf("%s :%d$ , %s:%d$\n",player_one->player_name,player_one->account,computer->player_name,computer->account);
        turn(board,player_one,computer,b_card);
        show_board(board,*player_one,*computer);
        is_end=check_end(*player_one);
        if (is_end==0)
        {
            printf("%s :%d$ , %s:%d$\n",player_one->player_name,player_one->account,computer->player_name,computer->account);
            turn_computer(board,computer,player_one,b_card);
            show_board(board,*player_one,*computer);
            is_end=check_end(*computer);
            if (is_end==1)
                printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",computer->player_name,computer->player_name);
        } else
            printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_one->player_name,player_one->player_name);

    }

}



void init_owned(player* current_player)	/*this is filling with 1 to owned blocks*/
{
    int i;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        current_player->owned_blocks[i]=-1;
    }

}

int main() {
int i,j,for_free;
    block *board;
    block *temp;
    board=(block *)malloc(sizeof(block));
    init_board(board);
    srand(time(NULL));
    player player_one,player_two;
    temp=board;

    player_one.player_name="Car";
	player_one.type=car;
	player_one.current_block_id=0;
    player_one.turn_to_wait=0;
	player_one.account=100000;
    init_owned(&player_one);

  	player_two.player_name="Cap";
	player_two.type=cap;
	player_two.current_block_id=0;
    player_two.turn_to_wait=0;
	player_two.account=100000;
    init_owned(&player_two);	

	show_board(board,player_one,player_two);
   	gameplay(board,&player_one,&player_two); 

	for_free=24;
	for(j=0;j<24;j++){			/*this is deallocating the memory*/
		for(i=0;i<for_free;i++){
			temp=temp->next;
		}
		free(temp);
		for_free--;
		temp=board;
   	}

    return 0;
}
