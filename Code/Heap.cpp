/** 
 * Author: Brandon Phillips
 * Function: This hold the heap class methods
 * from Heap.h to be used in the main
*/


#include "Heap.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

//Need for project 3
pVERTEX* V;



//constructor
HEAP::HEAP(int n)
{
	capacity = n;
	size = 0; //correct I think
    //size = 12;	//wrong I think

    //element pointer array
    pELEMENT* arr = new pVERTEX[n + 1];  //dynamically allocated

    H = arr;

	
}

//initialize, return HEAP* ptr
HEAP*	HEAP::initialize(int n)
{
	HEAP* heap = new HEAP(n);   //will be dynamically allocated in the constuctor

    //testing purposes
   /* cout << "INSIDE init: capcity=" << heap->getCapacity() << ", size=" 
    << heap->getSize() << endl; */

    return heap;
}
/*
//print the objects of the heap
void HEAP::heapPrint(HEAP* a)
{
	//print the capity and size
    cout << "capacity=" << a->capacity << ", size=" 
    << a->size << endl;
	*/
    //print the HEAP from size 1
   /* pVERTEX arr = a->getH();
    for(int i = 1; i <= a->size; i++)
    {
        //if key is == 0, break the for loop
        if(arr[i].key == 0)
        {
            break;
        }

        //if we are at the end of the arr, don't print a comma
        if(i == a->getSize())
        {
            cout << arr[i].key << endl;
        }

        //print everything and put a commma after
        else
        {
        cout << arr[i].key << ", ";
        }
    }
    //cout << endl; */
//} //end heapPrint()
//==================END Project 1=========================//

//=================Project 2 Methods=================//

//to swap the KEYS in the array
//integer Swap
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

//elementSwap 
void eSwap(pELEMENT *x, pELEMENT *y) 
{ 
	pELEMENT temp = *x; 
	*x = *y; 
	*y = temp; 
} 


//Return Node value (NOT IN HEAP.H)
int gParent(int i)
{
	return i/2;
}
int gLeft(int i)
{
	return 2*i;
}
int gRight(int i)
{
	return ((2 * i) + 1);
}

//builds a minHeap
/*
void HEAP::buildMinHeap(HEAP* a)//buildHeap(pointer to array heap?)
{ */
	//a->getSize() == a->getCapacity();
	/*for(int i = (a->getCapacity()); i <= 1; i++)
	{
		//minHeapify(a, i);		//minHeapBroken
		counter++;
		a->heapifyCount++;
	} */
	/*
	for(int i = a->size/2; i >= 1; i--)
	{
		//accessing elements
		//a->H[i].key;
		

		a->minHeapify(a, i);	//this is the call to minheapify recursively
		a->heapifyCount++;
	} 
	
}*/ //end buildMinHeap()
//builds minHeap
 /* 
void HEAP::minHeapify(HEAP * a, int i)
{
	//pELEMENT arr = a->getH();
	//int l = 2*i + 1;
	//int r = 2*i + 2;

	int left = gLeft(i);
	int right = gRight(i);
	int root = i;
	*/
	/************************************************************************/
	//ELEMENT *keyPtr = new ELEMENT(); //this may be wrong
	//VERTEX *keyPtr = new VERTEX();
	//pVERTEX keyptr = (pNODE *) calloc(n+1, sizeof(pNODE));
	/***********************************************************************/
	/*
	keyPtr->key = a->H[i]->key;	//THIS MAY BE WRONG
	//Logic should be right but the pointer issue
	if(left >= a->getSize() && a->H[left]->key <= a->H[i]->key)
	{
		a->H[root] = a->H[left];
		//root = left;
	}
	else
	{
		a->H[root] = a->H[i];
		//root = i;
	}

	if(right <= a->getSize() && a->H[right]->key <= a->H[i]->key)
	{
		a->H[root] = a->H[right];
		//root = right;
	}
	if(root != i)
	{
		swap(a->H[root]->key, a->H[i]->key);
		minHeapify(a, root);
	}
	
}*/ //END minHeapify()

/*
//sorts the heap(min) (I think uneeded but ye)
void HEAP::heapSort(HEAP* a)
{
	buildMinHeap(a);
	for(int i = a->getCapacity(); i <= 2; i++)
	{
		swap(a->H[1], a->H[i]);
		a->size--;

	}
} //end of heapSort
*/
//returns the root element(doesn't remove element)
pELEMENT HEAP::getHeapMin(HEAP * a)
{
	return a->H[1];
}


//deletes the minimum element from the 
//heap pointed to by heapand prints them
/*
void HEAP::extractMin(HEAP* a, pVERTEX* V, int f)	//SHOULDN'T BE VOID
{	
	//will be in main
	if(a->getSize() < 1)
	{
		cout << "heap is empty\n";
	}
	*/

	//print deleted key
	//ELEMENT *keyPtr = new ELEMENT();
	//keyPtr->key = a->H[1]->key;
	//a->H[1]->key = *key;
	/*
	cout << "Deleted key: " << a->H[1]->key << endl;

	int min;
	min = a->H[0]->key;
	a->H[0] = a->H[a->size];
	a->size = a->size - 1;
	minHeapify(a,0);

	//return a->H; 
	*/

    /* 
    if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	// Store the minimum value, and remove it from heap 
	int root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root;
    */

   //removes the element, size--
  // a->size--;
