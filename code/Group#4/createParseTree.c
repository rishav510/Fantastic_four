#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "parse_tree_node.h"
#include "tokeniseSourceCode.h"
#include "readGrammar.h"
#include "stack.h"
#include "data_structures_for_readGrammar.h"

int expansion(parse_tree_node* pnode, gelement* begin, gelement* grammar_rule, t_node* token_node, int depth); // recursively expand non terminals in the grammar till the top of the stack is a terminal, upon which it calls propagation()

int propagation(parse_tree_node* pnode, gelement* begin, gelement* grammar_rule, t_node* token_node, int depth); // propagates across terminals in the token stream till there is a mismatch and calls expansion() when it encounters a non-terminal

stack main_stack;	//global variable for maintaining a main stack

gelement* new_grammar_rule(gelement* begin, char* lhs_string)	//searches for the grammar rule whose lhs string matches the string taken as parameter
{
	gelement* p = begin;
	while(p!=NULL)
	{
		if (!strcmp(p->lhs_term,lhs_string)
			return p;
		
	}
	printf("No grammar rule found!"); // in the event that no suitable grammar rule has been found whose lhs matches the parameter string
	exit(1);
}
int search_lhs(gelement* rule)	//returns the next rule with the same lhs_string as the rule being passed as parameter
{
	gelement* p=rule;
	p++;
	if(!strcmp(p->lhs_term,rule->lhs_term))
	{
		rule = p;
		return 1;
	}
	return 0;
}



parse_tree_node*  createParseTree(parse_tree_node* root, t_node* token_stream_head, gelement* begin) // creates the complete parse tree and returns the root node to the caller
{
	
	
	
	push(begin->lhs_term,&main_stack);
	if(expansion(root, begin, begin, token_stream_head, 0)) // expands the start symbol and is supposed to recursively generate the whole parse tree.
		printf("Parse tree created successfully);
	return root;
	
	
	
	 // if there is an expansion p->child
	 // if there is no expansion p->sibling
	 
	 //when expansion, calling with head
	 //when terminal, call with head->next
	 
	 //if calling function rule works return 1
	 //if calling function rule doesn't work return 0
	 
	 
	 //checking for expansion: use top_is_terminal
	 

	
	
	

}


int expansion(parse_tree_node* pnode, gelement* begin, gelement* grammar_rule, t_node* token_node, int depth) 
{
	parse_tree_node* pnode = (parse_tree_node*)malloc(sizeof(parse_tree_node));
	pnode->depth = depth+1;
	strcpy(pnode->symbol_name,grammar_rule->lhs_term);
	pnode->sibling = NULL;
	pnode -> child = NULL;
	pnode->node_type = NON_LEAF; //call the node a leaf
	
	do{
		stack aux_stack;
		char lhs_string[MAX_WORD_LENGTH];
		int check_terminal; 
		strcpy(lhs_string,pop(&main_stack));
		
		gnode* p = grammar_rule->head;
		int propagation_success,expansion_sucess;
		stack_node* stack_pointer = main_stack->top;
		
		
		
		//char temp_string[MAX_WORD_LENGTH];
		while(p!=NULL)	//pushing rhs of rule into aux stack
		{
			push(p->rhs_term,aux_stack);
			p = p->next;
		}
		while(aux_stack->top!=NULL)
		{
			stack_count++;
			push(pop(aux_stack),main_stack));
		}
		
		check_terminal = main_stack-> top_is_terminal;

	
		if(check_terminal)
		{
			
			t_node* lookeahead = token_node; 
			propagation_success = propagation(pnode->child, begin, grammar_rule, lookahead, pnode->depth);
			if(propagation_success)
				return 1;
			else
			{
				while(main_stack->top != stack_pointer)
					pop(&main_stack);
				
				push(lhs_string,&main_stack);
				lookeahead = token_node;
				continue;
			}
		}
		
		else
		{
			
			expansion_success = expansion(pnode->child, begin, new_grammar_rule(G,lhs_string), token_node, depth);
			if(expansion_success)
			{
				return 1;
			}
			else
			{
				continue;
				
			}
		}
	
	}while(search_lhs(grammar_rule));
	printf("\nError: Could not create parse tree.");
	exit(1);
}

int propagation(parse_tree_node* p, gelement* begin, gelement* grammar_rule, token_node, depth) 
{
	gnode* rhs = grammar_rule->head;
	p = (parse_tree_node*) malloc(sizeof(parse_tree_node));
	
	parse_tree_node* pt_pointer = pnode;
	while(rhs!=NULL)
	{
		if(main_stack->top_is_terminal)
		{
			if(!strcmp(rhs->rhs_term,main_stack->top->stack_word))
			{
				pt_pointer->symbol_name = main_stack->top->stack_word;
				pt_pointer->node_type = LEAF; 
				pt_pointer->depth = depth;
				pop(&main_stack);
				token_node = token_node->next;
				pt_pointer->child = NULL;
				pt_pointer = pt_pointer -> sibling;
				
			}
			else
				return 0;
			
				
		}
		else
		{
			
			expansion(pt_pointer->sibling,begin, grammar_rule, token_node, depth);
			pt_pointer = pt_pointer -> sibling;
		}
		rhs = rhs ->next;
		
	}
	
}


