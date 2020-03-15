#include<stdio.h>
#include<stdlib.h>
#include<time.h>
						/*MUSTAFA TOKGÖZ 171044077*/
typedef struct bst{
	int value;
	struct bst *left,*right;		/*this is for bst_*/
}bst;


typedef struct queue{
	int value;			/*this is for queue*/
	struct queue *next;
}queue;


typedef struct stack{
	int value;
	struct stack *next;		/*this is for stack*/
}stack;

typedef struct linkedlist{
	int data;			/*this is temporary list for using bst*/
	struct linkedlist *next;
}list;



void print_list(stack *stack_){
 stack *temp=stack_;
	while(temp!=NULL){
		printf(" %d ",temp->value);	/*this prints stack*/		
		temp=temp->next;
	}
	printf("\n");

}

void print_list_q(queue *queue_){
 queue *temp=queue_;
	while(temp!=NULL){
		printf(" %d ",temp->value);	/*this prints queue*/	
		temp=temp->next;
	}
	printf("\n");

}

void print_bst(bst *bst){

	if(bst==NULL)
           return;

      	print_bst(bst->right);
	printf(" %d ", bst->value);		/*this prints bst in decreasing order*/
        print_bst(bst->left);
    
} 


bst *insert_bst(bst *bst_,int value){	/*this inserts the values to bst*/

 bst *temp;
	if(bst_==NULL){
 		temp=(bst *)malloc(sizeof(bst)); 
    		temp->value=value; 
    		temp->left=temp->right = NULL; 
		bst_=temp;
	} 
        if(value<bst_->value){ 
        	bst_->left=insert_bst(bst_->left,value); 
   	}
	else if(value>bst_->value){ 
        	bst_->right=insert_bst(bst_->right,value); 
  	}
	return bst_; 
} 




void fill_structures(stack **stack_,queue **queue_,bst **bst_,int data[20]){	/*this is filling structures*/
 stack *temp_of_stack;			/*this is for filling stack*/
 queue *temp_of_queue,*head_of_queue;	/*this is for filling queue*/
 bst *temp_of_bst,*temp;			/*this is for filling bst*/
 int i,number_of_data=20;					/*The data number is 20 if you want to change you must change*/
 double start_s,end_s,start_q,end_q,start_b,end_b;	/*this is for calculating execution time*/

	(*stack_)=NULL;
	(*queue_)=NULL;					/*At the beginning they are NULL*/
	(*bst_)=NULL;
	
	start_s=clock();			/*this is taking start time*/
	for(i=0;i<number_of_data;i++){						/*this is filling stack*/	
		
		temp_of_stack=(stack *)malloc(sizeof(stack));	
		temp_of_stack->value=data[i];
		temp_of_stack->next=(*stack_);
		(*stack_)=temp_of_stack;
			
	}
	end_s=clock();				/*this is taking end time for stack*/
	
	start_q=clock();			
	
	for(i=0;i<number_of_data;i++){			/*This is filling queue*/
		temp_of_queue=(queue *)malloc(sizeof(queue));
		temp_of_queue->value=data[i];
		temp_of_queue->next=NULL;
		if((*queue_)==NULL){
			(*queue_)=temp_of_queue;
			head_of_queue=(*queue_);
		}
		else{	(*queue_)->next=temp_of_queue;
			(*queue_)=temp_of_queue;
		}
				
	}
	(*queue_)=head_of_queue;
	
	end_q=clock();

	start_b=clock();
	
	(*bst_)=insert_bst((*bst_),data[0]);			/*this is inserting first data*/
	for(i=1;i<number_of_data;i++){			/*this is inserting all data except fist*/
		(*bst_)=insert_bst((*bst_),data[i]);
		
	}
	
	end_b=clock();
	
	printf("\n\nStructures Stack Queue  Bst   (In fill_structures function)\n");		/*this is printing execuiton times*/
	printf("Exec. Time %.3f %.3f  %.3f\n",(end_s-start_s)/CLOCKS_PER_SEC*1000,(end_q-start_q)/CLOCKS_PER_SEC*1000,(end_b-start_b)/CLOCKS_PER_SEC*1000);

}

void free_stack(stack *s){		/*this is for stack for deallocitng*/
 stack *temp;
	while(s!=NULL){
		temp=s;
		s=s->next;
		free(temp);
	}
}
void free_queue(queue *q){		/*this is for queue for deallocitng*/
 queue *temp;
	while(q!=NULL){
		temp=q;
		q=q->next;
		free(temp);
	}
	
}

