#define SIZE 1000
#define MAX_char 256

typedef struct node {
	int data;
        struct node *next;
	}Node;

typedef struct typeExpression{
        
        char type[MAX_char];
	int dimension ;
        int recArray[SIZE][2];
	Node *jaggedArray[SIZE];
	char basicElementType[MAX_char];
   }typeE;


  typedef union varientField{
	        char Ptype[MAX_char]; // stores what kind of primitive type is;
		typeE expression ; // in case of array type , it stores type Expression of array
	}TypeExpress;



   typedef struct typeExpTable{
		
            char name[MAX_char]; 	// stores name of the variable 
	    int tag ; 			/// 0 ->>primitive ; 1 --> rectangular ; 2 --> jagged array
            char typerec[MAX_char]; 	//  if array is rectangular type then it stores the whether it is static or dynamic
	    TypeExpress texpress ;
         }TEtable ;
    
	
