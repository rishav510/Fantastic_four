#include<stdio.h>
#include<string.h>
#include "symbolic_constants.h"



int is_ID(char* token_string)
{
	char *c =token_string; 
	if(!(*c==95 || (*c>=65&&*c<=90) || (*c>=97 && *c<=122)))
		return 0;
		
	while(*c)
	{
		if( !((*c==95) || (*c>=65 && *c<=90) || (*c>=97 && *c <=122)|| (*c>=48 && *c<=57)))
			return 0;
			
		c++;
	}
	return 1;
}
/*
int main()
{
	char str[MAX_WORD_LENGTH];
	while(1)
	{
		scanf("%s",str);
		printf("\n%d",is_identifier(str));
	}
	return 0;
}
*/