void free_tree(bst *b){			/*this is for bst for deallocitng*/ 
       if (b != NULL) {					
        free_tree(b->right);
        free_tree(b->left);
        free(b);
     }
}

void free_list(list *liste){		/*this is for list for deallocitng*/
 list *temp;
	while(liste!=NULL){
		temp=liste;
		liste=liste->next;
		free(temp);
	}
	
}


void ordered_print(stack *stack_,queue *queue_,bst *bst_){		/*this is ordering the lists*/
 stack *temp,*other_s;
 stack *temp2,*temp3;

 queue *temp_q,*other_q;
 queue *temp2_q,*temp3_q;
 double start_s,end_s,start_q,end_q,start_b,end_b;

	start_s=clock();
	if(stack_!=NULL){		/*this is for temporary stack for ordering*/
		temp=(stack*)malloc(sizeof(stack));		/*I back up stack for ordering decresing order*/
		temp->value=stack_->value;
		other_s=temp;
		stack_=stack_->next;
	}
	while(stack_!=NULL){
		temp->next=(stack*)malloc(sizeof(stack));
		temp=temp->next;
		temp->value=stack_->value;
		stack_=stack_->next;
	}
	
	temp2=(stack *)malloc(sizeof(stack));
	temp->next=NULL;
	temp=other_s;
	printf("  This is Stack ordered list in descending order!\n");
	if(temp!=NULL){			/*this is checking if is empty or not*/
		temp3=temp->next; /*this points temp->next for comparing forward*/
		while(temp->next!=NULL){		/*this is controlling numbers*/
			while(temp3!=NULL){
				if((temp->value)<(temp3->value)){	/*if number is bigger than other*/
				
				temp2->value=temp->value;
				
				temp->value=temp3->value;
				
				temp3->value=temp2->value;
				}
				temp3=temp3->next;	
			}
			temp=temp->next; /*this is going until reaching NULL*/
			temp3=temp->next; /*this points temp->next for comparing forward*/
		}
	}
	else
		printf("\nStack is empty!\n");	
	print_list(other_s);
	end_s=clock();
					/*this is temporary queue for */
	start_q=clock();
	if(queue_!=NULL){				/*I back up queue for ordering decresing order*/
		temp_q=(queue*)malloc(sizeof(queue));
		temp_q->value=queue_->value;
		other_q=temp_q;
		queue_=queue_->next;
	}
	while(queue_!=NULL){
		temp_q->next=(queue*)malloc(sizeof(queue));
		temp_q=temp_q->next;
		temp_q->value=queue_->value;
		queue_=queue_->next;
	}
	
	temp2_q=(queue *)malloc(sizeof(queue));
	temp_q->next=NULL;
	temp_q=other_q;
	printf("\n  This is Queue ordered list in descending order!\n");
	if(temp_q!=NULL){			/*this is checking if is empty or not*/
		temp3_q=temp_q->next; /*this points temp->next for comparing forward*/
		while(temp_q->next!=NULL){		/*this is controlling numbers*/
			while(temp3_q!=NULL){
				if((temp_q->value)<(temp3_q->value)){	/*if number is bigger than other*/
				
				temp2_q->value=temp_q->value;
				
				temp_q->value=temp3_q->value;
				
				temp3_q->value=temp2_q->value;
				}
				temp3_q=temp3_q->next;	
			}
			temp_q=temp_q->next; /*this is going until reaching NULL*/
			temp3_q=temp_q->next; /*this points temp->next for comparing forward*/
		}
	}
	else
		printf("\nStack is empty!\n");
	print_list_q(other_q);
	end_q=clock();


	start_b=clock();
	printf("\n  This is Bst ordered list in descending order!\n");
	print_bst(bst_);		/*this prints decreasing order for bst*/
	end_b=clock();

	printf("\n\nStructures Stack Queue  Bst   (In ordered_print function)\n");
	printf("Exec. Time %.3f %.3f  %.3f\n",(end_s-start_s)/CLOCKS_PER_SEC*1000,(end_q-start_q)/CLOCKS_PER_SEC*1000,(end_b-start_b)/CLOCKS_PER_SEC*1000);
	
}

