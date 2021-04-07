/** 
 * Author: Brandon Phillips
 * Function: Header file for Heap.cpp which holds
 * all the methods and variables for classes ELEMENT, ElementT, and HEAP
*/


#ifndef heap_h
#define heap_h

/** Element class that holds keys of type integer*/
class ELEMENT
{
    public:
    int key;

};

//pointer to element class to be used with an array
typedef ELEMENT *ElementT;


//heap class
class HEAP
{
    //values to be set at construction
    public: 
    int capacity;
    int size;
    ElementT H; 
    int heapifyCount;

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
    ElementT getH()
    {
        return this->H;
    } 
    
    //setters methods
    void setH(ElementT sH)
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


};


#endif