/****THis code won't compile ****/
// 


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SRC_WORD 100					//max length of a word
#define MAX_READ_LINE 256

typedef enum {ID, CONSTANT, OPERATOR, PUNCTUATOR, NA} token;	//enum representing token name

typedef struct tokeniser_node{				//record for one node of the linked list
	int line_number;			
	char lexeme [MAX_SRC_WORD];
	token token_name;
	struct tokeniser_node *next;
}t_node;



t_node * create_t_node();
void print_linked_list(t_node* head);
t_node *  tokeniseSourceCode ( char * filename, t_node * head);


t_node * create_t_node()					//this function is gonna create a new node for our linked list
{
	t_node* new = (t_node*) malloc(sizeof(t_node));
	new -> next = NULL;
	new -> line_number = 0;
	new -> token_name = NA;
	return new;
}

void print_linked_list(t_node* head)				// will throw up whatever the tokenizer consumed. It's not gross when it's code. Thank god we're not doctors!
{
	t_node *  p;
	p = head;
	while(p!=NULL)
	{
		printf("(%d, %s, %s) -- ", p->line_number, p->lexeme, p-> token_name );	//printing as a triple here. Don't mind the shabby formatting. 
		p = p -> next;
	}
}

t_node * tokeniseSourceCode (char * filename, t_node * head)	//the function we're actually designing. All other functions are either helpers or drivers. 
{
	FILE * fd_src;
	fd_src = fopen(filename, "r");
	char read_buffer[MAX_READ_LINE]; 
	int line_number = 1;
	char *token_string;
	t_node* head, *p;
	p = head;
	while(fgetc(read_buffer, sizeof(readbuffer), fd_src)!= EOF)
	{
		token_string = strtoken(read_buffer," ");
		while(token_string!=NULL)
		{
			token = 
			case 
		}
	}
}

int main()							//driver function. Might include a call to the print function. 
{
	FILE *fd_src;
	return 0;
	
}