void search(stack *stack_,queue *queue_,bst *bst_,int val_to_search){	/*this is searching number*/
 int how_many_s=0,how_many_q=0,how_many_b=0,i=1,check=0;
 double start_s,end_s,start_q,end_q,start_b,end_b;
 list *s,*temp,*q,*temp_q,*for_free;		/*this is temporary list for searching*/

 s=NULL;
 q=NULL;
	printf("\n This is searching %d number in Stack,Queue and Bst",val_to_search);
	start_s=clock();
	printf("\nNumber %d for Stack",val_to_search);
	s=(list *)malloc(sizeof(list));
	temp=s;
	while(stack_!=NULL){
		if(stack_->value==val_to_search){
				if(how_many_s>0){
					s->next=(list *)malloc(sizeof(list));	/*I dont know how many times number is there,So i allocate a temporary list*/
					s=s->next;
				}
				how_many_s++;
				s->data=i;
		}
		i++;
		stack_=stack_->next;
	}
	s->next=NULL;
	for_free=temp;		/*this is for dealloacating temporary list,so i assing the beginning address to for_free */
	if(how_many_s!=0){
		if(temp!=NULL)
			printf("\n%d result founded on ",how_many_s);	/*this is prints how many time*/
		while(temp!=NULL){
			printf("%d.step",temp->data);		/*this is prints searching data*/
			temp=temp->next;
			if(temp!=NULL){
				printf(" and ");
				
			}
		}
		
	}
	else
		printf("\nNot founded!");
	printf(".\n");
	end_s=clock();
	free_list(for_free);	/*this is deallocating temporary list*/
	
	start_q=clock();
	i=1;
	q=(list *)malloc(sizeof(list));
	temp_q=q;

	printf("\nNumber %d for Queue",val_to_search);		/*Same thing  for queue, it is like stack's search*/
	while(queue_!=NULL){
		if(queue_->value==val_to_search){
				if(how_many_q>0){
					q->next=(list *)malloc(sizeof(list));
					q=q->next;
				}
				how_many_q++;
				q->data=i;
		}
		i++;
		queue_=queue_->next;
	}
	q->next=NULL;
	for_free=temp_q;
	if(how_many_q!=0){
		if(temp_q!=NULL)
			printf("\n%d result founded on ",how_many_q);
		while(temp_q!=NULL){
			printf("%d.step",temp_q->data);
			temp_q=temp_q->next;
			if(temp_q!=NULL){
				printf(" and ");
				
			}
		}
		
	}
	else
		printf("\nNot founded!");
	printf(".\n");
	end_q=clock();
	free_list(for_free);

	start_b=clock();
	i=1;
	how_many_b=1;	
	printf("\nNumber %d for Bst",val_to_search);			
	while(bst_!=NULL){
		if(val_to_search==bst_->value){
			printf("\n%d result founded on %d.step",how_many_b,i);
				check=1;		/*this is checking there is or not*/
				break;
		}
		else if(val_to_search<bst_->value){
				bst_=bst_->left;
				i++;
		}
		else{
			bst_=bst_->right;
			i++;
		}

	}
	if(check==0)			/*if there is not then prints*/
		printf("\nNot founded!");
	printf(".\n");
	end_b=clock();
	
	printf("\nStructures Stack Queue  Bst   (In search function)\n");
	printf("Exec. Time %.3f %.3f  %.3f\n",(end_s-start_s)/CLOCKS_PER_SEC*1000,(end_q-start_q)/CLOCKS_PER_SEC*1000,(end_b-start_b)/CLOCKS_PER_SEC*1000);	

}
int max(bst *root) {		/*this is finding max number for bst*/
    while (root->right !=NULL) {
     root = root->right;
    }
    return root->value;
}

int find(bst *root, int largest, int current) {		/*this is finding second largest number with respect to lagest's number*/
   while(root !=NULL){
	    if(root->value<largest){
	      current=root->value;
	      root=root->right;
	    } 
	    else{
	      root=root->left;
	    }
   }
  return current;
}		
int min(bst *root){			/*this finds minimum number for bst*/
    while (root->left !=NULL) {
     root = root->left;
    }
    return root->value;
}



