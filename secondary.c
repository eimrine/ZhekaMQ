struct          node *           HEAD;
struct          node *           TAIL;

struct          data 
{
                int             dummy;
}
struct node {
        struct  node *           prev;
        struct  node *           next;
        struct  data *          apart;
        int                     dummy;
}
