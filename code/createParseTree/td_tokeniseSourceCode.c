/****THis code won't compile ****/
// 


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
void print_linked_list(t_node* head);
t_node *  tokeniseSourceCode ( char * filename, t_node * head);





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



int main()							//driver function. Might include a call to the print function. 
{

	t_node* head = create_t_node();
	head = tokeniseSourceCode("src.txt",head);
	print_linked_list(head);
	return 0;
}
