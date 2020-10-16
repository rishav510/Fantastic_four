#include<stdio.h>
int correct_id(char * s)
{
	int count =0;
	
	if(*s >= 48 && *s<=57)
		return 0;
	while(*s)
	{
		if(!(*s ==95 || (*s>=65 && *s<= 90) || (*s>=97&&*s<=122) || (*s>=48&&*s<=57)))
			return 0;
		count++;
		s++;
	}
	if(count>20)
		return 0;
	return 1;
}

int main()
{
	char string[200];
	scanf("%s",string);
	int cond = correct_id(string);
	printf("\t%d",cond);
	return 0;
}
