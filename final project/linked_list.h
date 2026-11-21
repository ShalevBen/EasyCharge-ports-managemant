#pragma once 
#ifndef Linked_list_H
#define Linked_list_H
#include "Structs.h"


typedef struct PortList {

	struct Port* head;//i put struct in every field in every type of managing strcut so it will know it exists before i finish writing it
	struct Port* tail;
}PortList;//managing the list of ports

PortList* makeEmptyList();
Port* createNewPort(Port* port);
int isListEmpty(Port* list);
PortList* addtoList(Port* list,Port* port);
Port* remove_from_list(Port* list, Port* port);
void  print_list(PortList* list);


#endif //linked_list_H