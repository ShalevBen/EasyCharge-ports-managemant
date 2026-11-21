#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Structs.h"
#include "BST.h"
#include "Queue.h"
#include "linked_list.h"
#define ALOC_ERROR "allocation faild!\n"

void loadfiles();
int countLines(FILE* file);
Car* searchCar(int licence_num);

int main()
{
	loadfiles();

	return 0;
}


int countLines(FILE* file)
{
	int count = 0;
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		count++;
	}
	return count;
}

Car* searchCar(int licence_num,BST_Car* root_car)
{


}

void loadfiles()
{

	//cars
	FILE* file_car = fopen("Cars.txt", "r");
	if (file_car == NULL)
	{
		printf("failed to open file\n");
		exit(0);
	}


	char buffer[256];//the amount of chars in the header line
	int car_count = countLines(file_car);
	rewind(file_car);
	fgets(buffer, sizeof(buffer), file_car);

	Car* car = (Car*)malloc(sizeof(Car) * (car_count - 1));
	if (car == NULL)
	{
		printf(ALOC_ERROR);
		exit(1);
	}

	//create an dynamic array to hold all the station ids
	int* car_stationIDs = (int*)calloc((car_count - 1), sizeof(int));
	if (car_stationIDs == NULL)
	{
		printf(ALOC_ERROR);
		exit(1);
	}

	char line[1024];//storing the data we collect from a line
	int i = 0;
	//create the tree and initialize it
	BST_Car* root_car = CreateEmptyBST_Car();
	while (fgets(line, sizeof(line), file_car) != NULL)
	{
		char* token;
		token = strtok(line, ",");
		strcpy(car[i].nLicense, token);

		token = strtok(NULL, ",");//forwarding the token to the next field
		//strcmp return 0 if it finds a match, 1 otherwise.
		if (strcmp(token,"FAST") == 0)
		{
			car[i].portType = FAST;
		} 
		else if (strcmp(token, "MID") == 0)
		{
			car[i].portType = MID;
		}
		else
		{
			car[i].portType = SLOW;
		}

		token = strtok(NULL, ",");
		double TotalPayed = strtod(token, NULL);//converting to double
		car[i].TotalPayed = TotalPayed;

		token = strtok(NULL, ",");
		car_stationIDs[i] = atoi(token);

		token = strtok(NULL, ",");
		car[i].pPort = (Port*)calloc(1, sizeof(Port));
		if (car[i].pPort == NULL)
		{
			printf(ALOC_ERROR);
			exit(1);
		}
		car[i].pPort->num = atoi(token);

		token = strtok(NULL, ",");
		car[i].inQueue = atoi(token);

		// what i did here is i give the car root pointer a pointer and not a value,
		//so the car_root dosent change itself it juts change whice pointer it point to. 
		root_car->car_root = insartToBST_Car(root_car->car_root, &car[i]); 

		i++;
	}
	fclose(file_car);



	//port 
	FILE* file_port = fopen("Ports.txt", "r");
	if (file_port == NULL)
	{
		printf("failed to open file! \n");
		exit(1);
	}

	buffer[256];
	int  port_count = countLines(file_port);// counting the ports and leaving the pointer in the end of the file 
	rewind(file_port);//will return the pointer to the start of the file
	fgets(buffer, sizeof(buffer), file_port);//skips the first line

	Port* port = (Port*)malloc(sizeof(Port) * (port_count - 1));
	if (port == NULL)
	{
		printf(ALOC_ERROR);
		exit(1);
	}


	int* port_stationIDs = (int*)calloc((port_count - 1), sizeof(int));
	if (port_stationIDs == NULL)
	{
		printf(ALOC_ERROR);
		exit(1);
	}

	line[1024];//storing the data we collect from a line
	i = 0;
	PortList* port_list = makeEmptyList(); // creates a new port singly linked list

	while (fgets(line, sizeof(line), file_port) != NULL)
	{

		char* token = strtok(line, ",");
		port_stationIDs[i] = atoi(token);

		token = strtok(NULL, ",");
		port[i].num = atoi(token);

		token = strtok(NULL, ",");
		if (strcmp(token, "FAST") == 0)
		{
			port[i].portType = FAST;
		}
		else if (strcmp(token, "MID") == 0)
		{
			port[i].portType = MID;
		}
		else
		{
			port[i].portType = SLOW;
		}

		token = strtok(NULL, ",");
		port[i].status = atoi(token);

		token = strtok(NULL, ",");
		port[i].tin.Year = atoi(token);

		token = strtok(NULL, ",");
		port[i].tin.Month = atoi(token);

		token = strtok(NULL, ",");
		port[i].tin.Day = atoi(token);

		token = strtok(NULL, ",");
		port[i].tin.Hour = atoi(token);

		token = strtok(NULL, ",");
		port[i].tin.Min = atoi(token);

		token = strtok(NULL, ",");
		port[i].p2car = (Car*)malloc(sizeof(Car));
		if (port[i].p2car == NULL)
		{
			printf(ALOC_ERROR);
			exit(1);
		}
		strcpy(port[i].p2car->nLicense, token);
		port[i].p2car->inQueue = NULL;

		port_list = addtoList(port_list,&port[i]);

		i++;
	}
	fclose(file_port);


	//station
	FILE* file_station = fopen("Stations.txt", "r");
	if (file_station == NULL)
	{
		printf("failed to open file! \n");
		exit(1);
	}

	buffer[256];
	int station_count = countLines(file_station);//counts the stations

	rewind(file_station);
	fgets(buffer, sizeof(buffer), file_station);

	Station* station = (Station*)malloc(sizeof(Station) * (station_count - 1));
	if (station == NULL)
	{
		printf(ALOC_ERROR);
		exit(1);
	}

	line[1024];//storing the data we collect from a line
	i = 0;
	while (fgets(line, sizeof(line), file_station) != NULL)
	{

		char* token = strtok(line, ",");

		station[i].id = atoi(token); //takes a string and cast it into an int.

		token = strtok(NULL, ",");//moves the pointer to the name of the station
		station[i].name = (char*)malloc(strlen(token));
		if (station[i].name == NULL)
		{
			printf(ALOC_ERROR);
			exit(1);

		}
		strcpy(station[i].name, token);

		token = strtok(NULL, ",");
		station[i].nPorts = atoi(token);

		token = strtok(NULL, ",");
		double tmp_x = strtod(token, NULL);
		station[i].coordinates.x = tmp_x;

		token = strtok(NULL, ",");
		double tmp_y = strtod(token, NULL);
		station[i].coordinates.y = tmp_y;

		station[i].portsList = (PortList*)malloc(sizeof(PortList));
		if (station[i].portsList == NULL)
		{
			printf(ALOC_ERROR);
			exit(1);
		}
		station[i].portsList = makeEmptyList();//creates a list and insart it

		for (int p = 0; p < port_count - 1; p++)
		{
			for (int s = 0; s < station_count - 1; s++)
			{
				if (station[s].id == port_stationIDs[p])//add  the port if the station id is matched
				{
					addtoList(station[s].portsList, port);
				}
			}
		}

		station[i].nCars = 0;
		station[i].carQueue = makeEmptyQueue();//creates a q and insart it
		for (int c = 0; c < car_count; c++)
		{
			for (int s = 0; s < station_count; s++)
			{
				inQueue(station[i].carQueue, &car[c]);
			}
		}


	}

	//creating a BST
	BST_Station* root_station = CreateEmptyBST_Station();
	//add to the tree the stations
	insartToBST_Station(root_station, &station[i]);

	i++;
	//you should close thsese only after you shut down the system.
	/*fclose(file_station);
	free(car_stationIDs);
	free(port_stationIDs);*/
}

