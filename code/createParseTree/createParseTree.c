#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "parse_tree_node.h"
#include "tokeniseSourceCode.h"
#include "readGrammar.h"
#include "stack.h"
#include "data_structures_for_readGrammar.h"

stack main_stack;

int search_lhs(gelement* head)
{
	
}

int expansion(parse_tree_node* pnode, gelement* grammar_node, stack* main_stack); // same as f1

int propagation(parse_tree_node* pnode, t_node* toke_stream token_node); // same as f2


int createParseTree(parse_tree_node* head, t_node* token_stream_head, gelement* grammar)
{
	
	stack aux_stack;

	push(g->lhs_term,&main_stack);
	parse_tree_node* p = head;
	
	
	
	 // if there is an expansion p->child
	 // if there is no expansion p->sibling
	 
	 //when expansion, calling with head
	 //when terminal, call with head->next
	 
	 //if calling function rule works return 1
	 //if calling function rule doesn't work return 0
	 
	 
	 //checking for expansion: use top_is_terminal
	 
	 
	 /*
	 	f1()
	 	{
	 		f1() if non-terminal
	 		
	 		f2() if terminal
		}
		
		f2()
		{
			f1() if non-terminal
			
			f2() if terminal
		}
	 */
	
	
	
	return;
}


int expansion(parse_tree_node* pnode, gelement* grammar_node, stack* main_stack)
{
	char compare[MAX_WORD_LENGTH];
	int check_terminal = main_stack-> top_is_terminal;
	strcpy(compare,pop(main_stack));
	
	if(check_terminal)
	{
		
	}
	
	else
	{
	}
	
	
}
