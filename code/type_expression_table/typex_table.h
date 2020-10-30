#define MAXX_ARRAY_SIZE 1000
#define MAX_WORD_LENGTH 256
#define NUMBER_OF_VARIABLES 500

typedef struct j2node {
	int r2;
    struct j2node *next;
}jagged_2_node;							//linked list where each node is an integer

typedef struct j3node {
	int r2;
	struct j3node *next;
	jagged_2_node *head; 				
}jagged_3_node;							//linked list where each node is an integer plus a linked list of integers

typedef union{							
	int rect_range[2];
	jagged_2_node *head2;
	jagged_3_node *head3;
}array_range;							//array range can be either an array of 2-element arrays (for rect array) or a list of integers (2 dimensional jagged) or a list of list of integers (3 dimensional jagged)

typedef struct {    
    char arr_type_name[MAX_char];
	int dimensions;
	int r1[2];							//first dimension R1 is always specified as a two number range
	array_range range[MAX_ARRAY_SIZE];	//the remaining dimensions are represented as a union ("array_range") which is controlled by the dimensions tag in array_type_expression
	char basicElementType[MAX_WORD_LENGTH];	//
}array_type_expression;					//the type expression in case the variable is an array type


typedef union variantField{
	char primitive_type_name[MAX_char]; // stores what kind of primitive type is;
	array_type_expression arr_typex ;  	// in case of array type , it stores type Expression of array
}type_expression;						//the type expression can be either a primitive or an array type


typedef struct {
	
	char variable_name[MAX_char]; 	// stores name of the variable 
	int tag ; 						//0 ->>primitive ; 1 --> rectangular ; 2 --> jagged array
    char typerec[MAX_char]; 		//  if array is rectangular type then it stores the whether it is static or dynamic
	type_expression typex;			//stores the complete type expression of the element			
}type_expression_element;			//one element of the type expression table


