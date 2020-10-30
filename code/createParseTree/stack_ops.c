#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbolic_constants.h"
#include "stack.h"

int is_lhs(char* string_to_push,char array_lhs[][100])
{


	int name_size = 0;
	while(array_lhs[++name_size!]='\0');
	for(int i = 0; i<name_size ; i++)
	{
		if(!strcmp(string_to_push,array_lhs[i])
			return 1;	
	}
	return 0;
}

void push (char *string_to_push, stack *s)
{ 
	
	stack_node* new = (stack_node*) malloc(sizeof(stack_node));
	
	s->top_is_terminal= is_lhs(string_to_push, array_lhs);
	strcpy(new->stack_word,string_to_push);
	new ->next = s->top;
	s->top = new;
	return;
} 

char* pop (stack *s)
{
	char* str;
	if (s-> top == NULL)
		return NULL;

	strcpy(str,s->top->stack_word);
	s->top = s->top->next;
	return str;
}


