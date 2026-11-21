#include <stdio.h>
#include "linked_list.h"

PortList* makeEmptyList()
{
	PortList* list =(PortList*) calloc(1, sizeof(PortList));
	if (list ==NULL)
	{
		printf("allocation failed!\n");
		return NULL;
	}

	list->head = list->tail = NULL;
	return list;
}
Port* createNewPort(Port* port)
{
	Port* new_node = (Port*)malloc(sizeof(Port));
	if (new_node == NULL)
	{
		printf("allocation failed! \n");
		return NULL;
	}
	new_node->num = port->num;
	new_node->portType = port->portType;
	new_node->status = port->status;
	new_node->p2car = port->p2car;
	new_node->tin = port->tin;
	new_node->next = NULL;
	return new_node;
}
int isListEmpty(PortList* list)
{
	if (list->head == NULL && list->tail == NULL)
	{
		return 1;//is empty
	}
	return 0;//not empty
}
PortList* addtoList(PortList* list, Port* port)
{
	Port* new_port = createNewPort(port);
	if (isListEmpty(list) == 1)
	{
		list->head = new_port;
		list->head->next = list->tail;
		return list;
	}
	else
	{
		//the case where the first place after the head is empty.
		if (list->head->next == NULL)
		{
			
			list->tail = new_port;
			list->tail->next = NULL;
			list->head->next = list->tail;
			return list;
		}
		
		//for the case where the null place is not diractly after head
		Port* temp = list->head;
		while (temp != NULL)
		{
			if (temp->next == NULL)
			{
				temp = new_port;
				temp->next = NULL;
				list->head = temp;
				return list;
			}
			temp = temp->next;
		}
		printf("The list is full \n");
		return list;
	}
}
Port* remove_from_list(PortList* list,Port* port)
{
	Port* to_remove = NULL;
	Port* curr = NULL;
	Port* tmp = NULL;

	//in case of a empty list
	if (isListEmpty(list) == 1)
	{
		printf("list is empty!\n");
		return	NULL;
	}

	//in case we remove the head
	if (list->head == port)
	{
		curr = list->head;//remambering the head
		list->head = list->head->next;//updating the head to point to next node to be new head.
		to_remove = curr;
		return to_remove;
	}

	//removing the end of the list
	if (list->tail == port)
	{
		tmp = list->head;
		while (tmp != NULL)
		{
			if (tmp->next == port)
			{
				to_remove = tmp->next;
				list->tail = tmp;
				return to_remove;
			}
			tmp = tmp->next;
		}
	}

	//removing a node from the middle
	curr = list->head;// save the head
	while (curr != NULL)
	{
		if (curr->next == port)
		{
			to_remove = curr->next;//catch the node to remove
			curr->next = curr->next->next;//ask ran about this and why its an issue 
			return to_remove;
		}
		curr = curr->next;
	}

}
void  print_list(PortList* list)
{
	int count = 0;
	Port* head = list->head;

	while (list->head != NULL)
	{
		count++;
		list->head = list->head->next;
	}
	list->head = head;
	Port* tmp = head;

	for (int i = 0; i < count; i++)
	{
		printf("%d", head->num);
		head = list->head->next;
	}
	head = tmp;
}





