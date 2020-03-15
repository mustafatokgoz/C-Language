#include<stdio.h>
#include<stdlib.h>
#include<time.h>

						   /*    Mustafa Tokgöz 171044077   */
#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n' && *ch_iter!=13) {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}
char random_letters(){
char r;
	r=rand()%26;
	r=r+97;		/*this return  random letter*/
	return r;
	
}

void print_bulmaca(char bulmaca[][15]){
int i,j;
	printf("\n");
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
		printf("%c ",bulmaca[i][j]);		/*this is printing bulmaca*/
		}
		printf("\n");
	}


}
void reverse_word(char *entered_word,char *reversed_word,int stringlen){
int i;
int a=0;
	for(i=stringlen-1;i>=0;i--){
		reversed_word[a]=entered_word[i];	/*this is taking reverse of word*/
		a++;	
	}
}



int main(){

	int i=0,j=0,x,y,x_new,y_new,stringlen=0,a=0;
	int count_word=0,count=0,t_x,t_y;
	char bulmaca[15][15],entered_word[15],reversed_word[15];
	char *dict[DICT_SIZE];
        int coord[DICT_SIZE][4];    
        char line[LINE_LEN];
	srand(time(NULL));
	FILE *fp = fopen("word_hunter.dat", "r");
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
		bulmaca[i][j]=random_letters();
		}
	}
	
	for(i=0;i<15;i++){
		y=coord[i][0];
		x=coord[i][1];
		y_new=coord[i][2];
		x_new=coord[i][3];
			/*this is assigning words to coordinates*/
		for(j=0;dict[i][j]!=0;j++){ 			
			bulmaca[y][x]=dict[i][j];
			if(x_new>x && y_new>y){
				x++;
				y++;
			}
			else if(x_new>x && y_new==y){
				x++;		
			}
			else if(x_new==x && y_new>y){
				y++;		
			}
			else if(x_new<x && y_new==y){
				x--;		
			}
			else if(x_new==x && y_new<y){
				y--;		
			}
			else if(x_new>x && y_new<y){
				x++;
				y--;		
			}
			else if(x_new<x && y_new>y){
				x--;
				y++;
			}
			else if(x_new<x && y_new<y){
				x--;
				y--;		
			}

		}
			
	}
	print_bulmaca(bulmaca);
	while(count_word!=line_counter/5){		/*if words is done,then game will finish*/
		
		printf("Now Enter the word! (if you want to quit enter -> exit game <-)\n");
		scanf("%s",entered_word);
		if(entered_word[0]=='e' && entered_word[1]=='x' && entered_word[2]=='i' && entered_word[3]=='t'){		/*If you write exit game then you will quit here */
			scanf("%s",entered_word);
			if(entered_word[0]=='g' && entered_word[1]=='a' && entered_word[2]=='m' && entered_word[3]=='e'){				
				return 0;
			}
		}
		y=-1;
		x=-1;
		printf("Please enter its row and column between 0-14\n");
		while(y<0 || y>14){
			printf("r: ");
			scanf("%d",&y);		/*if it isnt between 0 and 14 then this will take number again*/
		}
		while(x<0 || x>14){
		printf("c: ");
		scanf("%d",&x);			/*if it isnt between 0 and 14 then this will take number again*/
		}




		a=0;
		while(entered_word[a]!=0){
			stringlen++;			/*this is calculating string's lenght*/
			a++;
		}
		if(bulmaca[y][x]==entered_word[0]){		/*this is checking all sides if their first letters is equal*/
			t_x=x;
			t_y=y;			
			for(j=0;j<stringlen;j++){
				if(bulmaca[t_y][t_x]==entered_word[j]  || bulmaca[t_y][t_x]==entered_word[j]-32){
					count++;		/*this is counting that theirs equal letters*/
				}
				t_y++;
				t_x++;				
			}
			t_x=x;		/*this  again assign  original place*/
			t_y=y;
			if(count==stringlen){		/*if count is equal to string's lenght then it will replaced from lower character to upper character */
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x++;
					t_y++;				
				}
				count_word++;
			}
			count=0;
			t_x=x;		/*this  again assign  original place*/
			t_y=y;	

			for(j=0;j<stringlen;j++){				/*this is counting that theirs equal letters*/
				if(bulmaca[t_y][t_x]==entered_word[j] || bulmaca[t_y][t_x]==entered_word[j]-32){
					count++;
				}
				t_x++;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){		/*if count is equal to string's lenght then it will replaced from lower character to upper character */
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x++;				
				}
				count_word++;
			}
			count=0;
			t_x=x;			/*this  again assign  original place*/
			t_y=y;

			for(j=0;j<stringlen;j++){			/*this is counting that theirs equal letters*/
				if(bulmaca[t_y][t_x]==entered_word[j] || bulmaca[t_y][t_x]==entered_word[j]-32){
					count++;
				}
				t_y++;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){	/*if count is equal to string's lenght then it will replaced from lower character to upper character */
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_y++;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;
			
			for(j=0;j<stringlen;j++){		/*this is counting that theirs equal letters*/
				if(bulmaca[t_y][t_x]==entered_word[j] || bulmaca[t_y][t_x]==entered_word[j]-32){
					count++;
				}
				t_x--;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){		/*if count is equal to string's lenght then it will replaced from lower character to upper character */
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x--;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;
			
			for(j=0;j<stringlen;j++){		/*this is counting that theirs equal letters*/
				if(bulmaca[t_y][t_x]==entered_word[j] || bulmaca[t_y][t_x]==entered_word[j]-32){
					count++;
				}
				t_y--;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){   /*if count is equal to string's lenght then it will replaced from lower character to upper character */
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_y--;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;

			for(j=0;j<stringlen;j++){		/*this is counting that theirs equal letters*/
				if(bulmaca[t_y][t_x]==entered_word[j] || bulmaca[t_y][t_x]==entered_word[j]-32){
					count++;
				}
				t_x++;
				t_y--;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){		
					if(bulmaca[t_y][t_x]>96){	/*if count is equal to string's lenght then it will replaced from lower character to upper character */
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x++;
					t_y--;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;

			for(j=0;j<stringlen;j++){		/*this is counting that theirs equal letters*/
				if(bulmaca[t_y][t_x]==entered_word[j] || bulmaca[t_y][t_x]==entered_word[j]-32){
					count++;
				}
				t_x--;
				t_y++;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){	/*if count is equal to string's lenght then it will replaced from lower character to upper character */
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x--;
					t_y++;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;
		
			for(j=0;j<stringlen;j++){		/*this is counting that theirs equal letters*/
				if(bulmaca[t_y][t_x]==entered_word[j] || bulmaca[t_y][t_x]==entered_word[j]-32){
					count++;
				}
				t_x--;
				t_y--;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){	/*if count is equal to string's lenght then it will replaced from lower character to upper character */
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x--;
					t_y--;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;

		}
		if(bulmaca[y][x]==entered_word[stringlen-1]){  			/*this part is like upper side*/
			reverse_word(entered_word,reversed_word,stringlen);	/*this is reversing the word*/
			count=0;
			t_x=x;
			t_y=y;			
			for(j=0;j<stringlen;j++){
				if(bulmaca[t_y][t_x]==reversed_word[j]  || bulmaca[t_y][t_x]==reversed_word[j]-32){
					count++;
				}
				t_y++;
				t_x++;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x++;
					t_y++;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;

			for(j=0;j<stringlen;j++){
				if(bulmaca[t_y][t_x]==reversed_word[j] || bulmaca[t_y][t_x]==reversed_word[j]-32){
					count++;
				}
				t_x++;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x++;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;

			for(j=0;j<stringlen;j++){
				if(bulmaca[t_y][t_x]==reversed_word[j] || bulmaca[t_y][t_x]==reversed_word[j]-32){
					count++;
				}
				t_y++;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_y++;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;
			
			for(j=0;j<stringlen;j++){
				if(bulmaca[t_y][t_x]==reversed_word[j] || bulmaca[t_y][t_x]==reversed_word[j]-32){
					count++;
				}
				t_x--;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x--;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;
			
			for(j=0;j<stringlen;j++){
				if(bulmaca[t_y][t_x]==reversed_word[j] || bulmaca[t_y][t_x]==reversed_word[j]-32){
					count++;
				}
				t_y--;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_y--;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;

			for(j=0;j<stringlen;j++){
				if(bulmaca[t_y][t_x]==reversed_word[j] || bulmaca[t_y][t_x]==reversed_word[j]-32){
					count++;
				}
				t_x++;
				t_y--;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x++;
					t_y--;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;

			for(j=0;j<stringlen;j++){
				if(bulmaca[t_y][t_x]==reversed_word[j] || bulmaca[t_y][t_x]==reversed_word[j]-32){
					count++;
				}
				t_x--;
				t_y++;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x--;
					t_y++;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;
		
			for(j=0;j<stringlen;j++){
				if(bulmaca[t_y][t_x]==reversed_word[j] || bulmaca[t_y][t_x]==reversed_word[j]-32){
					count++;
				}
				t_x--;
				t_y--;				
			}
			t_x=x;
			t_y=y;
			if(count==stringlen){
				for(j=0;j<stringlen;j++){
					if(bulmaca[t_y][t_x]>96){
						bulmaca[t_y][t_x]=bulmaca[t_y][t_x]-32;
					}
					t_x--;
					t_y--;				
				}
				count_word++;
			}
			count=0;
			t_x=x;
			t_y=y;

		}
		stringlen=0;
		print_bulmaca(bulmaca);
		
		
	}
		
	return 0;
}






