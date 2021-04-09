#ifndef Graph_HPP
#define Graph_HPP
#define N 10
#define INF 1000000


//v[1], v[2], ... v[n] represent an array of n structs of type VERTEX
//v[i] rpresents vertex i
//v[i].color is the color of vertex i
//v[i].pi is either 0 or the predecessor of vertex i
//v[i].dist is the current value of the source to i distance
//v[i].name is not used at this moment

class VERTEX
{
    public:
    int color; //color of vertex in {0,1,2} 0 = white, 1 = grey, 2 = black
    int pi; //predecssor of vertex in {1,2, ..., n}
    float dist; //name current distance from source vertex
    int pos; //index in the heap array MAKE SURE TO UPDATE IN HEAP OPERATIONS
    
};
//allocate memory with V = (VERTEX * ) calloc(n+1, sizeof(VERTEX));
typedef VERTEX *pVERTEX;


//This the adjacency list of vertex u, and will be called A[u] 
class NODE
{
    int u; //start vertex u reduandant safe guard not needed

    int v; //end vertex v
    float w; //weight of edge (u,v)

    NODE *next; //pointer to the next node
};

//pointer class to node class
typedef NODE *pNODE;
//after reading n from the txt file use A = (pNode *) calloc(n+1, sizeof(pNode));

//A[1], A[2], ..., A[n] form an array of n pointers of type pNode
//A[i] is the adjacency list of vertex i

//int dijkstra(int n, pNODE *A, int s, int t, int f);

//V[G] adjacency list of G = (V,E,w)
//pNODE *source = source node source
//int destionation = end destination
//int flag = flag{0,1} for printing commands 

//Should be the right thing just not done implementing
int dijkstra(pVERTEX v[G], pNODE *A, int destination, int f);

#endif
/******************* End Graph.h*************************/

/*
Xue's Graph.h

typedef struct TAG_VERTEX
{
    int color; //color of vertex in {0,1,2}
    int pi; //predecssor of vertex in {1,2, ..., n}
    float dist; //name current distance from source vertex
    int pos; //position in the heap array
    char *name; //name of the POI represented by this vertex
}VERTEX;

typedef VERTEX *pVERTEX;


//v[1], v[2], ... v[n] represent an array of n structs of type VERTEX
//v[i] rpresents vertex i
//v[i].color is the color of vertex i
//v[i].pi is either 0 or the predecessor of vertex i
//v[i].dist is the current value of the source to i distance
//v[i].name is not used at this moment

typedef struct TAG_NODE
{
    int u; //start vertex u reduandant safe guard
    int v; //end vertex v
    float w; //weight of edge (u,v)

    TAG_NODE *next; //pointer to the next node
} NODE;

typedef NODE *pNode

//A[1], A[2], ..., A[n] form an array of n pointers of type pNode
//A[i] is the adjacency list of vertex i

int dijkstra(int n, pNODE *A, int s, int t, int f_i, int f_d, int f_u, int f_p);

//end

*/