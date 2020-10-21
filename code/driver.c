#include<stdio.h>
#include<stdlib.h>


int main(){

	while(1){

		int input ;
		scanf("%d",&input);

		switch(input){

			case 0: 
			       printf("\nexits");
			       exit(1);
			       break;

			case 1:
			       printf("\nCreates Parse Tree");
			       break;

			case 2:
				printf("\ntraverse the parse tree and construct type expression table Also print the type errors while traversing the parse tree and accessing the typeExpressionTable.");
				break;

			case 3:
				printf("print parse tree in specified format");
			       break;

			case 4:
			 	printf("Print typeExpressionTable in the specified format.");
			 	break;
			 


		}
	}
	return 0;
}
