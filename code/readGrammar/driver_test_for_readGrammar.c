#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data_structures_for_readGrammar.h"
#include "for_readGrammar.h"

gelement* readGrammar(gelement*);

void print_gnodes(gnode*);

void print_gnodes(gnode* head)
{
	gnode* p = head;
	while(p->next!=NULL)
	{
		printf("%s->", p->rhs_term);
		p = p->next;
	}
	printf("NULL\n");
}


int main()
{
	int i, count;
	FILE *fd_grammar;
	count = count_lines(fd_grammar);
	gelement G[count];
	gelement *p = G;
	
	
	
	p = readGrammar(G);
	
	for(i = 0; i<count;i++)					//loop over total number of lines in "grammar.txt"

	{
		printf("\n%s:==", p[i].lhs_term);			//print each lhs first 
		print_gnodes(p[i].head);				//print rhs in format specified by print_gnodes function
	}
	
	return 0;
}
