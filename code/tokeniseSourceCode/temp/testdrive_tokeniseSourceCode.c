

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

void add_to_end(t_node* head, t_node* new)
{
	t_node* p = head;
	if(head==NULL)
	{
		head = new;
		return;
	}
	while(p->next != NULL)
		p = p->next;
	p->next = new;
	return;
}

void print_linked_list(t_node* head)				// will throw up whatever the tokenizer consumed. It's not gross when it's code. Thank god we're not doctors!
{
	t_node *  p;
	p = head->next;
	char token_name_string[MAX_SRC_WORD];
	
	while(p!=NULL)
	{
		
		switch(p->token_name)
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
		printf("(%d, %s, %s)\t", p->line_number, p->lexeme, token_name_string );	//printing as a triple here. Don't mind the shabby formatting. 
		p = p -> next;
	}
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
				add_to_end(head,new);
			}
			token_string = strtok(NULL," ");
		
		}
	}
	return head;
}

int main()							//driver function. Might include a call to the print function. 
{

	t_node* head = create_t_node();
	head = tokeniseSourceCode("src.txt",head);
	print_linked_list(head);
	return 0;
	
}

