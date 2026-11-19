#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"


//BST for car
BST_Car* CreateEmptyBST_Car() {
	BST_Car* tree = (BST_Car*)malloc(sizeof(BST_Car));
	if (tree == NULL)
	{
		printf("allocation failed! \n");
		return NULL;
	}
	tree->car_root = NULL;
	return tree;
}
int isBST_Car_empty(BST_Car* tree)
{
	if (tree->car_root == NULL)
	{
		return 1;// is empty
	}
	else
		return 0;//not empty
}
tCar* Create_Car_Leaf(Car* car)
{
	tCar* new_leaf = (tCar*)calloc(1, sizeof(tCar));
	if (new_leaf == NULL)
	{
		printf("allocation failed! \n");
		return NULL;
	}
	new_leaf->car = car;
	new_leaf->left = new_leaf->right = NULL;
	return new_leaf;
}
BST_Car* insartToBST_Car(BST_Car* tree, Car* car)//return the updated tree
{
	if ( isBST_Car_empty(tree) == 1)
	{
		tCar* new_car = Create_Car_Leaf(car);
		tree->car_root = new_car;
		return tree;
	}
	else
	{
		tCar* new_car = Create_Car_Leaf(car);
		
		//using laxograpic sort meening it compers between the licenses and see if 123......>122...... for example
		if (strcmp(tree->car_root->car->nLicense, new_car->car->nLicense) > 0)//if cmp > 0  enter the left subtree meening new_car->nLicense < root->car->nLicense
		{
			if (tree->car_root->left == NULL)//if left subtree empty put new_car in it
			{
				tree->car_root->left = new_car;
				printf("insartion sucssesfull!\n");
				
			}
			else 
			{
				insartToBST_Car(tree, new_car);// looking in the left subtree until finds an empty slot to put new_car in
				
			}
			return tree;
			
		}
		
		else if (strcmp(tree->car_root->car->nLicense, new_car->car->nLicense) < 0) //enter right subtree if cmp < 0 
		{
			if (tree->car_root->right == NULL)//if root->right empty put car in it
			{
				tree->car_root->right = new_car;
				printf("insartion sucssesfull!\n");
			}
			else
			{
				insartToBST_Car(tree, new_car);//looking in the right subtree until finds an empty slot to put new_car in
				
			}
			return tree;
		}
		else
		{
			printf("car already exists! \n");
			return;
		}
	}
}
Car* deletefromBST_Car(BST_Car* tree, char* licenseNumber)
{
	if (isBST_Car_empty(tree) == 1)
	{
		printf("the tree is empty cant delete! \n");
		return;
	}

	if (strcmp(tree->car_root->right->car->nLicense,licenseNumber) == 0)
	{
		Car* tmp = tree->car_root->right->car;
		Car* to_return;
		to_return = tmp;
		free(tree->car_root->right);
		tree->car_root->right = NULL;
		return to_return;
	}

	if (strcmp(tree->car_root->left->car->nLicense, licenseNumber) == 0)
	{
		Car* tmp = tree->car_root->left->car;
		Car* to_return;
		to_return = tmp;
		free(tree->car_root->left);
		tree->car_root->left = NULL;
		return to_return;
	}
}
void printBST_Car(tCar* root)
{
	if (root != NULL)
	{
		printBST_Car(root->left);
		printf("%s\n",root->car->nLicense);
		printBST_Car(root->right);
		
	}
}


//BST for station
BST_Station* CreateEmptyBST_Station()
{
	BST_Station* tree = (BST_Station*)malloc(sizeof(BST_Station));
	if (tree == NULL)
	{
		printf("allocation failed! \n");
		return NULL;
	}
	tree->root_station = NULL;
	return tree;
}
int isBST_Station_empty(BST_Station* tree)
{
	if (tree->root_station == NULL)
	{
		return 1;// is empty
	}
	else
		return 0;//not empty
}
Station* Create_Station_Leaf(Station* station)
{
	Station* new_leaf = (Station*)calloc(1, sizeof(Station));
	if (new_leaf == NULL)
	{
		printf("allocation failed! \n");
		return NULL;
	}
	new_leaf->left = new_leaf->right = NULL;
	return new_leaf;
}
BST_Station* insartToBST_Station(BST_Station* tree, Station* station)//return the updated tree
{
	if (isBST_Station_empty(tree) == 1)
	{
		Station* new_station = Create_Station_Leaf(station);
		tree->root_station = station;
		return tree;
	}
	else
	{
		Station* new_station = Create_Station_Leaf(station);

		//using laxograpic sort meening it compers between the licenses and see if 123......>122...... for example
		if (strcmp(tree->root_station->id,station->id) > 0)//if cmp > 0  enter the left subtree meaning new_car->nLicense < root->car->nLicense
		{
			if (tree->root_station->left == NULL)//if left subtree empty put new_car in it
			{
				tree->root_station->left = new_station;
				printf("insartion sucssesfull!\n");

			}
			else
			{
				insartToBST_Station(tree, new_station);// looking in the left subtree until finds an empty slot to put new_car in

			}
			return tree;

		}

		else if (strcmp(tree->root_station->id, new_station->id) < 0) //enter right subtree if cmp < 0 
		{
			if (tree->root_station->right == NULL)//if root->right empty put car in it
			{
				tree->root_station->right = new_station;
				printf("insartion sucssesfull!\n");
			}
			else
			{
				insartToBST_Station(tree, new_station);//looking in the right subtree until finds an empty slot to put new_car in

			}
			return tree;
		}
		else
		{
			printf("car already exists! \n");
			return;
		}
	}
}
Station* deletefromBST_Station(BST_Station* tree, char* id)
{
	if (isBST_Station_empty(tree) == 1)
	{
		printf("the tree is empty cant delete! \n");
		return;
	}

	if (strcmp(tree->root_station->right->id, id) == 0)
	{
		Station* tmp = tree->root_station->right;
		Station* to_return;
		to_return = tmp;
		free(tree->root_station->right);
		tree->root_station->right = NULL;
		return to_return;
	}

	if (strcmp(tree->root_station->left->id, id) == 0)
	{
		Station* tmp = tree->root_station->left;
		Station* to_return;
		to_return = tmp;
		free(tree->root_station->left);
		tree->root_station->left = NULL;
		return to_return;
	}
}
void printBST_Station(Station* root)
{
	if (root != NULL)
	{
		printBST_Station(root->left);
		printf("%d\n", root->id);
		printBST_Station(root->right);

	}
}


