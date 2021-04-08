/**
 * Brandon Phillips
 * This file includes the main function that ties the 
 * files together and takes command input from the user
 * 
 */
#include "Util.h"
#include "Heap.h"
#include "Graph.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> //string class
//#include <math.h>
//#include <iostream>
//#include <fstream>
using namespace std;

/**
./dijkstra <graph> <direction>

Text File Format:
int n =
int m = 
each line represents an edge 
u = source vertex node
v = destination vertex node
w(u,v) = weight of u and v 

1st line: n m
2nd line: u v w(u,v)

//after reading n from the txt file use A = (pNode *) calloc(n+1, sizeof(pNode));
 */

//From Xue video
VERTEX *V;

int main(int argc, char *argv[])
{
    FILE *ifile;

    pNODE *A;
    pNODE node;

    char word[256];
    char word2[256];
    int n, m, directed_graph, i;
    int s, s_new, t, t_new, source, source_new, destination, destination_new;
    int u, v, edge_id, flag, flag_new;

}














/*
int main(int argc, char** args) //int argc, char** args
{
    //used to get direction from commandline
    string direction;
    for(int i = 0; i <argc; i++) {
        printf("%d: %s\n", i, args[i]);
    } 
    if(strcmp(args[2], "insertion") ==0 )
    {
        direction = "directed";              //set sorting string to value used in left shift
    }
    else if (strcmp(args[2], "quick") ==0 )
    {
       direction = "undirected";               //set sorting string to value used in left shift
    }
    else
    {
        return 1;                  //else returns an error
    }
*/
    /**
    From Xue Slides

    //allocate array for adjacency lists
    A = (pNode *) calloc(n+1, sizeof(pNODE));

    for(i = 1; i <= m; i++)
    {
        //reading a file line by line
        //&u starting vertex &v ending vertex &w weight
        fscan(ifile, "%d%d%d%f", &junk, &u, &v, &w);    //&junk is edge number don't need but need to read it &u starting vertex &v ending vertex &w weight
        //printf("u=%d, v=%d, w=%f\n", u, v, w);        //checking if reading correctly


        //directed graphs
        if(direction == "directed") //I added
        {
        //add a node and set values
        node = (pNODE) malloc(sizeof(NODE));
        node->u = u; node-> v = v; node->w = w; node->next = A[u];
        A[u] = node;
        }

        if(direction == "undirected") //I added
        {
        //BGN for undirected graphs...
        //node = (pNODE) malloc(sizeof(NODE));
        //node->u = v; node-> v = u; node->w = w; node->next = A[v];
        //A[v] = node;
        //end undirected graphs
        }
    }  

    //check for adjacency lists
    for(i = 1; i <= n; i++)
    {
        printf("Node %d:\n", i);
        node = A[i];
        while(node)
        {
            printf(" %d %d %d\n", node->u, node->v, node->w);
        }
    }


    */
