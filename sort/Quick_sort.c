#include <stdio.h>

void display(int a[], int length);
void swap(int *x, int *y);
void quick_sort(int a[], int length);
void qs_recursion(int a[], int low, int hi);
int partition(int a[], int low, int hi); //partition the array around the pivot

int main()
{
	int length = 10;
	int a[] = {5,6,4,2,8,7,9,0,1,3};
	quick_sort(a,length);
	display(a,length);
	return 0;
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

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void quick_sort(int a[], int length) //this fuction made to make it easy to use the quick sort algorithm in the main fuction
{
	qs_recursion(a, 0, length - 1); //low = 0; hi = length -1
}

void qs_recursion(int a[], int low, int hi)
{
	if (low < hi)
	{
		int pivot_index = partition(a, low, hi);
		qs_recursion(a, low, pivot_index - 1); //to sort the left of the array
		qs_recursion(a, pivot_index +1, hi); //to sort the right of the array	
	}
}

int partition(int a[], int low, int hi) //core step of the quick sort algorithm
{
	int pivot_value = a[hi];
	int i = low;
	for (int j = low; j < hi; j++)
	{
		if (a[j] <= pivot_value)
		{
			swap(&a[i], &a[j]);
			printf("a[%d] = %d\n", i, a[i]);
			i++;
		}
	}
	swap(&a[i], &a[hi]); //because the j = hi is not less than hi so that we have to have this
	return i;
}

/*Running the partition function by hand;

a[] = {5,6,4,2,8,7,9,0,1,3}

i                  pivot
5 6 4 2 8 7 9 0 1 [3]
j

i                  pivot
5 6 4 2 8 7 9 0 1 [3]
  j

...

  i                pivot
2 6 4 5 8 7 9 0 1 [3]
      j

    i              pivot
2 0 4 5 8 7 9 6 1 [3]
			  j      
			  
        i          pivot
2 0 4 1 8 7 9 6 5 [3]
			    j
then the swap(&a[i], &a[hi]) happen

        i          pivot
2 0 4 1 3 7 9 6 5 [8]
			    j
    
i will be equal to 2 0 1
*/
