/** 
 * This program will hold the methods to 
 * Dijkstras algorithm and be run with
 * ./dijikstra <graph> <direction> 
 * 
 * FOR REPORT PAGE 589
 */

#include "Graph.h"
#include "Heap.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
//#include <math.h>
using namespace std;

/* method to read in an edge weighed graph G = (V,E,w) from text file
  1st parameter = file name, 2nd parameter = type of graph
  ./dijikstra <graph> <direction> 

  input file: first line containts n, m. n = number of vertices, m = number of edges
  for m lines, the input will be <edge_ID> <vertex_ID> <vertex_v> <weight>
  <edge_id> = an integer in the interval [1,m] denoting that it is an edge
  <vertex_u> and vertex_v> = 2 integers in the interval [1,n] denoting the vertices that are the endpoints of the edge
  <weight> = a non-negative floating point number denoting the edge weight
  <direction> = will be either "directed" or "undirected"
  directed = each line in the file represesnts a directed edge

  graph G is represented with an adjacency list
  therefore, when the value of n is read, initialize an array of pointers for size n of the adjacency list for each vertex
  as each edge is read, insert it into the appropriate adjacency list, 
  If it is undirected, the edge is inserted into both vertex vertex_u and vertext_v's adjacency list

   algorithm on page 24.3
 C hanges: 1: initialize minheap with only the vertex source
             Note the total number of elements the heap may store is its CAPACITY and current size is set to 1
             will not store nodes with key element inifinity
          2: During relaxation period, the key field of a vertex v that is not in the heap is reduced from INF to a real number and inserted 
             into the heap
          3: instead of extract-min and relaxations until the heap is empty, the algorithm should terminate when empty or 
             if the destination is extracted from the heap, your algorthims should not perform any relaxations
        

/*
G = graph
s = source node
t = destination node
Q = HEAP 

u = extracted min node
v = vector or node?

return 0; destionation NODE found?
return 1; destination NODE not found?

colors = white = unchecked, grey = in process, black = checked NOT SURE

flow of dijsktra
1: sets each vertex inside of V[G] to white
2: sets the source node to grey and inserts it into an empty Q (HEAP)
3: Repeatedly extract the min node(u) and set the extracted Node to black(checked)
   if the extracted node (u) is equal to the destination node (t)
      if yes, return 0, else continue to look (relaxtion method)
4: relaxtion method: for each vertex inside of the extracted node (u) adjacency list
   if the vertex's color is white(unchecked), change the distance of the vertex, set v.pi to u
      then set it equal to grey and insert it into the Q (HEAP)
   else if the weight between the unchecked node is greater than the weight 
      set the weight to V and set u.pi to u
      then perform decrease key using current vertex v and v.dist
5: repeat until found or not found and return 0 or 1 
                     
int dijkstra-SP(G, s, t, f) 
{
   for each v (inside of) V[G] do
      v.color = white; v.d = INF; v.pi = nil;
   
   s.dist = 0; s.color = grey; insert s into initially empty Q

   while Q != empty do{
      //extract the min element from HEAP
      u = Extract-Min(Q)   
      u.color = black;

      //if minNode is equal to the destination node
      if (u == t)          
      {
         return 0;   //node is found 
      }

      //relaxtion method
      for each v (inside of) u.adj do  
         if(v.color == white) do
            v.d = u.d + w(u,v); v.pi = u; v.color = grey;
            insert v to Q
         
         //if the weight is heigher
         else if (v.d > u.d + w(u,v)) do
            v.d = u.d + w(u,v); u.pi = u;
            DecreaseKey(v,v.d)
   return 1;
   }
}
*/

//=============================START GRAPH.CPP============================================//

//initialize values and pointers
int pos;
int u, v;
float w;

