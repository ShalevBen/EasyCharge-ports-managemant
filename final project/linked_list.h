#pragma once 
#ifndef Linked_list_H
#define Linked_list_H
#include "Structs.h"


typedef struct PortList {

	struct Port* head;//i put struct in every field in every type of managing strcut so it will know it exists before i finish writing it
	struct Port* tail;
}PortList;//managind the list of ports

PortList* makeEmptyList();
Port* createNewPort(Port* port);
Port* addtoList(PortList* list,Port* port);
Port* remove_from_list(PortList* list, Port* port);
void  print_list(PortList* list);


#endif //linked_list_H