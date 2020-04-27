struct Nnode;

struct Gnode
{
    char data;
    struct Nnode *Nlist;
    struct Gnode *next; 
};
typedef struct Gnode Gnode;

Gnode *start;

struct Nnode
{
    struct Gnode *Gadd;
    struct Nnode *next;
};
typedef struct Nnode Nnode;



