#include <stdio.h>
#include <stdlib.h>

/*define that in a node of linked list, there is data and a pointer to the next node
typedef: so that dont need to use struct when needed
*/
typedef struct node 
{
	int data;
	struct node *next;
}node;
node *head = NULL; //first in list
node *tail = NULL; //last place in list

//display the list
void display()
{
	node *p = head;
	printf("\n[");
	
	//start from the head
	while(p != NULL)
	{
		printf(" %d ",p->data);
		/*the arrow (->) is used because p is an structure pointer, 
		it is nessesary to use -> when a pointer point at an structure variable*/
		p = p->next;
	}
	
	printf("]");
}

////linked list length: to use in add function but it create more algorithm complex so scrap this.
//int lengthList()
//{
//	node *lk = (node*) malloc(sizeof(node));
//	lk = head;
//	int i = 0;
//	while (lk->next != NULL)
//	{
//		i++;
//		lk = lk->next;
//	}
//	return i;
//}

///*get a specific node by index: need to check the lengh of the list first,
//then if the index provide is in range then start to get the indexed node*/
//node* getNode(int index)
//{
//	node *lk = (node*) malloc(sizeof(node));
//	lk = head;
//	int i = 0;
//	while (i < index)
//	{
//		lk = lk->next;
//		i++;
//	}
//	return lk;
//}

//create node: create an funtion that return an pointer of node
node* creNode(int data)
{
	node *lk = (node*) malloc(sizeof(node));
	/*
		malloc (memory allocate): create an memory space for the pointer
		(struct node*): is to make the memory allocated the type of node
		sizeof(): define the size of the memory just created to the size in ()
	*/
	lk->data = data;
	lk->next = NULL;
	return lk;
}

//insertion at begining
void addFirst(int data)
{
	if(head == NULL)
	{
		node *lk = creNode(data);
		//when there is no node exsist in the LL, the first node created will be it's head and tail
		head = lk;
		tail = lk;
	}
	else
	{
		node *lk = creNode(data);
		//point the next to the old first node and make the just created node the first node
		lk->next = head;
		head = lk;
	}
}

//insertion at end
void addLast(int data)
{
	//make sure the tail exist
	if (tail == NULL)
	{
		addFirst(data);
	}
	else
	{
		//create a link
		node *lk = creNode(data);
		tail->next = lk; //to direct the old tail to the new tail
		tail = lk; //replace the tail to the newly created tail
	}
}

//add in specific space by index
void add(int data, int index)
{
	int ll = lengthList();
	if (index == 0)
	{
		addFirst(data);
		return;
	}
	else if((ll > 0)&&(index == (ll + 1)))
	{
		addLast(data);
	}
	else if((0 < index)&&(index <= ll))
	{
		//case the index is in bound by head and tail
		node *lk = creNode(data);
		node *temp = (node*) malloc(sizeof(node));
		temp = head;
		int i = 0;
		while (i < index - 1)
		{
			temp = temp->next;
		}	
		lk->next = temp->next;
		temp->next = lk;
	}
	else
	{
		printf("\nIndex is not in bound of head and tail!");
	}
}

//delete begining
void delete_head()
{
	if(head == NULL)
	{
		printf("\nNo head to delete!");
		return;
	}
	else if(head->next == NULL)
	{
		node *temp = head;
		head = NULL;
		tail = NULL;
		free(temp);
		return;
	}
	else
	{
		node *temp = head;
		head = head->next;
		free(temp);
		return;
	}
}

//delete tail
void delete_tail()
{
	
}

//delete node
void delete_node()
{
	
}


int main()
{
 	   
    return 0;
}
