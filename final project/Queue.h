#pragma once
#ifndef Queue
#define Queue
#include "Structs.h"


typedef struct carNode {

	Car* car;
	struct carNode* next;

}carNode;//a node in the q

typedef struct qCar {
	carNode* front;
	carNode* rear;

}qCar;//managing the Q

qCar* makeEmptyQueue();//creating an empty queue
int isQueueEmpty(const qCar* queue);//chacking if the queue is empty. 0 if not. 1 if is
qCar* inQueue(qCar* queue, Car* car);// got a car into the queue
carNode* createNode(Car* car);
Car* deQueue(qCar* queue);//return the car that got out of queue
void print_Queue(qCar* queue); // printing the queue

#endif //Queue