/*
int n is number of vertices from txt file
pNODE* A is the adjacency list holding all of the NODES which holds node(s) that point 
         to other nodes(u,v) and u->color or 
*/
int dijkstra(int n, pNODE* A, pVERTEX* V, int source, int destination, int f)
{
   //initalize variables and stuctures
   pNODE node;
   pELEMENT element;
   int u, v, i;
   float w;
   int pos;

   float oldKey;

	//for each v (inside of) V[G] set v values to defaults
   //for(i = 1; i <= sizeof(V); i++)
   for(i = 1; i <= n; i++)
   {
      //V == list of edges; v == next node
      V[i]->color = 0;
      V[i]->pi = 0;  //0 for nil
      //V[i]->dist = INF;
   }
   
   //set source node to default source values
   V[source]->color = 1;   //grey color
   //V[source]->pi = 0;
   V[source]->dist = 0;    //distance to itself

   //heap and element data structures 
   HEAP* heap = heap->initialize(n);

   //create element pointer 
   element = (ELEMENT*) malloc(sizeof(ELEMENT));

   //set element pointer to source values
   element->vertex = source;
   element->key = V[source]->dist;


   //insert source pointer into heap
   heap->insert(heap, V, element);

   //if flag == 1 print insert
   if(f ==1)
   { 
      printf("Insert vertex %d, key=%12.4f\n", element->vertex, element->key); 
   }

   while(heap->size != 0)
   {  
      //extract the min element
      element = heap->extractMin(heap, V);
      
      //print delete information
      if(f == 1)
      {
         printf("Delete vertex %d, key=%12.4f\n", element->vertex, element->key); 
      }

      //sets u as the current element pointer vertex
      u = element->vertex;

      V[u]->color = 2;  //searched AND ADDED 
      
      if(u == destination)
      {  
         //cout << "U == DESINTATION" << endl;
         break; //source found
      }

      free(element);

      node = A[u];

      //else set values to the next node
      while(node != NULL)
      {
         v = node->v;
         w = node->w;
          
         //if next node is unsearched
         if(V[v]->color == 0)
         {
            //set default values
            V[v]->color = 1;
            V[v]->pi = u;
            V[v]->dist = V[u]->dist + w;
            
            //set pos 
            V[v]->pos = heap->size + 1;
            
            //element point to add to heap
            element = (ELEMENT*) malloc(sizeof(ELEMENT));
            element->vertex = v;
            element->key = V[v]->dist;

            //add to heap
            heap->insert(heap, V, element); 

            //FLAG for printing MIGHT NOT BE HERE
            if(f == 1)
            {
               //print insertion information
               printf("Insert vertex %d, key=%12.4f\n", v, V[v]->dist);
            }
            
         }//end (color == 0)
         else if(V[v]->dist > V[u]->dist + w)
         {   
            if(f == 1)
            {
               //print insertion information
               printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", v, V[v]->dist, V[u]->dist+w);
            }
            //sets the next nodes values to the current 
            oldKey = V[v]->dist;
            V[v]->dist = V[u]->dist + w; 
            V[v]->pi = u;
            
            //position maintence
            //pos = V[v]->pos; //<------- this may still be needed
            //cout << "D_Testing17" << endl;
            
            //call to decreaseKey
            heap->xueDecreaseKey(heap, V, V[v]->pos, V[v]->dist);
            //return 1;
         }//end else if
         
         //else move to next node
         node = node -> next;  
      }//end while(node!)  

   }//end while(!HEAP)
   //cout << endl <<"END DIJIKSTRAS" << endl;
   return 1;
}//end dijkstras

   
   

