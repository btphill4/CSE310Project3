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
#include <math.h>
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

//insert method
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

      node = A[u]l
      while(node) 
      {
         v = node->v;
         w = node->w;
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
               printf("Inserted V[%d], dist=%12.6f\n", v, V[v].dist);
            }
         }
         else if(V[v].dist > V[u].dist + w)
         {
            if(f_u == 1)
            {
               //print insertion information
               printf("Updated V[%d].dist from %12.6f to %12.6f\n", v, V[v].dist, V[u].dist+w);
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
            printf("V[%7d].dist= %12.6f, ", v, V[v].dist);
         }
         printf("V[%7d].pi=%d, ", v, V[v].pi);
         printf("V[%7d].pos=%d\n", v, V[v].pos);
      }
   }

   return 0;
}//end Xue slides
*/

int	dijkstra(int n, pNODE *A, int s, int t, int f_i, int f_d, int f_u, int f_p)
{
	
}
