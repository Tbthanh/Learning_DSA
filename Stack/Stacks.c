#include <stdio.h>
#include <string.h>

/*
size : tra ve kich thuoc hien tai cua stack.
empty : true neu stack rong, và nguoc lai.
push : day phan tu vào stack.
pop : loai bo phan tu o dinh cua stack.
top : truy cap toi phan tu o dinh stack.
*/

int size(char* stack);
void empty(char *stack);
void push(char *stack);

//void pop(char *stack);
//
//void top(char *stack);
//
//void reverse_str(char *stack);

//Main function

int main()
{
	char a[1000];
	gets(a);
	printf("you entered: \"%s\"\n",a);
	printf("the length is: %d\n", size(a)); //test the size function
	empty(a);
	printf("deleting the stack: %s",a);
    return 0;
}

int size(char *stack)
{
	return strlen(stack);
}

void empty(char *stack)
{
	strcpy(stack,"\0");
}

void push(char *stack)
{
	
}

//void reverse_str(char *stack)
//{
//	
//}
//
//void top(char *stack)
//{
//	
//}

