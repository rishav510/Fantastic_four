#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbolic_constants.h"

	


int is_constant(char* token_string) 
{
	int flag = 0;
	char c;
	for(int i = 0; i<strlen(token_string);i++)
	{
		c = token_string[i];
		if(c>=48 && c<=57)
			continue;
		if(c == '.')
			flag++;
		else
			return 0;
	}
	if(!(flag>1))
		return 1;
	return 0;
}
/*
int main()
{
	while(1)
	{
		char token_string[MAX_SRC_WORD];
		printf("\n");
		scanf("%s",token_string);
		printf("\n%d",is_constant(token_string));
	}
	return 0;
}
*/
