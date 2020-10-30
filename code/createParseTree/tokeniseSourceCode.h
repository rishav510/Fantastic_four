typedef struct tokeniser_node{				//record for one node of the linked list
	int line_number;			
	char lexeme [MAX_SRC_WORD];
	token token_name;
	struct tokeniser_node *next;
}t_node;
void add_to_end(t_node* head, t_node* new);
t_node * create_t_node();
t_node *  tokeniseSourceCode ( char * filename, t_node * head);
