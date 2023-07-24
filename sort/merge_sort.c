#include <stdio.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);
void display(int a[], int length);

int main()
{
	int a[] = {234, 23, 948, 217, 473, 12, 85, 93, 169, 420};
	int length = 10;
	
	merge_sort(a, length);
	
	display(a, length);
	
	return 0;
}

void merge_sort(int a[], int length)
{
	merge_sort_recursion(a, 0, length - 1);	
}

void merge_sort_recursion(int a[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
	
		merge_sort_recursion(a, l, m);
		merge_sort_recursion(a, m + 1, r);
		
		merge_sorted_arrays(a, l, m, r);	
	}
}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
	int left_length = m - l + 1;
	int right_length = r - m;
	
	int temp_l[left_length];
	int temp_r[right_length];
	
	int i, j, k;
	
	for (int i = 0; i < left_length; i++)
	{
		temp_l[i] = a[l + i];
	}
	
	for (int i = 0; i < right_length; i++)
	{
		temp_r[i] = a[m + i + 1];
	}
	
	for(i = 0, j = 0, k = l; k <= r; k++) // k is index for a[] from l to r; i is for left, j is for right.
	{
		if ((i < left_length) && (j >= right_length || temp_l[i] <= temp_r[j]))
		{
			a[k] = temp_l[i];
			i++;
		}
		else
		{
			a[k] = temp_r[j];
			j++;
		}
	}
}

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

