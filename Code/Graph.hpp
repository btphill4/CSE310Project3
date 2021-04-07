#ifndef GRAPH_HPP
# define GRAPH_HPP
#define N 10

//holds adjacency list nodes
class adjListNode
{
    public: 
    int destination;
    int weight;
    adjListNode* next;

    adjListNode* newAdjListNode(int destination, int weight);
};

//structure of the adjList
class adjList
{
    //pointer to head of list
    adjListNode::adjListNode *head;
};
class Edge
{
    public: 
    int source;
    int destination;
    int weight;
            
};

class Vertex
{
    public:
    int color;
    int pi; //predecessor
    float d; //distance from source
};

class Graph
{
	public:
        int v;  //number of vertices
        adjList* array;

};
//void Dijkstra(int n, int w[][N], Edge* f, int len[N], int source);

#endif