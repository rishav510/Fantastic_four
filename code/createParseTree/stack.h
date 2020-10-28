typedef struct s_node{
	char stack_word[MAX_WORD_LENGTH];
	struct s_node * next;
}stack_node;
typedef struct{
	int top_is_terminal;
	stack_node *top;
}stack;

void push (char *string_to_push, stack *s);
char* pop (stack *s);
