#include <stdio.h>

//function to display array
void display(int a[], int length)
{
	printf("\n___________________________________\n");
	if(a)
	{
		for (int i = 0; i < length; i++)
			printf("a[%d] = %d\n", i, a[i]);
		printf("___________________________________\n");
		return;
	}
	printf("No array to display!");
	printf("\n___________________________________\n");
}

//insertion sort function
void insertion_sort(int a[], int length)
{
	int i, j, temp;
	for (i = 1; i < length; i++)
	{
		temp = a[i];
		j = i - 1;
		
		while(j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
		display(a,length);
	}
}


int main()
{
	int length = 10;
	int a[] = {5,6,4,2,8,7,9,0,1,3};
	insertion_sort(a,length);
	display(a,length);
	return 0;
}