void special_traverse(stack *stack_,queue *queue_,bst *bst_){		
	
 stack *temp,*other_s,*head_stack_for_free=stack_;		/*this is temporary pointers for stack*/
 stack *temp2,*temp3,*temp4,*temp5; 	/*this is becouse of sorting,I never change the original stack bst or queue */

 queue *temp_q,*other_q,*head_queue_for_free=queue_;	/*this is temporary pointers for queue*/
 queue *temp2_q,*temp3_q,*temp4_q,*temp5_q; /*this is becouse of sorting,I never change the original stack bst or queue */

 bst *head_bst_for_free=bst_;

 list *a,*c,*temp4_b,*temp5_b,*other_b;  /*this is becouse of sorting,I never change the original stack bst or queue */
 int b,how_many_s=1,how_many_q=1,how_many_b=1;
 double start_s,end_s,start_q,end_q,start_b,end_b;
	printf("\n This is special traverse!\n");
	start_s=clock();
	if(stack_!=NULL){			/*this is same thing with ordering function*/
		temp=(stack*)malloc(sizeof(stack));
		temp->value=stack_->value;
		other_s=temp;
		stack_=stack_->next;
	}
	while(stack_!=NULL){
		temp->next=(stack*)malloc(sizeof(stack));
		temp=temp->next;
		temp->value=stack_->value;
		stack_=stack_->next;
	}
	
	temp2=(stack *)malloc(sizeof(stack));
	temp->next=NULL;
	temp=other_s;
	if(temp!=NULL){			/*this is checking if is empty or not*/
		temp3=temp->next; /*this points temp->next for comparing forward*/
		while(temp->next!=NULL){		/*this is controlling numbers*/
			while(temp3!=NULL){
				if((temp->value)<(temp3->value)){	/*if number is bigger than other*/
				
				temp2->value=temp->value;
				
				temp->value=temp3->value;
				
				temp3->value=temp2->value;
				}
				temp3=temp3->next;	
			}
			temp=temp->next; /*this is going until reaching NULL*/
			temp3=temp->next; /*this points temp->next for comparing forward*/
		}
	}

	temp4=other_s;
	while(temp4->next!=NULL){
		temp4=temp4->next;
		how_many_s++;		/*this counts how many number stack has*/
	}
	temp5=temp4;
	printf("For Stack\n");			/*Firstly I sort in decresing orden then ,I take first number and last number then i did it's next then i take first number and i went forwad to that i found last number so on */
	if(how_many_s==1){
			printf("%d",other_s->value);
	}	
	else if(how_many_s%2==0){		/*this is for if data's size is even*/
		while(temp5!=other_s){
			 temp5=temp4;
			if(other_s!=NULL)
				printf(" %d ",other_s->value);
			if(temp4!=NULL){
				printf("%d",temp4->value);
			}
			 temp4=other_s;
			if(temp4->next!=NULL){
			 while(temp4->next!=temp5){
				temp4=temp4->next;
			 }
			}
			other_s=other_s->next;
		}
	}
	else{			/*this is for if data's size is odd*/
		while(temp5!=other_s){
			 temp5=temp4;
			if(other_s!=NULL)
				printf(" %d ",other_s->value);
			if(other_s!=NULL){
				if(temp5==other_s){	/*this is becouse that number of bst'node doesn't divide by 2*/	     			  
					break;
	       			}
			}	
			if(temp4!=NULL){
				printf("%d",temp4->value);
			}
			 temp4=other_s;
			if(temp4->next!=NULL){
				 while(temp4->next!=temp5){
					temp4=temp4->next;
				 }
			}
			other_s=other_s->next;
		}

	}

	end_s=clock();
	free_stack(other_s);		/*this is deallocating for temporary lists*/
	free_stack(temp2);

	start_q=clock();		
	if(queue_!=NULL){			/*this is sorting in decreasing order*/
		temp_q=(queue*)malloc(sizeof(queue));
		temp_q->value=queue_->value;
		other_q=temp_q;
		queue_=queue_->next;
	}
	while(queue_!=NULL){
		temp_q->next=(queue*)malloc(sizeof(queue));
		temp_q=temp_q->next;
		temp_q->value=queue_->value;
		queue_=queue_->next;
	}
	
	temp2_q=(queue *)malloc(sizeof(queue));
	temp_q->next=NULL;
	temp_q=other_q;
	if(temp_q!=NULL){			/*this is checking if is empty or not*/
		temp3_q=temp_q->next; /*this points temp->next for comparing forward*/
		while(temp_q->next!=NULL){	/*this is controlling numbers*/
			while(temp3_q!=NULL){
				if((temp_q->value)<(temp3_q->value)){	/*if number is bigger than other*/
				
				temp2_q->value=temp_q->value;
				
				temp_q->value=temp3_q->value;
				
				temp3_q->value=temp2_q->value;
				}
					temp3_q=temp3_q->next;	
			}
			temp_q=temp_q->next; /*this is going until reaching NULL*/
			temp3_q=temp_q->next; /*this points temp->next for comparing forward*/
		}

	}

	printf("\nFor Queue\n");/*Firstly I sort in decresing orden then ,I take first number and last number then i did it's next then i take first number and i went forwad to that i found last number so on */
	temp4_q=other_q;
	while(temp4_q->next!=NULL){
		temp4_q=temp4_q->next;
		how_many_q++;
	}
	temp5_q=temp4_q;
	if(how_many_q==1){
			printf("%d",other_q->value);
	}
	else if(how_many_q%2==0){
		while(temp5_q!=other_q){
			 temp5_q=temp4_q;
			if(other_q!=NULL)
				printf(" %d ",other_q->value);
			if(temp4_q!=NULL)
				printf("%d",temp4_q->value);
			 temp4_q=other_q;
			if(temp4_q->next!=NULL){
				 while(temp4_q->next!=temp5_q){
					temp4_q=temp4_q->next;
				 }
			}
			other_q=other_q->next;
		}
	}
	else {
		while(temp5_q!=other_q){
			 temp5_q=temp4_q;
			if(other_q!=NULL)
				printf(" %d ",other_q->value);
			if(other_q!=NULL){
				if(temp5_q==other_q){	/*this is becouse that number of bst'node doesn't divide by 2*/	      			  
					break;
	       			}
			}	
			if(temp4_q!=NULL){
				printf("%d",temp4_q->value);
			}
			 temp4_q=other_q;
			if(temp4_q->next!=NULL){
				 while(temp4_q->next!=temp5_q){
					temp4_q=temp4_q->next;
				 }
			}
			other_q=other_q->next;
		}

	}
	end_q=clock();	
	free_queue(other_q);		/*this is deallocating for temporary lists*/
	free_queue(temp2_q);
	
	start_b=clock();
	printf("\nFor Bst\n");		
	a=(list*)malloc(sizeof(list));		/*I did a temporary list for bst*/
	a->data=max(bst_);
	c=a;
	while(a->data!=min(bst_)){		/*this is sorting in decreasing order*/
		b=find(bst_,a->data,a->data);
		a->next=(list*)malloc(sizeof(list));
		a=a->next;
		a->data=b;
	}
	a->next=NULL;
	other_b=c;
/*Firstly I sort in decresing orden then ,I take first number and last number then i did it's next then i take first number and i went forwad to that i found last number so on */
	
	temp4_b=other_b;
	while(temp4_b->next!=NULL){
		temp4_b=temp4_b->next;
		how_many_b++;
	}
	temp5_b=temp4_b;
	if(how_many_b==1){
			printf("%d",other_b->data);
	}
	else if(how_many_b%2==0){
		while(temp5_b!=other_b){
			 temp5_b=temp4_b;
			if(other_b!=NULL)
				printf(" %d ",other_b->data);	
			if(temp4_b!=NULL)
				printf("%d",temp4_b->data);
			 temp4_b=other_b;
			
			if(temp4_b->next!=NULL){
				 while(temp4_b->next!=temp5_b){
					temp4_b=temp4_b->next;
				 }
			}
			other_b=other_b->next;
		}
	}
	else{
		while(temp5_b!=other_b){
			 temp5_b=temp4_b;
			if(other_b!=NULL)
				printf(" %d ",other_b->data);
			if(other_b!=NULL){
				if(temp5_b==other_b){	/*this is becouse that number of bst'node doesn't divide by 2*/	      			  
					break;
	       			}
			}	
			if(temp4_b!=NULL){
				printf("%d",temp4_b->data);
			}
			 temp4_b=other_b;
			if(temp4_b->next!=NULL){
				 while(temp4_b->next!=temp5_b){
					temp4_b=temp4_b->next;
				 }
			}
			other_b=other_b->next;
		}

	}
	
	printf("\n");
	end_b=clock();
	free_list(c);		/*this is deallocating for temporary lists*/
	
	printf("\nStructures Stack Queue  Bst   (In special_traverse function)\n");
	printf("Exec. Time %.3f %.3f  %.3f\n",(end_s-start_s)/CLOCKS_PER_SEC*1000,(end_q-start_q)/CLOCKS_PER_SEC*1000,(end_b-start_b)/CLOCKS_PER_SEC*1000);	
	
		/*this is deallocating original stack ,bst and queue*/
		/*I already deallocated temporary lists,stacks,bst and queue upper sides*/
		/*If you want to use in main function additinally you can delete this three sentence*/
	free_stack(head_stack_for_free);			
	free_queue(head_queue_for_free);
	free_tree(head_bst_for_free);
	
}


int main()
{
int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17,8, 23, 4};
bst *bst_;
queue *queue_;
stack *stack_;
	fill_structures(&stack_,&queue_,&bst_,data);

	ordered_print(stack_,queue_,bst_);
	
	search(stack_,queue_,bst_,5);

	special_traverse(stack_,queue_,bst_);

	return 0;
}



