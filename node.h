struct Nnode;

struct Gnode
{
    int data;
    struct Nnode *list;
    struct Gnode *next; 
};
typedef struct Gnode Gnode;

Gnode start;

struct Nnode
{
    struct Gnode *add;
    struct Nnode *next;
};
typedef struct Nnode Nnode;



