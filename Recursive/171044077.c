#include<stdio.h>
							/*Mustafa Tokgöz 171044077*/

int common(int n1,int n2,int i){  /* this is finding great common division*/
	if(n1==0 || n2==0){
		return 0;	/*if one of them is zero then retrun 0*/
	}
	else if(n1%i==0 && n2%i==0){  /*if number 1 and number 2 are 0 in terms of modulo of increasing constant i*/
					/*i is multiplier of them */
			return i*common(n1/i,n2/i,i); /*then it returns common and it divide them into multiplier i*/
		
	}
	else if(i>n2){
		return 1;   /*if multiplier is bigger than any number either n1 or n2 ,then it returns 1 */
	}
	
	else{
		return common(n1,n2,i+1);   /*if i isn't multiplier then it doesnt do anyting and it increases i*/
	}
}



void merge_of_them(int list[],int first_side,int second_side,int left_side[],int right_side[],int how_many_left){ 
 int i=0; 
 int j=0;
 int m=0;
 int h=how_many_left;  /*this is how many number on the left*/
 int t[first_side+second_side];
	    for(m=0;m<first_side+second_side;m++){  /*this is assigning to t from list*/
		t[m]=list[m];
	    }
	    while(first_side>i && second_side>j){  /*when i is less than left side number of array  and  and j is less than right side number of array */
		if(left_side[i]<=right_side[j]){  /*if left side's i th number is less or equal to right side's then*/
		    list[h]=left_side[i];         /*it assign to list from left side i th number*/
		    i=i+1;                         /*then is increases i*/
		} 
		else{
		    list[h]=right_side[j];      /*else right side's j th number assign to list*/
		    j=j+1; 				/*then j is increasing*/
		} 
		h=h+1;                        /*then it continiue and h is increased 1*/
	    } 
	    for(;first_side>i;){ 		/*when i is less than left side of array number*/
		list[h]=left_side[i];  		/*it assign to list from left side i th number*/
		i=i+1; 				/*then it increases i and h 1*/
		h=h+1; 
	    } 
	    for(;second_side>j;){ 		/*when j is less then right side of array number*/
		list[h]=right_side[j]; 		/*then it assign to list from right side*/
		j=j+1; 				/*then it increses j and h*/
		h=h+1; 				
	    } 

} 
void divide_two(int how_many_left,int middle,int how_many,int list[]){
 int i=0, j=0,k=0;
 int first_side=middle-how_many_left+1;  /*first side is number of left side array*/
 int second_side=how_many-middle; 	/*second side is number of right side array*/
 int left_side[first_side],right_side[second_side];  /*they are left and right side arrays*/
 int tl[first_side];	/*temp of the array left*/
 int tr[second_side];	/*temp of the array right*/
    while(first_side>i){ 			/*while i is less than left side number of array*/
        left_side[i]=list[how_many_left+i];  /*it assigns left side*/
	i=i+1;					/*and it increases i 1*/
    }
    for(k=0;k<first_side;k++){  /*this is assigning to t from left*/
		tl[k]=left_side[k];
    }
    while(second_side>j){ 			/*while j is less than right side number of array*/
        right_side[j]=list[middle+j+1];		/*it assigns right side*/
	j=j+1;						/*then it increases j 1*/
    } 
    for(k=0;k<second_side;k++){  /*this is assigning to t from right*/
		tr[k]=right_side[k];
    }	
	merge_of_them(list,first_side,second_side,left_side,right_side,how_many_left); /*this is merging the arrays*/

}
  
void part_two(int list[],int how_many_left,int how_many){
int middle_point;
    if(how_many>how_many_left){    /*this is seperating arrays*/
        middle_point=how_many_left+(how_many-how_many_left)/2; /*this is middle point*/
        part_two(list,how_many_left,middle_point); /*this is recursion side*/
       	part_two(list,middle_point+1,how_many);    /*this is recursion side*/
	divide_two(how_many_left,middle_point,how_many,list); /*this is dividing two with increasing order*/
    } 

}
int part_three(int number){
	if(number<=2){
		printf("1");
		return 0;	/*if number is less and equal to 2 then prints 1*/
	}

	else if(number%2==0){	/*if number modulo of 2 is 0 then it divides 2 with respect to formulo of hw6*/
		number=number/2;
	}
	else if(number%2==1){	/*if number modulo of 2 is 1 then it multiply 3 and add 1  with respect to formulo of hw6*/
		number=(number*3)+1;
	}
		printf("%d ",number); /*then this is prints them*/
		return part_three(number); /*this is recursion side*/
}

