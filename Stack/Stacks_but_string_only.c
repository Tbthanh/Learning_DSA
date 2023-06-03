#include <stdio.h>
#include <string.h>

/*
A BIT OF EXPLAINATION BUT IN VIETNAMESE, TO LAZY TO TRANSLATE SO DONT ASK ¯\_(¯^¯)_/¯

size : tra ve kich thuoc hien tai cua stack.
empty : true neu stack rong, và nguoc lai.
push : day phan tu vào stack.
pop : loai bo phan tu o dinh cua stack.
top : truy cap toi phan tu o dinh stack.
reverse_stk: lon nguoc stack
*/


/* ---------------------FUCTION DECLARATION-------------------- */
int size(char* stack);
void empty(char *stack);
void push(char *stack,char *pushin);
void pop(char *stack);
//void top(char *stack);
void reverse_stk(char *stack);
//void encodeString(char *stack);


/* ------------------------MAIN FUCTION------------------------ */
int main()
{
	char a[1000];
	gets(a);
	printf("you entered: \"%s\"\n",a);
	
	
	/* ------------------------TESTING ZONE------------------------ */
	
	/*test the size function*/
	printf("the length is: %d\n", size(a)); 
	
	/*test the empty function*/
//	empty(a);
//	printf("deleting the stack: %s",a);

	/*test the reverse function*/
	reverse_stk(a);
	printf("reverse the stack: %s\n",a);
	
	reverse_stk(a);
	pop(a);
	printf("after pop the stack: %s\n",a);
	
	push(a," , nyoooooooo.");
	printf("after push the stack: %s\n",a);
	
	/* ---------------------END OF TESTING ZONE-------------------- */
	
    return 0;
}


/* ----------------------FUCTION ARGUMENT---------------------- */
int size(char *stack)
{
	return strlen(stack);
}

void empty(char *stack)
{
	strcpy(stack,"\0");
}

void push(char *stack,char *pushin) //Let's skip the proplem with stack limit for now, cuz ...; also this push(*stack) is diffrent from push(g)
{
	strcat(stack,pushin);
}

void pop(char *stack)
{
	int a = size(stack) - 1;
	stack[a] = '\0';
}

//void top(char *stack)
//{
//	
//}

void reverse_stk(char *stack)
{
	char a[1000];
    int c = strlen(stack);
    int d = c - 1;
    for (int i = 0; i < c; i ++)
    {
		a[i] = stack[d];
		d--; 
	}
	strcpy(stack,a);
}

//void encodeString(char *stack)
//{
//	
//}


