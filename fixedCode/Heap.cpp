/** 
 * Author: Brandon Phillips
 * Function: This hold the heap class methods
 * from Heap.h to be used in the main
*/


#include "Heap.h"
#include "Graph.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

//Need for project 3
//pVERTEX* V;



//constructor
HEAP::HEAP(int n)
{
	capacity = n;
	size = 0; //correct I think
    //size = 12;	//wrong I think

    //element pointer array
    pVERTEX* arr = new pVERTEX[n + 1];  //dynamically allocated

    H = arr;

	
}

//initialize, return HEAP* ptr
HEAP*	HEAP::initialize(int n)
{
	HEAP* heap = new HEAP(n);   //will be dynamically allocated in the constuctor

    //testing purposes
   /* //cout << "INSIDE init: capcity=" << heap->getCapacity() << ", size=" 
    << heap->getSize() << endl; */

    return heap;
}

//print the objects of the heap
void HEAP::heapPrint(HEAP* a)
{
	//print the capity and size
    //cout << "capacity=" << a->capacity << ", size=" 
    //cout << a->size << endl;
	cout << "Current Heap: ";
    //print the HEAP from size 1
    pELEMENT* arr = a->H;
    for(int i = 1; i <= a->size; i++)
    {
        //if key is == 0, break the for loop
        if(arr[i]->key == 0)
        {
            break;
        }

        //if we are at the end of the arr, don't print a comma
        if(i == a->getSize())
        {
            cout << arr[i]->key << endl;
        }

        //print everything and put a commma after
        else
        {
        cout << arr[i]->key << ", ";
        }
    }
    //cout << endl; */
} //end heapPrint()
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


//returns the root element(doesn't remove element)
pVERTEX HEAP::getHeapMin(HEAP * a)
{
	return a->H[1];
}

//==================END Project 2=========================//


/******************* Project 3 methods*************************/

//inserts an object of type ELEMENT pointed to by 
//element into the heap pointed to by heap
int HEAP::insert(HEAP* heap, pVERTEX* V, pELEMENT obj)
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
	//V[heap->H[heap->size]->vertex]->pos = heap->size;

	MovingUp(heap, V, heap->size);
	return 1;

}

void heapFree(HEAP *heap) //still probably wrong
{
	free(heap->H);
	free(heap);	//Possibly should be it idk if not for loop sets values to null
	
}

//decrease the key value using position
//int	HEAP::xueDecreaseKey(HEAP* heap, pVERTEX* V, int pos, int newKey)
int	HEAP::xueDecreaseKey(HEAP* heap, pVERTEX* V, int pos, float newKey)
{
	//if the position is the min OR is bigger than the heap size OR the new key is equal to old key
	//cout << "(pos > heap->size )" << pos << "<" << heap->size << endl;
	if(pos < 1 || pos > heap->size || newKey >= heap->H[pos]->key)
	{	
		//if statements for validity check
		/*cout << "uhhhh" << endl;
		if(pos < 1)
		{
			cout << "(pos < 1)" << endl;
		}
		if(pos > heap->size )
		{
			cout << "(pos > heap->size )" << pos << "<" << heap->size << endl;
		}
		if(newKey >= heap->H[pos]->key)
		{
			cout << "(newKey > heap->H[pos]->key)" << endl;
		}*/
		//printf("Error: invalid call to DecreaseKey\n");
		//return 0;
		
	}
	//else set key = newKey
	else
	{
	//cout << "XueDecreaseKey Success" << endl;
	heap->H[pos]->key = newKey;
	MovingUp(heap, V, pos);
	//eturn 1;	//this might need to return an int probably like a bool maybe?
	}
	return 1;
}

//Moving up moves the element to its new position and sets it parents values
void HEAP::MovingUp (HEAP *heap, pVERTEX* V, int pos)
{
	//cout << "Moving up segfault" << endl;

	//declare variables
	int parent;
	pELEMENT temp; //might need to change 

	parent = pos/2; 
	//cout << endl << "do I reach this tho" << endl;
	/*
	Check if int pos > 1 {1,2,3...} else out of bounds
	and that the new elements new position has a higher key value(moving UP)
	and sets the position and new key value accordingly
	*/
	//cout << "CURRENT POSITION: " << pos << endl;
	//cout <<  " heap->H[pos]->key: " << heap->H[pos]->key << " < heap->H[parent]->key: " << heap->H[parent]->key << endl;
	if(pos > 1 && heap->H[pos]->key < heap->H[parent]->key)
	{	
		//cout << "ENTER MovingUp" << endl;
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


//elementSwap 
void eSwap(float x,  float y) 
{ 
	float temp = x; 
	x = y; 
	y = temp; 
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
void HEAP::MovingDown(HEAP* a, pVERTEX* V, int pos, int flag)
{
	int left = gLeft(pos);
	int right = gRight(pos);
	int root = pos;
	
	//pointer to move keys
	pELEMENT keyPtr = (VERTEX *) malloc(size+1);
	
	keyPtr->key = a->H[root]->key;	//THIS MAY BE WRONG

	//check statements
	if(left >= a->size && a->H[left]->key <= a->H[pos]->key)
	{
		
		a->H[root] = a->H[left];
		//root = left;
	}
	else
	{
		a->H[root] = a->H[pos];
		//root = i;
	}
	if(right <= a->size && a->H[right]->key <= a->H[pos]->key)
	{
		a->H[root] = a->H[right];
		//root = right;
	}
	if(root != pos)
	{
		eSwap(a->H[root]->key, a->H[pos]->key);
		MovingDown(a, V, root, flag);
	}

} //END minHeapify()




void HEAP::minHeap(HEAP* heap, pVERTEX* V, int index)
{
	int smallest = index;
	

	int left = gLeft(index);
	int right = gRight(index);
	//int root = index;

	//if(heap->size != 0)
	//{
		//cout << "HEAP SIZE IS ONE DUMBASS" << endl;
	
		if(left <= heap->size && heap->H[left]->key <= heap->H[index]->key)
		{
			//heap->H[smallest] = heap->H[left]; <-
			smallest = left;
		}
		else
		{	
			//heap->H[smallest] = heap->H[index];
			smallest = index;
		}
		if(right <= heap->size && heap->H[right]->key < heap->H[smallest]->key)
		{
			//heap->H[smallest] = heap->H[right]; 
			smallest = right;
		}
		if(smallest != index)
		{
			/*pELEMENT element = heap->H[smallest];
			heap->H[smallest] = heap->H[index];
			heap->H[index] = element;

			element = heap->H[smallest];
			heap->H[smallest] = heap->H[index];
			heap->H[index] = element;*/

			std::swap(heap->H[index], heap->H[smallest]);
			std::swap(V[heap->H[index]->vertex]->pos, V[heap->H[smallest]->vertex]->pos);
			std::swap(heap->H[smallest]->key, heap->H[index]->key);
			minHeap(heap, V, smallest);
		}
	//}
}

pELEMENT HEAP::extractMin(HEAP* heap, pVERTEX* V)
{
	pELEMENT min, last;

	if(heap->size <= 0)
	{
		//printf("Error in DeleteMin: heap empty\n");
		return NULL;
	}
		//cout << endl << "BEFORE EXTRACT MIN HEAP SIZE: " << heap->size << endl;

		min = heap->H[1];
		last = heap->H[heap->size--];
		heap->H[1] = last;

		V[heap->H[1]->vertex]->pos = 1;
		heap->minHeap(heap, V, min->vertex);	
		V[min->vertex]->pos = 0;
		//cout << "After EXTRACT MIN HEAP SIZE: " << heap->size << endl << endl;
		return min;
}
