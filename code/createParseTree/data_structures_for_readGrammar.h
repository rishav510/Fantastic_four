#define MAX_LINE_LENGTH 256	
#define MAX_WORD_LENGTH 50
typedef struct grammar_node{
	char rhs_term[MAX_WORD_LENGTH]; //each node containing a string
	struct grammar_node* next;
}gnode;

typedef struct grammar_element{
	gnode* head;				//head of the linked list
	char lhs_term[MAX_WORD_LENGTH];	//left hand side term
}gelement;

extern gelement **G;
