/** 
 * This program will hold the methods to 
 * Dijkstras algorithm and be run with
 * ./dijikstra <graph> <direction> 
 */

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
