

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbolic_constants.h"
#include "identify_token.h"




typedef struct tokeniser_node{				//record for one node of the linked list
	int line_number;			
	char lexeme [MAX_SRC_WORD];
	token token_name;
	struct tokeniser_node *next;
}t_node;



t_node * create_t_node();

t_node *  tokeniseSourceCode ( char * filename, t_node * head);


t_node * create_t_node()					//this function is gonna create a new node for our linked list
{
	t_node* new = (t_node*) malloc(sizeof(t_node));
	new -> next = NULL;
	new -> line_number = 0;
	new -> token_name = NA;
	return new;
}

t_node* add_to_end(t_node* head, t_node* new)
{
	t_node* p = head;
	if(head==NULL)
	{
		new = head;
		return head;
	}
	while(p->next != NULL)
		p = p->next;
	p->next = new;
	return head;
}


t_node * tokeniseSourceCode (char * filename, t_node * head)	//the function we're actually designing. All other functions are either helpers or drivers. 
{
	FILE * fd_src;
	fd_src = fopen(filename, "r");
	char read_buffer[MAX_READ_LINE]; 
	int line_number = 0;
	char *token_string;
	t_node *new;
	
	
	while(fgets(read_buffer, sizeof(read_buffer), fd_src)!= NULL)
	{
		line_number++;
		if(read_buffer[strlen(read_buffer)-1] == '\n')
			read_buffer[strlen(read_buffer)-1] = '\0';
		token_string = strtok(read_buffer," ");
		
		while(token_string!=NULL)
		{
			if(strcmp(" ",token_string))
			{
				new = create_t_node();
				new->line_number = line_number;
				new->token_name = identify_token(token_string);
				strcpy(new->lexeme,token_string);
				head  = add_to_end(head,new);
			}
			token_string = strtok(NULL," ");
		
		}
	}
	return head;
}


