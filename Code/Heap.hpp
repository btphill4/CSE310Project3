/** 
 * Author: Brandon Phillips
 * Function: Header file for Heap.cpp which holds
 * all the methods and variables for classes ELEMENT, pELEMENT, and HEAP
*/


#ifndef heap_hpp
#define heap_hpp

/** Element class that holds keys of type integer*/
class ELEMENT
{
    public:
    //int key;
    float key;
    int vertex; //points to the vertex V[vertex]
};

//typedef ELEMENT *pELEMENT;


//pointer to element class to be used with an array
typedef ELEMENT *pELEMENT;


//heap class
class HEAP
{
    //values to be set at construction
    public: 
    int capacity;
    int size;
    pELEMENT H;
     
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
    pELEMENT getH()
    {
        return this->H;
    } 
    
    //setters methods
    void setH(pELEMENT sH)
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
    
    void insert(HEAP* a, int key);
    void extractMin(HEAP* a);
    void decreaseKey(HEAP* a, int index, int key);
    void minHeapify(HEAP* a, int index);

    //Not required may not need
    void buildMinHeap(HEAP* a);
    void heapSort(HEAP* a);
    ELEMENT getHeapMin(HEAP* a);

//====================================================//

    //project 3 methods
    int xueDecreaseKey(HEAP *a, int pos, int newKey);


};


#endif