int power(int number,int digit){   /*this is calculating power of number with recursively*/
	if(digit==0){
		return 1;
	}
	else{
		return number*power(number,digit-1);
	}
}




int part_four(int number,int number_t){
int ans;
int temp=number_t;
int digit=0;
int pow;
	if(number>0){
		while(temp>0){		/*this is finding digit of number for positive number*/
			temp=temp/10;
			digit++;
		}
		if(number<10){			/*then if number is less 10 then it returns power digit of number*/
			return power(number,digit);
			
		}	
		else{	
			pow=number%10; /*else it find last number of number*/
			number=number/10; /*and it reduces its digit*/
			return power(pow,digit)+part_four(number,number_t); /*then it finds power of last number with digit then there is recursive*/
		}

	}
	else if(number<0){
		while(temp<0){		/*this is finding digit of number for negative number*/
			temp=temp/10;
			digit++;
		}
		if(number>-10){			/*then if number is less 10 then it returns power digit of number*/
			return power(number,digit);
			
		}	
		else{	
			pow=number%-10; /*else it find last number of number for negative number*/
			number=number/10; /*and it reduces its digit*/
			return power(pow,digit)+part_four(number,number_t); /*then it finds power of last number with digit then there is recursive*/
		}
	}
	else{
		return number;  /*if number is 0 then return 0*/
	}
	


}

char part_five(char *word){
	if(word[0]<91 && word[0]>64){  /*it finds first capital letter in a word*/
		return word[0];
	}
	else if(word[0]==0){
		printf("There is no capital letter \n"); /*if there is no , then it prints ..*/
		return 32; /*then return space character*/
	}
	else{
		return part_five(&word[1]); /*else it sends augmented adress of word */
	}

}


int main(){
 int n1,n2,result,temp,number; /*this is for part 1 and part 3 and 4*/
 int choice=1; /*this is for selecton*/
 int lenght_of_list,i; 
 int a[1000]; /*this is for part 2*/
 char word[1000]; /*this is for part 5*/
	while(choice!=0){
		printf("\n-----------------Please enter-----------------\n");
		printf("---------------  1 for part one    -----------\n");
		printf("---------------  2 for part two    -----------\n");
		printf("---------------  3 for part three  -----------\n");
		printf("---------------  4 for part four   -----------\n");
		printf("---------------  5 for part five   -----------\n");
		printf("---------------To quit , enter 0--------------\n");
		scanf("%d",&choice);
		switch (choice){
			case 0: break;		
			case 1: printf("Please enter two number for commons\n");
				printf("number 1:");
				scanf("%d",&n1);
				printf("number 2:");
				scanf("%d",&n2);
				result=common(n1,n2,2);
				printf("the result is=%d \n",result);
				break;

			case 2: printf("Please enter the length of the list: ");
				scanf("%d",&lenght_of_list);
				for(i=0;i<lenght_of_list;i++){
					scanf("%d",&a[i]);
				}
				part_two(a,0,lenght_of_list-1);				
				for(i=0;i<lenght_of_list;i++){
					printf("%d  ",a[i]);
				}
				break;



			case 3: printf("Please,enter a number\n");
				printf("Input:");
				scanf("%d",&number);
				printf(" %d ",number);
				part_three(number);

				break;



			case 4: printf("Please,enter a number\n");
				printf("Input:");
				scanf("%d",&number);
				if(part_four(number,number)==number){
					printf("Equal\n");
				}
				else
					printf("Not Equal\n");
				break;
			case 5: printf("Please,enter a word\n");
				scanf("%s",word);
				printf("First capital letter is: ");
				printf("%c",part_five(word));
				break;
			
			default : printf("Please only select 0-5\n");
		}
	}

return 0;


}
