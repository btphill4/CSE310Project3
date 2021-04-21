// n = number of vertices
// A = the adjacency list
// s = source node
// d = destination node
// f = flag
#include <limits>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "heap.h"
#define FIXED 100
using namespace std;

void dijkstra(int n, pNODE *A, int s, int d, int f)  {
    pNODE adjacency_list;
    int u;
    int v;
    float weight;

    //allocate memory for VERTEX V*
    V = new VERTEX[n+1];
    //V = (VERTEX *) calloc(n+1, sizeof(VERTEX));

    // for each v ∈ V[G] do
    for(int i = 1; i<=n; i++){
        V[i].d = numeric_limits<float>::max();// v.d = ∞
        V[i].color = 0; // v.color = white
        V[i].pi = 0; // V.π = nil
    }
    // SETTING SOURCE VERTEX
    V[s].d = 0 ;// s.d = 0
    V[s].color = 1; // s.color = 1

    //initialize HEAP
    HEAP *HEAP = initHEAP(n);

    //create and allocate a new pELEMENT temp
    //temp = (ELEMENT *) calloc(n+1, sizeof(ELEMENT));
    pELEMENT temp = new ELEMENT;
    temp->vertex = s;
    temp->key = V[s].d;

    //insert temp into heap // insert source node into heap
    HeapInsert(HEAP, temp);

    if (f == 1){
        //print insert statement
        printf("Insert vertex %d, key=%12.4f\n", temp->vertex,temp->key );// not sure if correct
    }

    while (HEAP->size != 0) {
        temp = extractMin(HEAP);

        if (f == 1) {
            //print delete statement
            printf("Delete vertex %d, key=%12.4f\n", temp->vertex,temp->key );
        }

        u = temp->vertex;
        V[u].color = 2; // u.color = black

        if (u == d) {

            break; // arrived at destination//or return;
        }
        free(temp);

        adjacency_list = A[u];
        while (adjacency_list != NULL) {
            v = adjacency_list->v;
            weight = adjacency_list->w;

            if (V[v].color == 0) { // if node has not been visited
                V[v].color = 1; // v.color = grey
                V[v].pi = u; // v.π = u
                V[v].d = V[u].d + weight; // u.d + w(u, v)

                //create and allocate a new pELEMENT temp
                pELEMENT temp = new ELEMENT;
                temp->vertex = v;
                temp->key = V[v].d;

                //insert temp into heap
                HeapInsert(HEAP, temp); //code i added

                if (f == 1) {
                    //print insert statement
                    printf("Insert vertex %d, key=%12.4f\n", temp->vertex,temp->key );// not sure if correct
                } else if (V[v].d > V[u].d + weight) {
                    V[v].d = V[u].d + weight;
                    V[v].pi = u;
                    DecreaseKey(HEAP, V[v].pos, V[v].d);
                }

            } //decreasekey of V[v]
            //

            adjacency_list = adjacency_list->next;
        }
        printf("Decrease key of vertex %i, from\t %12.4f to \t %12.4f \n",temp->vertex,temp->key,(float)v);
    }
    printf("completed dijkstra \n");
}

void printPath(int n, int source, int destination, int s, int t ){
    //int arr[n+1];
    //int u, v;
    if(V[t].color ==0){
        if (destination < 1 || destination > n || t == destination){
            printf("No %d-%d path esists. \n", s, t);
            return;
        }else{
            printf("no %d-%d path has been computed. \n", s, t);
            return;
        }
    }else if (V[t].color==1){
        printf("Path not known to be shortest: <%d", s);
    }else if (V[t].color ==2){
        printf("Shortest path: <%d", s);
    }

}