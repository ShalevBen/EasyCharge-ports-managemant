#pragma once
#ifndef BST_ADT
#define BST_ADT 
#include "Structs.h"

typedef struct Station Station;

typedef struct tCar {

	Car* car;
	struct tCar* left;
	struct tCar* right;
} tCar;

typedef struct BST_Car {

	  tCar* car_root;

}BST_Car;// managing strcture for BST car

typedef struct BST_Station {

	Station* root_station;

}BST_Station;// managing strcture for BST car


//bst for car
BST_Car* CreateEmptyBST_Car();
int isBST_Car_empty(tCar* tree);
tCar* Create_Car_Leaf(Car* car);
tCar* insartToBST_Car(tCar* tree,Car* car);
Car* deletefromBST_Car(tCar* tree,char* licenseNumber);
void printBST_Car(tCar* root);


//BST station
BST_Station* CreateEmptyBST_Station();
int isBST_Station_empty(BST_Station* tree);
Station* Create_Station_Leaf(Station* station);
BST_Station* insartToBST_Station(BST_Station* tree, Station* station);
Station* deletefromBST_Station(BST_Station* tree, char* id);
void printBST_Station(Station* root);

	
	








#endif //BST