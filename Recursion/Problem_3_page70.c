#include <stdio.h>
#include <stdlib.h>

char A[10];

//Generate all the strings of n bits. Assume A[0..n – 1] is an array of size n.
void binary(int n)
{
	if(n < 1)
		printf("\n%s",A);
	else
	{
		A[n-1] = 0;
		binary(n-1);
		A[n-1] = 1;
		binary(n-1);
	}
}

int main()
{
	binary(3);
	return 0;
}

