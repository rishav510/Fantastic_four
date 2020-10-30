#include "symbolic_constants.h"
#include "identify_token.h"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
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
		case KEYWORD: strcpy(token_name_string, "KEYWORD");
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
	

