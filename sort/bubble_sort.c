#include <stdio.h>
#include <stdbool.h>

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

//bobble sort algorithm
void bubble_sort(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				display(a,length);
				
			}
		}
	}
}

//follow the guide from: https://youtu.be/YqzNgaFQEh8
void bubble_sort_PCYT(int a[], int length)
{
	
	for (int i = 0; i < length; i++)
	{
		bool swapped = false;
		do
		{
			swapped = false;
			for (int j = 0; j < length - 1 - i; j++)
			{
				if (a[j] > a[j + 1])
				{
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
					display(a,length);
					swapped = true;
				}
			}
		} while (swapped);
	}

}

//follow the improved code in the DSA made easy.
void bubble_sort_book_improved(int a[], int length)
{
	int swapped = 1;
	for (int i = 0; (i < length) && (swapped); i++)
	{
		swapped = 0;
		for (int j = 0; j < length - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				swapped = 1;
				display(a,length);
				
			}
		}
	}
}

int main(void)
{
	int length = 10;
	
	int a[] = {5,6,4,2,8,7,9,0,1,3};
	
	bubble_sort_book_improved(a, length);
	
//	int b[] = {1,3,7,9,0,2,4,5,8,6};
//	
//	bubble_sort_PCYT(b, length);	
	
	display(a,length);
	
	return 0;
}
