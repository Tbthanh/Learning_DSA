#include <stdio.h>
#include <stdlib.h>

//Khai bao cac cau truc du lieu (a)
typedef struct model
{
	long mComputer;
	int bQuantity;
	int sQuantity;
	float bPrice;
	float sPrice;
	double profit;
} model;

typedef struct node
{
	model m;
	struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

//Ham khoi tao mot danh sach rong de luu tru cac model may tinh (b)
model in_m()
{
	model m;
	printf("Nhap du lieu theo thu tu sau: mComp, bQuantity, \nsQuantity, bPrice, sPrice, profit:\n");
	scanf("%ld", &m.mComputer);
	scanf("%d", &m.bQuantity);
	scanf("%d", &m.sQuantity);
	scanf("%f", &m.bPrice);
	scanf("%f", &m.sPrice);
	scanf("%lf", &m.profit);
	printf("\n");
	return m;
}

node* creNode(model m)
{
	node *lk = malloc(sizeof(node));
	lk->m = m;
	lk->next = NULL;
	return lk;
}

//ham them vao dau danh sach
void addHead(model m)
{
	node *lk = creNode(m);
	if(head == NULL)
	{
		head = lk;
		tail = lk;
		return;
	}
	lk->next = head;
	head = lk;
}

//ham them vao cuoi danh sach (c)
void addTail(model m)
{
	if(tail == NULL)
	{
		addHead(m);
		return;
	}
	node *lk = creNode(m);
	tail->next = lk;
	tail = lk;
}

void del_head()
{
	node *lk = head;
	head = head->next;
	free(lk);
}

void del_tail()
{
	if(tail == NULL)
	{
		printf("Nahh.");
		return;
	}
	
	if(tail == head)
	{
		del_head();
		return;
	}
	
	
}

//xoa mot model co ma so model cho truoc
void del_model(long mComputer)
{
	node *lk = head;
	while (lk->next->next != NULL)
	{
		if(lk->next->m.mComputer == mComputer)
		{
			node *temp = lk->next;
			lk->next = temp->next;
			free(temp);
			printf("Deleted said node.");
			return;
		}
		lk = lk->next;
	}
}

//Ham tinh tien lai cua tat ca cac model (e)
double profit_sum()
{
	double sum_of_profit = 0;
	node *lk = head;
	while(lk->next != NULL)
	{
		sum_of_profit += lk->m.profit;
		lk = lk->next;
	}
	sum_of_profit += tail->m.profit;
	return sum_of_profit;
}

//

int main()
{
	//for testing some dumb dumb dumb stuf
	addHead(in_m());
	printf("\n%lf\n",profit_sum());
	printf("__________________");
	
	addHead(in_m());
	addHead(in_m());
	addTail(in_m());
	printf("\n%lf\n",profit_sum());
	return 0;
}

