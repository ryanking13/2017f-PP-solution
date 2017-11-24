#include <stdio.h>
/*void main()
{
	printf("MAKE ABCDEFGHIJ\n");
	printf("MAKE B\n");
	for (int i = 0; i < 10000000; i++)
		printf("PUSH_FRONT ABCDEFGHI %d\n", i);

	for (int i = 0; i < 10000000; i++)
		printf("PUSH_BACK B %d\n", i);

	printf("PRINT ABCDEFGHIJ\n");
	printf("PRINT_BACK ABCDEFGHIJ\n");
	printf("PRINT B\n");
	printf("PRINT_FRONT B\n");
	printf("CONCAT ABCDEFGHIJ B\n");
	printf("PRINT A\n");
	printf("PRINT_SIZE A\n");
//	system("pause");
}
*/


#include <stdlib.h>
#include <string.h>
struct list {
	int a;
	struct list *next;
};
void element_insertion(struct list* list_head, int index, int element)
{
	struct list* inserted_element;
	inserted_element = (struct list *) malloc(sizeof(struct list));
	inserted_element->a = element;
	inserted_element->next = NULL;
	struct list* tmp = list_head;
	for (int i = 0; i < index; i++)
		tmp = tmp->next;

	inserted_element->next = tmp->next;
	tmp->next = inserted_element;
	
	list_head->a++;
}
void element_delete(struct list* list_head, int index)
{
	struct list* inserted_element;
	struct list* tmp = list_head;
	for (int i = 0; i < index; i++)
		tmp = tmp->next;

	inserted_element = tmp->next->next;
	free(tmp->next);
	tmp->next = inserted_element;
	list_head->a--;
}
void print_element(struct list* list_head, int index)
{
	struct list* tmp = list_head->next;
	for (int j = 0; j < list_head->a; j++)
	{
		if (j == index) {
			printf("%d ", tmp->a);
			break;
		}
		tmp = tmp->next;
	}
	printf("\n");
}

int main()
{
	struct list list_head[1000];
	char list_name[1000][11];
	char tmp_order[100];
	char tmp_order2[100];
	int tmp_value;
	int index; 
	int total_list_num = 0;
	for (int i = 0; i < 1000; i++)
	{
		list_head[i].a = 0;
		list_head[i].next = NULL;
	}
	while (scanf("%s", tmp_order)!=EOF)
	{
		if (strcmp(tmp_order, "MAKE") == 0)
		{
			scanf("%s", tmp_order);
			strcpy(list_name[total_list_num], tmp_order);
			total_list_num++;
		}
		else if (strcmp(tmp_order, "PUSH_FRONT") == 0)
		{
			scanf("%s", tmp_order);
			scanf("%d", &tmp_value);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{
					element_insertion(&list_head[i], 0, tmp_value);
				}
			}
		}
		else if (strcmp(tmp_order, "PUSH_BACK") == 0)
		{
			scanf("%s", tmp_order);
			scanf("%d", &tmp_value);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{
					element_insertion(&list_head[i], list_head[i].a, tmp_value);
				}
			}
		}
		else  if (strcmp(tmp_order, "INSERT") == 0)
		{
			scanf("%s", tmp_order);
			scanf("%d", &index);
			scanf("%d", &tmp_value);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{
					element_insertion(&list_head[i], index, tmp_value);
				}
			}
		}
		else  if (strcmp(tmp_order, "DELETE") == 0)
		{
			scanf("%s", tmp_order);
			scanf("%d", &index);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{
					if(index < list_head[i].a)
						element_delete(&list_head[i], index);
				}
			}
		}
		else  if (strcmp(tmp_order, "CONCAT") == 0)
		{
			scanf("%s", tmp_order);
			scanf("%s", tmp_order2);
			int list_a;
			int list_b;
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
					list_a = i;
			
				if (strcmp(list_name[i], tmp_order2) == 0)
					list_b = i;
			}
			struct list* tmp; 
			
			list_head[list_a].a += list_head[list_b].a;

			for (tmp = &list_head[list_a]; tmp->next != NULL; tmp = tmp->next);
			tmp->next = list_head[list_b].next;
			
			list_head[list_b].a = 0;
			list_head[list_b].next = NULL;
			strcpy(list_name[list_b], "");

		}
		else  if (strcmp(tmp_order, "PRINT") == 0)
		{
			scanf("%s", tmp_order);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{
					struct list* tmp = list_head[i].next;
					for (int j = 0; j < list_head[i].a; j++)
					{
						printf("%d ", tmp->a);
						tmp = tmp->next;
					}
					printf("\n");
				}
			}
		}
		else if (strcmp(tmp_order, "PRINT_FRONT") == 0)
		{
			scanf("%s", tmp_order);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{
					print_element(&list_head[i], 0);
					break;
				}
			}
		}
		else if (strcmp(tmp_order, "PRINT_BACK") == 0)
		{
			scanf("%s", tmp_order);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{
					print_element(&list_head[i], list_head[i].a - 1);
					break;
				}
			}
		}
		else if (strcmp(tmp_order, "PRINT_ELEMENT") == 0)
		{
			scanf("%s", tmp_order);
			scanf("%d", &tmp_value);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{
					if(list_head[i].a > tmp_value)
					print_element(&list_head[i], tmp_value);
					break;
				}
			}
		}
		else if (strcmp(tmp_order, "PRINT_SIZE") == 0)
		{
			scanf("%s", tmp_order);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{
					printf("%d\n", list_head[i].a);
					break;
				}
			}
		}
		else if (strcmp(tmp_order, "POP_FRONT") == 0)
		{
			scanf("%s", tmp_order);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{
					if(list_head[i].a > 0){
					print_element(&list_head[i], 0);
					element_delete(&list_head[i], 0);
					}
					break;
				}
			}
		}
		else if (strcmp(tmp_order, "POP_BACK") == 0)
		{
			scanf("%s", tmp_order);
			for (int i = 0; i < total_list_num; i++)
			{
				if (strcmp(list_name[i], tmp_order) == 0)
				{	
					if(list_head[i].a > 0){
					print_element(&list_head[i], list_head[i].a - 1);
					element_delete(&list_head[i], list_head[i].a - 1);
					}
					break;
				}
			}
		}

		if (strcmp(tmp_order, "END") == 0)
			break;
	}

//	system("pause");
}

