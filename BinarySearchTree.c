#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	const void* key;
	const void* value;
	struct node* left;
	struct node* right;
};
 struct  tree_t{
	node* tree;
	int (*compare_doubles)(const void*, const void*);
} BinarySearchTree;

int compare_doubles(const void* a, const void* b){
	double *ptA = (double*) a; 
	double *ptB = (double*) b;
	if(*ptA>*ptB)
	{
		return 1;
	}
	else return(*ptB>*ptA);
	
}


BinarySearchTree* newBST(int comparison_fn_t(const void *, const void *)){


	BinarySearchTree* new = (BinarySearchTree*) malloc(sizeof(BinarySearchTree));
	if(!new){
		return NULL;
	}
	 new = newBST(&compare_doubles);
	 new->compare_doubles= comparison_fn_t;
	return new;


}







void freeBST(BinarySearchTree* bst, bool freeContent){
   if (bst != NULL) {
        freeBST(bst->left,freeContent);
        freeBST(bst->right,freeContent);
	
        free(bst);
    }
	
}

size_t sizeOfBST(const BinarySearchTree* bst){
 if (bst == NULL) return 0;
  return 1 + sizeOfBST(bst->left) + sizeOfBST(bst->right);
}



/* ------------------------------------------------------------------------- *
 * Inserts a new key-value pair in the provided BinarySearchTree. This
 * specific implementation of the BST must handle duplicate keys.
 *
 * PARAMETERS
 * bst          A valid pointer to a BinarySearchTree object
 * key          The key of the new element or of the element to update
 * value        The value to store
 *
 * RETURN
 * res          A boolean equal to true if the new element was successfully
 *              inserted, false otherwise
 * ------------------------------------------------------------------------- */

bool insertInBST(BinarySearchTree* bst, const void* key, const void* value){
  if ((bst) == NULL) {
        BinarySearchTree* nw = (BinarySearchTree) malloc(sizeof(struct node));
        nw->key = key;
	nw->value = value;
        nw->left = NULL;
        nw->right = NULL;
        (*bst) = nw;
    }
    else if (key < (*bst)->key && value < (*bst)->value ){
        return insert(&((*bst)->left), key) && insert(&((*bst)->left), value);}
    else{
        return insert(&((*bst)->right),key) && insert(&((*bst)->right),value);
	}
}


/* ------------------------------------------------------------------------- *
 * Return the value associated to that key, if any
 *
 * PARAMETERS
 * bst          A valid pointer to a BinarySearchTree object
 * key          The key to look for
 *
 * RETURN
 * res          One of the value corresping to that key. Or NULL if the key
 *              is not present in the BST
 * ------------------------------------------------------------------------- */

const void* searchBST(BinarySearchTree* bst, const void* key){
 if ( bst == NULL) return 0;
    if (key == bst->key) return 1;
    if (key < bst->key) return search(bst->left, key);
    else return search(bst->right, key);
}
/* ------------------------------------------------------------------------- *
 * Finds a set of elements in the provided BinarySearchTree whose the keys
 * are included in a range [key1, key2] and returns their values. The values
 * are sorted in the increasing order of the keys.
 *
 * PARAMETERS
 * bst          A valid pointer to a BinarySearchTree object
 * keyMin       Lower bound of the range (inclusive)
 * keyMax       Upper bound of the range (inclusive)
 *
 * RETURN
 * ll           A linkedList containing the element in the given range, or
 *              NULL in case of allocation error.
 *
 * NOTES
 * The linkedList must be freed but not its content
 * If no elements are in the range, the function returns an empty linked-list
 * ------------------------------------------------------------------------- */

LinkedList* getInRange(const BinarySearchTree* bst, void* keyMin, void* keyMax)
