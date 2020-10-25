#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbolic_constants.h"

				//max length of a word


int is_keyword(char* token_string) 
{
	char array_of_keywords [][MAX_SRC_WORD] = {"program" , "declare" , "list",  "of", "variables", "array", "size", "values", "jagged", "integer", "real", "boolean"};
	for(int i = 0; i<11;i++)
	{
		if(!strcmp(array_of_keywords[i], token_string))
			return 1;
	}
	return 0;
}
/*
int main()
{
	char string[MAX_SRC_WORD];
	while(1)
	{
		scanf("%s",string);
		printf("\n%d", is_keyword(string));
	}
	return 0;
}
*/
