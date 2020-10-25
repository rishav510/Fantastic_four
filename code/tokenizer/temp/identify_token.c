#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SRC_WORD 100					//max length of a word
#define MAX_READ_LINE 256

typedef enum {ID, CONSTANT, OPERATOR, PUNCTUATOR, NA} token;

void print_token_name(char * token_string);

token identify_token(char *token_string);

token identify_token(char *token_string)
{
	token t_name;
	char word[MAX_SRC_WORD];
	
	strcpy(word,token_string);
	
	
	
	if(!strcmp(word,"+") || !strcmp(word,"-") || !strcmp(word,"*") || !strcmp(word,"/") || !strcmp(word,"|||") || !strcmp(word,"&&&") || !strcmp(word,"="))
	
		t_name = OPERATOR;
	
	else
		t_name = NA;
	return t_name;
		
}





void print_token_name(char * token_string)
{
	token t_name = identify_token(token_string);
	char token_name_string[MAX_SRC_WORD];
	switch(t_name)
	{
		case ID: strcpy(token_name_string,"ID");
				break;
		case CONSTANT: strcpy(token_name_string,"CONSTANT");
				break;
		case OPERATOR: strcpy(token_name_string,"OPERATOR");
				break;
		case PUNCTUATOR: strcpy(token_name_string,"PUNCTUATOR");
				break;
		case NA: strcpy(token_name_string,"NA");
	
				break;		
	}
	printf("(%s, %s) ", token_string, token_name_string);
	return ;
}

int main()							//driver function. Might include a call to the print function. 
{
	FILE * fd_src = fopen("src.txt","r");
	if(fd_src == NULL)
	{
		printf("Error! Cannot find src.txt");
	}
	char line_buffer[MAX_READ_LINE];
	char *token_string;
	
	token t_name; 
	while(fgets(line_buffer, sizeof(line_buffer),fd_src)!=NULL)
	{
		if (line_buffer[strlen(line_buffer)-1] == '\n')
			line_buffer[strlen(line_buffer)-1]=0;
		strcat(line_buffer,"\0");
		printf("\n");
		token_string = strtok(line_buffer," ");
		
		while(token_string!=NULL)
		{
			
			print_token_name(token_string);
			token_string = strtok(NULL," ");
		}
		
		
	}
	return 0;
}
	
	
	

