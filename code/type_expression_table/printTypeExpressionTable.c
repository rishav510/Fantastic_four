#include<stdio.h>
#include<stdlib.h>
#include "typex_table.h"



void printTypeExpressionTable(type_expression_element table[NUMBER_OF_VARIABLES])
{
	int i = 0,j,k;
	printf("\nField 1\tField 2\tField 4);
	while(table[i]->variable_name!=NULL)
	{
		i++;
		printf("\n%s\t",table[i]->variable_name);
		switch(table[i]->tag)
		{
			case 0:
			printf("primitive\t"); break;
			case 1:
			printf("rectangular array\t"); break;
			case 2:
			printf("jagged array\t"); break;
			
		}
		printf("%s\t",table[i]->typerec);
		printf("<type = ");
		if(table[i]->tag == 0)
			printf("%s>",table[i]->typex->primitive_type_name);
		else
		{
			printf("%s",table[i]->typex->arr_typex->arr_type_name);
			printf(", dimensions = %d, ",table[i]->typex->arr_typex->dimensions);
			printf("range_R1 = (%d,%d)",table[i]->typex->arr_typex->r1[0],table[i]->typex->arr_typex->r1[1]);
			if(table[i]->tag == 1)
			{
				int j = 0;
				while(table[i]->typex->arr_typex->range->rect_range[0]!=-1)
				{
					printf(", range_R%d = (%d,%d)",(j+2),table[i]->typex->arr_typex->range[j]->rect_range[0],table[i]->typex->arr_typex->range[j]->rect_range[1]);
					j++;
				}
				
			}
			else if(table[i]->tag == 2)
			{
				if(table[i]->typex->arr_typex->dimensions ==2)
				{
					
								
					jagged_2_node *p = table[i]->typex->arr_typex->range[j]->head2;
					printf(", range_R2 = (");
					while(p != NULL)
					{
						if(p->next == NULL)
						{
							printf("%d)",p->r2);
							break;
						}
						printf("%d, ",p->r2);
						p = p->next;
						
					}
				}
				else if(table[i]->typex->arr_typex->dimensions == 3)
				{
					jagged_3_node *q;
					jagged_2_node* p;
					
					
				}
			}
			
		}
	}
}
