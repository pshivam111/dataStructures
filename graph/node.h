struct Nnode;

struct Gnode
{
    char data;
    int visited;
    struct Nnode *Nlist;
    struct Gnode *next; 
};
typedef struct Gnode Gnode;

Gnode *start;

struct Nnode
{
    struct Gnode *Gadd;
    int weight;
    struct Nnode *next;
};
typedef struct Nnode Nnode;

struct edge
{
    char from;
    char to;
};
typedef struct edge edge;

