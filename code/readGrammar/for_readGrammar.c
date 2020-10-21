#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data_structures_for_readGrammar.h"

int count_lines(FILE* fd_grammar)
{
	char c;
	int count = 0;
	fd_grammar = fopen("grammar.txt", "r");
	if(fd_grammar == NULL)
	{
		printf("descriptor read error! can't find grammar.txt");
		exit(1);
	}
	
	for(c = getc(fd_grammar); c!=EOF ; c = getc(fd_grammar))
	{
		if(c == '\n')
		{
			count++;
		}
	}
	return count;
}

gnode* create_gnode()
{
	gnode* new = (gnode*) malloc(sizeof(gnode));
	
	new -> next = NULL;
	return new;
}


gnode* add_to_end(gnode* head)
{
	gnode* p = head,*q;
	
	gnode *new;
	
	q= p->next;
	while(q!=NULL)
	{
		p = q;
		q = q->next;
	}
	new = create_gnode();
	p->next = new;
	return new;
}

