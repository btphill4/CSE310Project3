/** 
 * This program will hold the methods to 
 * Dijkstras algorithm and be run with
 * ./dijikstra <graph> <direction> 
 * 
 * FOR REPORT PAGE 589
 */

#include "Graph.hpp"
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
*/

/*
 algorithm on page 24.3
 Changes: 1: initialize minheap with only the vertex source
             Note the total number of elements the heap may store is its CAPACITY and current size is set to 1
             will not store nodes with key element inifinity
          2: During relaxation period, the key field of a vertex v that is not in the heap is reduced from INF to a real number and inserted 
             into the heap
          3: instead of extract-min and relaxations until the heap is empty, the algorithm should terminate when empty or 
             if the destination is extracted from the heap, your algorthims should not perform any relaxations
        
*/
//find method
//find <source> <destination> <flag>

//insert method WRONG
/*
void	Graph::Dijkstra(int n, int w[][N], Edge* f, int len[], int source)
{
   //intializing values
	int i, x, vnear, min;
   Edge::Edge e;
   x = 0;

   int visted[n], length[n];
   length[0] = -1;
   for(i = 0; i < n; i++)
   {
      //check if i != source-1
      if(i != source-1)
      {
         //if i!= the source, it sets the visted[i] to source -1 
         visted[i] = source -1;
         length[i] = w[source-1][i];
      }

   }

   //while x < n 
   while(x < n)
   {
      min = INF; 
      for(i = 0; i < n; i++)
      {
         if(length[i] >= 0 && length[i] < min)
         {
            min = length[i];
            vnear = i;
         }
      }

      //add the edge's source to the visited[vnear]
      e.source = visited[vnear];
      e.end = vnear;
      
      //set the edge weight to min
      e.weight = min;

      //perform check to find the lengths
      if(e.source == (source - 1))
      {
         len[e.end] = 1;
      }
      else
      {
         len[e.end] = len[e.source] + 1
      }
      F[y++] = e; //adds the edge to the array of finished edges (Edge F)

   }


}*/
/*
Xue's code

not sure above parts
{ //full class brackets

   { //method unfinished above PRINT METHOD I THINK

      node = A[u];
      while(node) 
      {
         v = node->v;
         w = node->w;

         //relaxtion method 
         if(V[v].color == 0)
         {
            V[v].dist = V[u].dist + w;
            V[v].pi = u;
            V[v].color = 1;
            //printf("V[d].color to 1\n" , v);
            V[v].pos = heap->size+1;
            element = (ELEMENT *) malloc(sizeof(ELEMENT));
            element->vertex = v;
            element->key = V[v].dist;
            Insert(heap, element);
            if(f_i == 1)
            {
               //print insertion information
               printf("Inserted V[%d], dist=%12.4f\n", v, V[v].dist);
            }
         }
         else if(V[v].dist > V[u].dist + w)
         {
            if(f_u == 1)
            {
               //print insertion information
               printf("Updated V[%d].dist from %12.4f to %12.4f\n", v, V[v].dist, V[u].dist+w);
            }
            V[v].dist = V[u].dist + w;
            V[v].pi = u;
            pos = V[v].pos;
            DecreaseKey(heap, pos, V[v].dist);
         }
         node = node -> next;
      }
   }

   //print method?
   if(f_p ==1)
   {
      for(v=1; v <= n; v++)
      {
         if(V[v].color == 0)
         {
            printf("V[%7d].dist=    inifinity, ", v);
         }
         else
         {
            printf("V[%7d].dist= %12.4f, ", v, V[v].dist);
         }
         printf("V[%7d].pi=%d, ", v, V[v].pi);
         printf("V[%7d].pos=%d\n", v, V[v].pos);
      }
   }

   return 0;
}//end Xue slides
*/


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

From video, Successful relaxation:
if(V[v].d > V[u].d + w)
{
   V[v].d = V[u].d + w;
   V[v].pi = u;

   //go to vertex array and find position 
   pos = V[v].pos;
   DecreaseKey(heap, pos, V[v].d);
}
*/


int dijkstra(int n, pNODE *A,int source, int destination, int f);
{
	//for each v (inside of) V[G] set v values to defaults
   for(int i = 0; i <= sizeof(V); i++ )
   {
      V[i]->color = 0;
      V[i]->pi = NULL;
      V[i]->dist = INF;
   }

   //set source node to default source values
   A
}