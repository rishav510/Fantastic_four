#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data_structures_for_readGrammar.h"
#include "for_readGrammar.h"

gelement* readGrammar(gelement* G)
{
	int i =0,count;
	
	FILE *fd_grammar = fopen("grammar.txt","r");
	
	char line_buffer[MAX_LINE_LENGTH];					//declare a character array for storing each line of the file.
	
	char *token; 								// declare a character pointer which is used for tokenising each line.
	
	char delimiter[2] = " ";						//declare a delimiter string for tokenization. (i.e. whitespace)
	
	
										// file descriptor for "grammar.txt"
	
	count = count_lines(fd_grammar);
	
	
	
	for(i=0;i<count;i++)					
	{
		if(fgets(line_buffer,sizeof(line_buffer),fd_grammar)!=NULL) 	//if there is something to read in that line, store it in line_buffer and ...
		{
			token = strtok(line_buffer,delimiter);		//tokenize strtok for the first time on delimiter " "
			
			strcpy(G[i].lhs_term, token);			//copy the first token into the array cell
			
			gnode* new;						//declare a new node
			
			token = strtok(NULL, delimiter);
			
			if(token[strlen(token) -1 ] == '\n')
				token[strlen(token) - 1] = '\0';
			
			G[i].head = create_gnode();	
			
			while(token!=NULL)					//while there are more tokens
			{

				new = add_to_end(G[i].head);	//add
				
				strcpy(new->rhs_term, token);
				
				token = strtok(NULL,delimiter);
			}
		}
	
	}
	
	
	
	
	return G;
}
