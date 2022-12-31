#include<stdio.h>
#include<stdlib.h>
struct stack
{ int top ;
int size;
char arr[100]; 
};
////////////////////////
int checker(struct stack *sp, char a)
{if((sp->arr[sp->top]=='{')&&(a=='}'))
{
	return 1;
}
else if((sp->arr[sp->top]=='(')&&(a==')'))
{
	return 1;
}
	else if((sp->arr[sp->top]=='[')&&(a==']'))
{
	return 1;
}
else{
	return 0;
}
}
///////////////////////////////////// is full /////////////////////////
int isfull(struct stack *sp)
{
	 if( sp->top==sp->size-1)
	 {
	 	return 1;
	 }
	 return 0;
}
//////////////////////////////is empty/////////////////////
int isempty(  struct stack *sp )
{
	if((sp->top)==-1)
	{
	return 1;
	}
	return 0;
}
////////////////////// push /////////////////
void push( struct stack *sp,char value)
{ if( isfull(sp))
{ printf("stack is overflow \n");

	return;
}
else{
	sp->top++;
	 sp->arr[sp->top]=value;
}

}
///////////////////// pop //////////////////////////
int pop(struct stack *sp )
{
	if(isempty(sp))
	{
		// printf( "unbalance equation \n");
		  return 0 ;
	}
	else
	{
		  sp->top--;
		    return 1;
	}
}

//////////////////////////////////////peek /////////////////////
char peek( struct stack *sp , int index)
{ 
if( (sp->top-index)<0)
{ 
printf(" invaid input! \n");
return -1;
}
return sp->arr[sp->top-index];
}	



/////////////////////////////////////
void  parnthesis_match( struct stack* sp,char*arr)
{ int i=0;
	while(arr[i]!='\0')
	{
		if( arr[i]=='{'||arr[i]=='('||arr[i]=='[')
		{
			push(sp,arr[i]);
	
			
		}
		else if(arr[i]=='}'||arr[i]==')'||arr[i]==']')
	{
		if(!checker(sp,arr[i]))
		{
			printf( "unbalance equation \n");
			return ;
		}
		if(checker(sp,arr[i]))
		{
			pop(sp);
		}
	}
		i++;
	}
	if(isempty(sp))
	{
		printf("balance equation \n");
		return;
	}
	if(!isempty(sp))
	{	printf("unbalance equation \n");
		 return ;
	}
}
int main()
{
struct stack *sp= (struct stack*)malloc(sizeof(struct stack));
sp->top=-1;
char arr[]="({49()[]})";
sp->size=100;
 parnthesis_match(  sp,arr);

return 0 ;}

