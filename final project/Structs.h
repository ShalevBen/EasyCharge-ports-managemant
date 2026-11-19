#pragma once
#ifndef Structs_H
#define Structs_H //means this file is the header file for all the structs ill use 
#include <stdio.h>
#include <stdlib.h>

 
//forward declarations so i can use structs with no "is undefined" error
typedef struct Station Station;
typedef struct qCar qCar;
typedef struct Port Port;
typedef struct Car Car;

typedef struct Date {
	int Year;
	int Month;
	int Day;
	int Hour;
	int Min;
}Date;

enum portType { FAST,MID,SLOW };

typedef struct Car {
	char nLicense[9];
	enum portType portType;
	double TotalPayed;
	Port* pPort;
	int inQueue;
}Car;

typedef struct Port {
	int num;
	enum portType portType;
	int status;
	Car* p2car;
	Date tin;
	Port* next;

}Port;
  
typedef struct cord {
	double x;
	double y;
}cord;

typedef struct Station{

	int id;
	char* name; 
	int	nPorts;
	struct cord coordinates;
	struct PortList* portsList;
	int nCars;
	struct qCar* carQueue;
	Station* right;
	Station* left;

}Station;
#endif // Structs_H