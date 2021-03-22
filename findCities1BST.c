/* ========================================================================= *
 * findCities: arbre implementation
 * ========================================================================= */

#include "City.h"
#include "findCities1BST.h"
#include "LinkedList.h"

int compare_doubles(const void* a, const void* b){
	double *ptA = (double*) a; 
	double *ptB = (double*) b;
	if(*ptA>*ptB)
	{
		return 1;
	}
	else return(*ptB>*ptA);
	
}


	

LinkedList* findCities(LinkedList* cities, double latitudeMin, double latitudeMax, double longitudeMin, double longitudeMax){
	
	BinarySearchTree *villesBTS = newBST(compare_doubles);
	if (!villesBTS)
	{
		
		return NULL;
	}
	
	//remplissage d'arbre
	LLNode* lcurr = cities->head;
	int i=1;
	while(lcurr != NULL)
	{
		City* city = (const City*)lcurr->value;
		bool error = false;
		if(error)
		{
			
			freeBST(villesBTS, false);
			return NULL;
		}
		lcurr = cities->last;
		i++;
	}
	printf("l'arbre est fait");
	
	//filtre selon la latitude
	LinkedList *filtreLat = getInRange(villesBTS, &latitudeMin, &latitudeMax);
	if(!filtreLat)
	{
		
		freeBST(villesBTS, false);
		return NULL;
	}
	
	
	return filtre;
}
