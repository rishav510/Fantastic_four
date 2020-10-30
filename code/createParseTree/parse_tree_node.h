typedef enum ntype {LEAF, NON_LEAF};

typedef struct lnode{
	char lexeme[MAX_SRC_WORD];
	int line_number;
}leaf_node

typedef struct nlnode{
	type_expression typex;
	gelement grammar_rule;
}nonleaf_node;

typedef union node_struct{
	leaf_node l_node;
	nonleaf_node nl_node;
} node_structure;

typedef struct pt_node{
	struct parse_tree_node* child;
	struct parse_tree_node* sibling;
	ntype node_type;
	node_structure nstr;
	char symbol_name[MAX_WORD_LENGTH];
	int depth;
	
}parse_tree_node;
