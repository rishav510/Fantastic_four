typedef struct s_node{
	char stack_word[MAX_WORD_LENGTH];
	struct s_node * next;
}stack_node;
typedef struct{
	int top_is_terminal;
	stack_node *top;
}stack;
char array_lhs[][100] = {"STMTS", "DECLARE_STMTS", "ASSIGNMENT_STMTS", "DECLARE_STMT", "SINGLELINE_DECLARE_STMT", "MULTILINE_DECLARE_STMT", "R1_ARRAY", "TYPE", "DIM2", "ELEMS", "LIST_NUM", "IDS", "ASSIGNMENT_STMT", "ARITHMETIC_EXPR", "LINEAR_EXPR", "FACTOR", "VAR", "ARRAY_ELEMENT", "LIST_INDICES", "BOOLEAN_EXPR", "OR_EXPR", "AND_EXPR", "ID_NUM", "DIM"};

void push (char *string_to_push, stack *s);
char* pop (stack *s);
int is_lhs(char* string_to_push,char array_lhs[][100]);



