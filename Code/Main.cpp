/**
 * Brandon Phillips
 * This file includes the main function that ties the 
 * files together and takes command input from the user
 * 
 */

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include<string.h>      //string class
using namespace std;

/**
Flow of the program
1: enter s and t    //1 1000
2: enter f_i, f_d, f_u, and f_p //1 1 1 1
 */

int main(int argc, char** args) //int argc, char** args
{
    //used to get direction from commandline
    string direction;
    for(int i = 0; i <argc; i++) {
        printf("%d: %s\n", i, args[i]);
    } 
    if(strcmp(args[1], "insertion") ==0 )
    {
        direction = "directed";              //set sorting string to value used in left shift
    }
    else if (strcmp(args[1], "quick") ==0 )
    {
       direction = "undirected";               //set sorting string to value used in left shift
    }
    else
    {
        return 1;                  //else returns an error
    }

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

}