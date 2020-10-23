#define MAX_SRC_WORD 100					//max length of a word

typedef enum {ID, CONSTANT, OPERATOR, PUNCTUATOR} token;	//enum representing token name
typedef struct tokeniser_node{				//record for one node of the linked list
	int line_number;			
	char lexeme [MAX_SRC_WORD];
	token token_name;
	struct tokeniser_node *next;
}t_node;