//} end extractMin
/*
//right method but pointers are rough
//decreases the key of heap->H[index] to value
void decreaseKey(HEAP* a, int i, int value)
{ 	//main call: mainHeap->decreaseKey(mainHeap, n, f);
	
	
	if (value > a->H[i-1]->key)
	{
		cout << "key is larger than current key";
	}
	a->H[i]->key = value;
	while (i > 1 && a->H[gParent(i)]->key > a->H[i]->key)
	{
		swap(a->H[i]->key, a->H[gParent(i)]->key);
		i = gParent(i);
	}
	*/
	/*
	Xue Slides
	if key < a[i]
	{
		cout << "Error";
	}
	else
	a[i] = key;
		while(i > 1 and a[getParent(i) < a[i]])
		{
			swap(a[i], a[getParent(i)]);
			i = getParent(i);
		}
	 */
//} end decreaseKey()

/******************* End Project 2 *************************/


/******************* Project 3 methods*************************/

//inserts an object of type ELEMENT pointed to by 
//element into the heap pointed to by heap
int HEAP::insert(HEAP* heap, pELEMENT obj)
{
	if(heap->size >= heap->capacity)
	{
		printf("Error in HeapInsert: Heap full...\n");
		return 1;
	}
	heap->size++;
	heap->H[heap->size] = obj; 
	heap->H[heap->size]->pos = heap->size;
	//another version
	//V[heap->H[heap->size].vertex].pos = heap->size;

	MovingUp(heap, V, heap->size);
	return 0;

   //added element, size++ ADD TO MAIN MAYBE
   /*NOT really sure what this is tbh
	Xue Slides
	heap-size[a]++; //a->size++;
	i = heap-size[a]; //i = a->size;
	a[i] = (negative inifity);
	heapdecreasekey(A,i,key(OBJ))
   */
}

void heapFree(HEAP *heap) //still probably wrong
{
	free(heap);	//Possibly should be it idk if not for loop sets values to null
	free(heap->H);
	

}

//decrease the key value using position
int	HEAP::xueDecreaseKey(HEAP* heap, int pos, int newKey)
{
	//if the position is the min OR is bigger than the heap size OR the new key is equal to old key
	if(pos<1 || pos > heap->size || newKey >= heap->H[pos]->key)
	{
		printf("Error: invalid call to DecreaseKey\n");
		return 1;
		
	}
	//else key = newKey
	else
	{
	heap->H[pos]->key = newKey;
	MovingUp(heap, V, pos);
	return 0;	//this might need to return an int probably like a bool maybe?
	}

}

//Moving up moves the element to its new position and sets it parents values
void HEAP::MovingUp (HEAP *heap, pVERTEX* V, int pos)
{
	//declare variables
	int parent;
	pELEMENT temp; //might need to change 

	parent = pos/2; 

	/*
	Check if int pos > 1 {1,2,3...} else out of bounds
	and that the new elements new position has a higher key value(moving UP)
	and sets the position and new key value accordingly
	*/
	if(pos>1 && heap->H[pos]->key < heap->H[parent]->key)
	{	
		//temporary variable to hold current position integer
		temp = heap->H[pos];

		//sets the current position to the parents positon(moves the element)
		heap->H[pos] = heap->H[parent];

		//sets the parent position to the temp value of the old position for current node
		heap->H[parent] = temp;

		//================================Might need to change these=============
		//go to vertex array and update the pos there too
		V[heap->H[pos]->vertex]->pos = pos;	//current vertex position is updated in vertex array
		V[heap->H[parent]->vertex]->pos = parent; //the parents position gets updated in the vertex array
		//heap->H[pos]->vertex->pos = pos;
		//heap->H[parent]->vertex->pos = parent; 
		//=====================================================

		//call to method if successful
		MovingUp(heap, V, parent); 
	}

}

void HEAP::MovingDown(HEAP *heap, pVERTEX* V, int pos, int flag)
{
	//like minHeapify swapping the parents until the order is restored

}

pELEMENT HEAP::deleteMin(HEAP* heap, pVERTEX* V, int flag)
{
	pELEMENT min, last;	//might be pVERTEX or pELEMENT

	if(heap->size <= 0)
	{
		printf("Error in DeleteMin: heap empty\n");
		return NULL;
	}
	else
	{
	min = heap->H[1];
	last = heap->H[heap->size--]; 
	heap->H[1] = last;
	V[heap->H[1]->vertex]->pos = 1;
	MovingDown(heap, V, 1, flag);
	V[min->vertex]->pos = 0;

	return min;
	}
}

