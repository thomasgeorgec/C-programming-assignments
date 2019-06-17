#include <stdio.h>

struct binList
{
	int data;
	struct binList *next;
};

int binayconvert(struct binList *head)
{
	if (head == NULL)
	{
		return 0;
	}
	struct binList *list = head;
	int bin=0, num=0;
	int i = 0;
	do
	{
		bin = (bin * 10) + list->data;
		list = list->next;
	} while (list != NULL);

	while (bin > 0)
	{
		num += (bin % 10)*(1 << i);
		bin = bin / 10;
		i++;
	}
	return num;
}
int main()
{
	int arr[] = { 1,0,0,1,0 };
	int res = 0;
	struct binList *list = (struct binList *)malloc(sizeof(struct binList));
	struct binList *head = list;
	list->data = arr[0];
	list->next = NULL;
	for (int i = 1; i < sizeof(arr) / sizeof(int); i++)
	{
		list->next = (struct binList *)malloc(sizeof(struct binList));
		list = list->next;
		list->data = arr[i];
		list->next = NULL;
	}
	list = head;
	do
	{
		list = list->next;
	} while (list != NULL);
	
	res = binayconvert(head);

	printf("\n%d", res);

}
