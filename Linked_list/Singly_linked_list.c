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
	if(index < 0)
	{
		printf("Index Error");
		return;
	}
	if (index == 0)
	{
		addFirst(data);
		return;	//so that if will not be repeated!
	}
	int i = 0;
	node *temp = head;
	while (temp->next != NULL)
	{
		if (i == index - 1)
		{
			node *lk = creNode(data);
			lk->next = temp->next;
			temp->next = lk;
			return;
		}
		temp = temp->next;
		i++;
	}
	if (i == index - 1)
		{
			addLast(data);
			return;
		}
	printf("Index exceed tail.");
}

//delete begining
void delHead()
{
	if(head == NULL)
	{
		printf("\nNo list to work!");
		return;
	}
	if(head->next == NULL)
	{
		node *temp = head;
		head = NULL;
		tail = NULL;
		free(temp);
		return;
	}

	node *temp = head;
	head = head->next;
	free(temp);
}

//delete tail
void delTail()
{
	if (tail = NULL)
	{
		printf("\nNo list to work!");
		return;
	}
	if (tail == head)
	{
		delHead();
		return;
	}
	node *lk = head;
	while (lk->next->next !=NULL)
	{
		lk = lk->next;
	}
	node *temp = lk->next;
	lk->next = NULL;
	tail = lk;
	free(temp);
}

//delete node
void del(int index)
{
	if(index < 0)
	{
		printf("Index Error");
		return;
	}
	if (index == 0)
	{
		delHead();
		return;	//so that if will not be repeated!
	}
	int i = 0;
	node *temp = head;
	while (temp->next->next != NULL)
	{
		if (i == index - 1)
		{
			node *lk = temp->next;
			temp->next = temp->next->next;
			free(lk);
			return;
		}
		temp = temp->next;
		i++;
	}
	if (i == index - 1)
		{
			delTail();
			return;
		}
	printf("Index exceed tail.");
}

int baka()
{
	node *lk = head;
	int i = 0;
	while (i < 3)
	{
		lk = lk->next;
		i++;
	}
	return lk->data;
}

int main()
{
	addFirst(10);
	addFirst(11);
	addFirst(12);
	addLast(99);
	addLast(5);
	add(100,1);
	display();
	printf("\n");
	del(1);
	del(6);
	display();
	printf("\n%d",baka());
 	   
    return 0;
}