/** 
For "Write Path" in main
Write path scans for &s_new(new source node) and &t_new(new destination node)  
*/
void printPath(int n, int source, pVERTEX* V, int destination, int s, int t)
{
   int u, v;
   int arr[n+1];

   /*
   Shortest path from s to d can be extracted using the predecessor
   The output has two lines:
   Shortest path: <s, s2, s3, ..., sk, d>
   The path weight is: weight(s, s2, s3, ..., sk, d)
      where predecessor(s2) = s, (s3) = 2 and
      weight(s, s2, s3, ... sk, d) - D: a floating point value for whole path
*/
   //initalize variables
   PATH *pPath;
   PATH *pNODE;

   //using a stack to and pushing its values
   pNODE = (PATH *) malloc(sizeof(PATH));
   pNODE->vertex = t;
   pNODE->next = NULL;
   pPath = pNODE;
   v = pNODE->vertex;

   //while a predessor exists
   arr[0] = t;
   int iterator = 1;
   while(V[v]->pi)
   {
      //u == predessor
      u = V[v]->pi;
      pNODE = (PATH *) malloc(sizeof(PATH));

      //save path
      pNODE->vertex = u;
      pNODE->next = pPath;

      v = pNODE->vertex;
      //cout << "v: " << v<< endl;
      arr[iterator] = v;
      iterator++;
   }
   // iterator++;
   //arr[iterator] = t;
   //cout << "t: " << t<< endl;
   int arr2[iterator];
   for(int i = iterator-1; i>=0; i--)
   {
      arr2[i] = arr[i];
   }
   if(V[t]->color == 0)
   {  //if the destination is greater than 1, greater than the number of edges, or t == destination
      if(destination < 1 || destination > n || t == destination)
      {
         printf("No %d-%d path exists.\n", s,t);
         return;
      }
      else
      {
         printf("No %d-%d path has been computed.\n", s, t);
         return;
      }
   }
   else if(V[t]->color == 1)
   {
      printf("Path not known to be shortest: <%d, %d", s,t);
      //printf("Path not known to be shortest: <%d", s);
   }
   else if(V[t]->color == 2)
   {
      printf("Shortest path: <"); //printf("Shortest path: <%d", s);
      for(int i =iterator-1; i>=0 ; i--){
         printf("%d",arr2[i]);
         if(i > 0){
               printf(", ");
         }
      }
      
   }


   pNODE = pPath;
   pPath = pPath->next;
   free(pNODE);
   
   while (pPath)
   {  
      pNODE = pPath;
      printf(" , %d", pNODE->vertex);
      pPath = pPath->next;
      free(pNODE);
   }
   printf(">\n");
   printf("The path weight is: %12.4f\n", V[t]->dist);


   //==========================================================================
   /*
      Shortest path from s to d can be extracted using the predecessor
      The output has two lines:
      Shortest path: <s, s2, s3, ..., sk, d>
      The path weight is: weight(s, s2, s3, ..., sk, d)
         where predecessor(s2) = s, (s3) = 2 and 
         weight(s, s2, s3, ... sk, d) - D: a floating point value for whole path 
      
   */
   /*
   //initalize variables
   PATH *pPath;
   PATH *pNODE;
   int u, v;
   int arr[n + 1];
   //using a stack to and pushing its values
   pNODE = (PATH *) malloc(sizeof(PATH));
   pNODE->vertex = t;
   pNODE->next = NULL;
   pPath = pNODE;
   v = pNODE->vertex;

   int i = 1;
   //cout << "PRINTPATH CHECK: " << pNODE->vertex << endl;
   //if the detination is unsearched
   if(V[t]->color == 0)
   {  //if the destination is greater than 1, greater than the number of edges, or t == destination
      if(destination < 1 || destination > n || t == destination)
      {
         printf("No %d-%d path exists.\n", s,t);
         return;
      }
      else
      {
         printf("No %d-%d path has been computed.\n", s, t);
         return;
      }
   }
  else if(V[t]->color == 1)
   {
      printf("Path not known to be shortest: <%d", s);
   }
   else if(V[t]->color == 2)
   {
      printf("Shortest path: <%d", s);
   }

   //while a predessor exists
   while(V[v]->pi)
   {  */
     /*if(V[v]->pi == 1)
      {
         cout << ", " << t; 
      }
      else
      {
         cout << ", " << V[v]->pi;
      }*/
   /*
      //cout << "arr[i] = " << i << endl;
      arr[i] = V[v]->pi;
      //u == predessor
      u = V[v]->pi;
      pNODE = (PATH *) malloc(sizeof(PATH));


      //save path
      pNODE->vertex = u;
      pNODE->next = pPath;
      v = pNODE->vertex;
      i++; 
   }*/

   
   //cout << endl;
  /* pNODE = pPath;
   pPath = pPath->next;
   free(pNODE);*/
   //======================================================//
   /* Possibly More between these lines                    */
   //======================================================//
   /*while (pPath)
   {
      pNODE = pPath;
      printf(", %d", pNODE->vertex);
      pPath = pPath->next;
      free(pNODE);
   }*/
   /*cout << "SIZE OF PATH" << sizeof(pPath);
   for(int a = sizeof(pPath); a >= 0; a--)
   {
      cout << ", " <<arr[a];
   }*/

   //printf(">\n");
   //printf("The path weight is: %12.4f\n", V[t]->dist);
   
   


   /*backtrace the predecossor V[destination]->pi and V[destination]->weight 
   and then go to V[pi]->pi and V[pi]->weight etc and store values to list, then reverse the list
   */

   //Errors 
   /*
   if shortest(s,d) unknown 
   first line: Path not known to be shortest: <s, s2, s3, ..., sk, d>
   second line: path weight is: weight(s, s2, s3, ..., sk, d)
   */

   /*
   No shortest(s-d) path computed but valid values
   "No s-d path has been computed, yet."
   Hint: use %d for printing an integer here
   */

   /*
   No shortest(s-d) exsists in Graph G
   "No s-d path exists."
   */

}//end printPath



