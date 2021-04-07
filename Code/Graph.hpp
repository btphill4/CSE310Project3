#ifndef GRAPH_HPP
#define GRAPH_HPP
#define N 10
#define INF 1000000
//holds adjacency list nodes
class adjListNode
{
    public: 
    //variables
    int destination;
    int weight;
    adjListNode* next;

    //constructor
    adjListNode()
    {

    }
    //methods
    adjListNode* newAdjListNode(int destination, int weight);
};

//structure of the adjList
class adjList
{
    adjListNode::adjListNode *head; //pointer to head of list
};

//structure to contain variables to edges
class Edge
{
    public: 
    //variables
    int source;
    int destination;
    int weight;
            
};

class Vertex
{
    public:
    //variables
    int color;
    int pi; //predecessor
    float d; //distance from source
};

class Graph
{
	public:
    //variables
    int v;  //number of vertices
    adjList* array;

    //constructors
    Graph()
    {

    }

    //methods
    Graph* createGraph(int v);

};
//void Dijkstra(int n, int w[][N], Edge* f, int len[N], int source);

#endif