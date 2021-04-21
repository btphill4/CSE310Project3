/** 
 * Author: Brandon Phillips
 * Function: Header file for Heap.cpp which holds
 * all the methods and variables for classes ELEMENT, pELEMENT, and HEAP
*/


#ifndef Heap_h
#define Heap_h
#include <stdio.h>
#include "Graph.h"

//Of type VERTEX so it hold VERTEX elements
typedef VERTEX ELEMENT;
typedef VERTEX *pELEMENT;

/** Element class that holds keys of type integer*/
//MAY NEED TO CHANGE TO STRUCTS CAUSE XUE CODE 
/*class ELEMENT
{
    public:
    //int key;
    float key;
    int vertex; //points to the vertex V[vertex]
};*/

typedef ELEMENT *eELEMENT;


//pointer to element class to be used with an array
//typedef ELEMENT *pELEMENT;


//heap class
class HEAP
{
    //values to be set at construction
    public: 
    int capacity;
    int size;
    //pELEMENT *H;     //array of pointers to elements(vertices) <type> VERTEX
    pELEMENT* H;      //With <type> ELEMENT
     
    int heapifyCount;   //project 2 don't need

    //~~~constructors~~~~//
    //default
    HEAP()
    {
        
    }
    //for initalize(n)
    HEAP(int n);


    //methods for project 1
    HEAP* initialize(int n);
    void heapPrint(HEAP* a);

    //getter methods
    int getCapacity()
    {
	    return this->capacity;
    }
    int getSize()
    {
        //return this->size;
        return this->size;
    }
    pELEMENT* getH()
    {
        return this->H;
    } 
    
    //setters methods
    void setH(pELEMENT* sH)
    {
        H = sH;
    }

    void setCapacity(int c)
    {
        capacity = c;
    }

    void setSize(int s)
    {
        size = s;
    }

//====================================================//


    //Methods For project 2
    //required methods
    //void insert(HEAP* a, int key);
    
    void decreaseKey(HEAP* a, int index, int key);
    void minHeapify(HEAP* a, int index);
    //void HEAP::extractMin(HEAP* a, int f);
    //Not required may not need
    void buildMinHeap(HEAP* a);
    void heapSort(HEAP* a);
    pVERTEX getHeapMin(HEAP* a);

//====================================================//

    //project 3 methods
    void heapFree(HEAP *a);
    int xueDecreaseKey(HEAP *a, pVERTEX* V, int pos, float newKey);
    void MovingUp (HEAP *a, pVERTEX* V,int pos);
    void MovingDown(HEAP *a, pVERTEX* V, int pos, int flag);
    int insert(HEAP* a, pVERTEX* V, pELEMENT obj); 
    pVERTEX deleteMin(HEAP* heap, pVERTEX* V, int flag);
    pELEMENT extractMin(HEAP* heap, pVERTEX* V);
    void minHeap(HEAP* heap, pVERTEX* V, int i);
};
#endif
/*
//heap class OLD WITH typedef ELEMENT* pELEMENT
class HEAP
{
    //values to be set at construction
    public: 
    int capacity;
    int size;
    //pELEMENT *H;     //array of pointers to elements(vertices) <type> VERTEX
    eELEMENT H;      //With <type> ELEMENT
     
    int heapifyCount;   //project 2 don't need

    //~~~constructors~~~~//
    //default
    HEAP()
    {
        
    }
    //for initalize(n)
    HEAP(int n);


    //methods for project 1
    HEAP* initialize(int n);
    void heapPrint(HEAP* a);

    //getter methods
    int getCapacity()
    {
	    return this->capacity;
    }
    int getSize()
    {
        //return this->size;
        return this->size;
    }
    eELEMENT getH()
    {
        return this->H;
    } 
    
    //setters methods
    void setH(eELEMENT sH)
    {
        H = sH;
    }

    void setCapacity(int c)
    {
        capacity = c;
    }

    void setSize(int s)
    {
        size = s;
    }

//====================================================//


    //Methods For project 2
    //required methods
    
    void insert(HEAP* a, ELEMENT obj);
    //void insert(HEAP* a, int key);
    void extractMin(HEAP* a);
    void decreaseKey(HEAP* a, int index, int key);
    void minHeapify(HEAP* a, int index);

    //Not required may not need
    void buildMinHeap(HEAP* a);
    void heapSort(HEAP* a);
    ELEMENT getHeapMin(HEAP* a);

//====================================================//

    //project 3 methods
    void heapFree(HEAP *a);
    void xueDecreaseKey(HEAP *a, int pos, int newKey);
    void MovingUp (HEAP *a, int pos);

};
*/