#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


qCar* makeEmptyQueue()// creates am empty Q.
{
	qCar* queue = (qCar*)malloc(sizeof(qCar));
	if (queue == NULL)
	{
		printf("allocation error");
		exit(1);

	}
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}
int isQueueEmpty( const qCar* queue)
{
	if (queue == NULL)
	{
		return 1;
	}
	if (queue->front == NULL)
	{
		return 1;
	}
	else
		return 0;
		
}
carNode* createNode(Car* car) {
	carNode* newNode = (carNode*)calloc(1, sizeof(carNode)); //creates a node for the queue
	if (newNode == NULL)
	{
		printf("allocation failed\n");
		return NULL;
	}
	newNode->car = car;
	newNode->next = NULL;
	return newNode;
}
qCar* inQueue(qCar* queue,Car* car)
{
	carNode* new_car = createNode(car);//creates a new node
	

	if (isQueueEmpty(queue)==1)// enters the car first in line in case q is empty
	{
		queue->front = new_car;
		return queue;
	}
	else
	{
		queue->rear = new_car;
		queue->front->next = queue->rear;
		return queue;
	}
}
Car* deQueue(qCar* queue)
{
	if (isQueueEmpty(queue) == 1)
	{
		printf("Queue is empty cant deQueue an empty Queue!. \n");
		return NULL;
	}

	Car* tmp_car = queue->front->car;// saving the obj i want to return.
	Car* tmp_next = queue->front->next;// saving the obj next so i can update the queue after deleting the front node

	free(queue->front);//deleting the front node
	queue->front = tmp_next;//updating the queue

	//chacking if the queue is empthy after deletion
	if (isQueueEmpty(queue))
	{
		printf("Queue is empty! \n");
		return NULL;
	}
	return tmp_car;

}
void print_Queue(qCar* queue)
{
	int count = 0;
	carNode* tmp = queue->front;//to not damage the q it self

	while (tmp != NULL)//while there is a car in Q
	{
		printf("car number %d in Q.\n number license: %s\n", ++count, tmp->car->nLicense);
		tmp = tmp->next;
	}
}
