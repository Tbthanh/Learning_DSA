#include <stdio.h>

//function to display array
void display(int a[], int length)
{
	printf("\n___________________________________\n");
	if(a)
	{
		for (int i = 0; i < length; i++)
			printf("a[%d] = %d\n", i, a[i]);
		printf("\n___________________________________\n");
		return;
	}
	printf("No array to display!");
	printf("\n___________________________________\n");
}

//selection sort
void selection_sort(int a[], int length)
{
	int min_pos, i, j, temp;
	for (i = 0; i < length - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < length; j++)
		{
			if(a[j] < a[min_pos])
				min_pos = j;
		}
		
		if(min_pos != i)
		{
			temp = a[min_pos];
			a[min_pos] = a[i];
			a[i] = temp;	
		}
		//display(a,length);
	}
	
}

int main()
{
	int length = 10;
	int a[] = {5,6,4,2,8,7,9,0,1,3};
	selection_sort(a,length);
	printf("\nFinal out put:");
	display(a,length);
	return 0;
}
