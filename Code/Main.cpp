/**
 * Brandon Phillips
 * This file includes the main function that ties the 
 * files together and takes command input from the user
 * 
 */
#include "Util.h"
#include "Heap.h"
#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>  //string class
//#include <math.h>
#include <iostream>
//#include <fstream>
using namespace std;

/**
./dijkstra <graph> <direction>

Text File Format:
int n = number of vertices -> use n to initialze adjacency list A[u] of vertex u, A = (pNode *) calloc (n+1, sizeof(pNode));
int m = number of edges 
each line represents an edge 
u = source vertex node
v = destination vertex node
w(u,v) = weight of u and v 

1st line: n m
2nd line: u v w(u,v)

//after reading n from the txt file use A = (pNode *) calloc(n+1, sizeof(pNode));
*/



int main(int argc, char *argv[])
{
    //initalizing values
    FILE *ifile;

    //structures
    pNODE *A;
    pNODE node;
    pVERTEX *V;
        
    //for nextWord
    char word[256];
    char word2[256];

    //for reading text, vertices, edges
    int n, m, directed_graph, i;
    //for source nodes and destination nodes
    int s, s_new, t, t_new, source, source_new, destination, destination_new;
    //for reading source node and next nodes and flags
    int u, v, edge_id, flag, flag_new;
    float w;

    //for util
    int v_scanf, v_fscanf;
    int r_value;


    /* used to get direction from commandline */
    //if there are not 3 arguments in the call, error
    if(argc != 3)
    {
        printf("Command Format: %s <graph_file> <direction>\n", argv[0]);
        exit(1);
    }

    //if <direction> == directed 
    //set directed_graph == 1 else will be 0
    if(0 == strcmp(argv[2], "directed\0"))
    {
        directed_graph = 1;
    }

    /* ifile Reading */
    //opens network file to be read 
    ifile = fopen(argv[1], "r");
    //cout << "testing1" << endl;
    if(ifile == NULL)
    {
        cout << "iFile not initalized" << endl;
    }

    //error printing ifilefor(i = 1; i <=m; i++)
   /* {
        v_fscanf = fscanf(ifile, "%d%d%d%f", &edge_id, &u, &v, &w);
        if(v_fscanf < 4)
        {
            printf("Error: fscanf returns %d.\n", v_fscanf);
            exit(1);
        }
    
        printf("ErrorGLX1: cannot open file for reading.\n");
    }*/

    //read m n = |V| pVERTEX* V
    //cout << "M before read" << n << endl;
    //cout << "N before read" << m << endl;

    v_fscanf = fscanf(ifile, "%d%d", &n, &m);
    //cout << "testing2" << endl;
    if(v_fscanf < 2)
    {
        printf("ErrorGLX2: fscan returns %d.\n", v_fscanf);
    }
    
    /*cout << "M READ FROM FILE: " << m << endl;
    cout << "N READ FROM FILE: " << n << endl;*/

    /* allocate memory for adjacency lists */
    //Uses int n from the graph file to 
    //created the adjacency list to hold list of vertex
    A = (pNODE *) calloc(n+1, sizeof(pNODE));
    if(!A)
    {
        printf("Error: calloc failure.\n");
        exit(1);
    }

    /* read in edges and construct adjacency lists */
    //for each m (number of edges)
    for(i = 1; i <=m; i++)
    {
        //std::cout << "THIS IS I:" << i << endl;
        //scan the file for 
        //int edge_id(name),int u(start index), int v(destination/end vertex), float weight
        v_fscanf = fscanf(ifile, "%d%d%d%f", &edge_id, &u, &v, &w);
        if(v_fscanf < 4)
        {
            printf("Error: fscanf returns %d.\n", v_fscanf);
            exit(1);
        }
    
        //creates a pointerNode using size of NODE
        node = (pNODE) malloc(sizeof(NODE));
        if(!node)
        {
            printf("Error: malloc failure.\n");
            exit(1);
        }

        //sets the current [m] node with values
        node->u = u;
        node->v = v;
        node->w = w;
        node->next = A[u];

        //adjacency list does not need to be freed 
        //adds the [m] node to the 
        A[u] = node;

        //for undirected graphs
        if(!directed_graph)
        {
            //BGN: undirected 
            node = (pNODE) malloc(sizeof(NODE));
            if(!node)
            {
                printf("Error: malloc failure.\n");
                exit(1);
            }
            node->u = v;
            node->v = u;
            node->w = w;
            node->next = A[v];
            A[v] = node;
        }//end if Undirected Graphs

    }//end for loop
    /*
    //BGN for adjacency lists
    for(i = 1; i<=n; i++)
    {
        printf("Node %d:", i);
        node = A[i];
        while(node)
        {
            printf("-->|%d %4.1f| ", node->v, node->w);
            node = node->next;
        }
        printf("\n");
    }
    //Checking adjacency list, Bug checking
    */

    //close the input file;
    fclose(ifile);

    //set default values for VERTEX variables
    source = 0;
    destination = 0;
    //creates V[]
    V = (pVERTEX *) calloc(n+1, sizeof(pVERTEX));
    if(!V)
    {
        printf("Error: calloc failure.\n");
        exit(1);
    }

    //creates vertex objects to be pointed at and adding the values to each vertex
    for(i = 1; i <= n; i++)
    {
        V[i] = (VERTEX *) malloc(sizeof(VERTEX));
        if(!V[i])
        {
            printf("Error: malloc failure.\n");
            exit(1);
        }
        V[i]->vertex = i;
    }


    /*~~~~~~~~~~~~~~Query Loop~~~~~~~~~~~~~*/
    while(1)
    {   
        //first read in command 
        r_value = nextWord(word);

        //if there is no read value
        if(!r_value) 
        {
            printf("ErrorGLX: EOF\n");
            continue;
        }

        //stop command (FREE MEMORY HERE)
        if(0 == strcmp(word, "stop"))
        {
            printf("Query: %s\n", word);
            //heap.heapFree();
            break;
        }//end stop

        //find command
        if(0 == strcmp(word, "find"))
        {   
            //read in 3 values
            v_scanf = scanf("%d%d%d", &source_new, &destination_new, &flag_new);
            if(v_scanf !=3)
            {
                //printf("ErrorGLX3: wrong return value for scanf\n");
                continue;
            }
            /******************************************************************************
            if(source_new < 0)
            {
                printf("Query: %s %d %d %d\n",
                    word, source_new, destination_new, flag_new);
            }*****************************************************************/
            else
            {
                printf("Query: %s %d %d %d\n", 
                    word, source_new, destination_new, flag_new);
                if(source_new < 1 || source_new > n || flag_new < 0 || flag_new > 1)
                {
                    printf("Error: invalid find query\n");
                }
                else
                {
                    //cout << "IF WE MADE IT THIS FAR GG BOIS" << endl;
                    source = source_new;
                    destination = destination_new;
                    flag = flag_new;

                    //dijkstras call
                    dijkstra(n, A, V, source, destination, flag);
                    continue;
                }
            }

        }//end find

        //write command
        else if(0 == strcmp(word, "write"))
        {
            r_value = nextWord(word2);
            if(!r_value)
            {
                printf("ErrorGLX4: EOF\n");
                continue; 
            }
            if(0 == strcmp(word2, "path"))
            {
                v_scanf = scanf("%d%d", &s_new, &t_new);
                if(v_scanf !=2)
                {
                    //out << "s_new: " <<s_new << endl;
                    //cout << "t_new: " <<t_new << endl;

                    //for(int x = 0; x <= sizeof(v_fscanf))
                    printf("ErrorcwGLX5: wrong return value for scanf\n");
                    continue;
                }
                else
                {
                    printf("Query: %s %s %d %d\n", word, word2, s_new, t_new);

                    //if source == 0 (doesn't exist {1,2,3...}) or A isn't initalized
                    if(source == 0 || !A)
                    {
                        printf("Error: no path computation done\n");
                    }

                    /* If the new source != old source (Good)
                       If the new source is the same as the old source
                       If the new source is less than 1 {1,2,3...} 
                       or If the new source is greater than the number of Number
                       of vertices (out of bounds) */
                    else if(s_new != source || t_new == s_new || t_new < 1 || t_new > n)
                    {
                        printf("Error: invalid source destination pair\n");
                    }

                    /* finally print the old source equals the new source 
                       and the new destination equals the destination*/
                    else
                    {
                        s = s_new; t = t_new;
                        printPath(n, source, V, destination, s, t);
                    }

                }
            }
        }//end of write
        else
        {
            printf("ErrorGLX: Bad Input\n");
            continue;
        }
    }//end of query loop
    


}

