#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbolic_constants.h"
#include "stack.h"


void push (char *string_to_push, stack *s)
{ 
	
	stack_node* new = (stack_node*) malloc(sizeof(stack_node));
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