/*   
   //Files for reading and writing
    std::ifstream ifile("input.txt");
    std::ifstream jfile("HEAPinput.txt");
    std::ifstream input("HEAPinput.txt");

    //heap initialize check for while()
    bool initalized = false;

    // variables for the parser....
    std::string temp2;
    //char *temp;
    HEAP* mainHeap;
    char c;
    int w;
    //int i, v;
    int n, f;

    

    //command line input loop
    while(1)
    {
        c = nextCommand(&n, &f);
        switch (c) 
        {
            //S input, stops the while loop
            case 's':
            case 'S': 
                //printf("COMMAND: %c\n", c); 
                exit(0);
            
            //C input: Creates a heap object and sets initalized to true
            case 'c':
            case 'C': 
                //printf("COMMAND: %c %d\n", c, n);
                mainHeap = mainHeap->initialize(n);
                initalized = true;
                break;
            
            //R input: reads from a heap from a file and adds it to the heap object
            case 'r':
            case 'R': 
                //printf("COMMAND: %c %d\n", c, f);
                
                //initalize check
                if(!initalized)
                {
                    cout << "Error: heap overflow\n";
                    break;
                }
                
                //set input
                input >> n;

                //if input cannot be opened
                if (!input)
                {
                   printf("Error: cannot open file for reading\n");
                   break;
                }

                //null and size check
                if(mainHeap == NULL || mainHeap->capacity < n)
                {
                      std::cout << "Error: heap overflow\n";
                      break;
                }

                //write to the heap
                //mainHeap->setSize(n);
                for(int i = 1; i <= n; i++) //changed n from mainHeap->getSize()
                {
                    input >> w;
                    ELEMENT *keyPtr = new ELEMENT();
                    keyPtr->key = w;
                    //std::cout << w << "\n";                   //Testing purposes
                    mainHeap->H[i] = *keyPtr;
                    //std::cout << mainHeap->H[i].key << "\n";  //Testing purposes
                    
                    //Call to build heap THIS IS BROKEN THIS SORTS THE HEAP
                    mainHeap->buildMinHeap(mainHeap);   

                    //increments the heapSize with each added element
                    mainHeap->size++;
                    //cout << endl << mainHeap->size;
                }
                //if f = 1, print number of Heapify Calls
                if(f == 1)
                {
                    cout << "Number of Heapify calls: " << mainHeap->heapifyCount << endl;
                    break;
                    //calls to r
                }
                break;

            //print command
            case 'p':
            case 'P':
                //printf("COMMAND: %c\n", c);

                //initalize check
                if(!initalized)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }

                if(mainHeap == NULL)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }
                //size check */
                /*if(mainHeap->size == 0)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }*/
                //print function
/*                mainHeap->heapPrint(mainHeap);
                break;

            //W: input, writes the array and commands to a file
            case 'w':
            case 'W':  
                //printf("COMMAND: %c\n", c);

                //initalize check
                if(!initalized)
                {
                     printf("Error: cannot write\n");

                    break;
                }

                //if file cannot be opened
                //jfile >> temp2;
                if(jfile.fail())
                {
                     printf("Error: cannot open file for writing\n");
                     break;
                }

                //size check
                if(mainHeap->size == 0)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }

                //else write
                else
                {
                    printf("Error: cannot open file for writing\n");
                    break;
                }
            //end project 1 stuff

//========================================================================//

            //PROJECT 2 STUFF
            //D, deletes the minimum element and writes it to terminal
            case 'd':
            case 'D':
                //printf("COMMAND: %c\n", c);

                //initalize check
                if(!initalized)
                {
                    printf("Error: heap is NULL or empty\n");
                    break;
                }
                //heap is null or size is 0 
                //THIS BREAKS CAUSE SIZE ISSUES
                if (mainHeap->size == 0)
                {
                    printf("Error: heap is NULL or empty\n");
                    break;
                }

                //else does extractMin(mainHEap)
                else
                {
                    //wrong i think
                    mainHeap->extractMin(mainHeap);
                    break;
                }
                //code
                break;    

            //unposted 1 and 2
            case 'i':
            case 'I':
                //printf("COMMAND: %c %d\n", c, n);
                //int n = value 

                if(!initalized)
                {
                    printf("Error: heap is NULL or full\n");
                    break;
                }
                //heap is null or size is 0
                if (mainHeap->size == mainHeap -> capacity)
                {
                    printf("Error: heap is NULL or full\n");
                    break;
                }

                //else Dynamically allocates memory for an ELEMENT, 
                //sets its key field to value, and inserts it
                //to the heap pointed to by heap
                else
                {
                    //wrong
                    //mainHeap->insert(n)
                    break;
                }
                //code
                break;  
            
            //unposted 4
            //K, decreases the key of heap->H[index]
            case 'k':
            case 'K':
                //printf("COMMAND: %c\n", c);

                if(!initalized)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                //heap is null or size is 0
                if (mainHeap->size == mainHeap->capacity)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                //if index is not within interval [1, heap->size]
                if(n >= 0 && n <= mainHeap->size)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                //if n >= heap->H[index]->key
                if(n >= mainHeap->H->key)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                else
                {
                    //int n = index, int f = value

                    //probably wrong
                    //decrese the key of mainHeap->H[index(n)] 
                    //mainHeap->decreaseKey(mainHeap, n, f);
                    break;
                }
                
                //code

                break;  
            
            default: 
                cout << "Please Enter correct Input" << endl;
                break;
        }
    }//end while
exit(0);
}//end of main
*/