struct          node *           HEAD;
struct          node *           TAIL;

struct  data 
{
                int             dummy;
}
struct  node 
{
        struct  node *           prev;
        struct  node *           next;
        struct  data *          apart;
        int                     dummy;
}
void deque-push(data)
{
        struct data * data-creating;
        //data-creating = (struct data *) malloc(sizeof(struct data));
        struct node * node-creating;
        node-creating = (struct node *) malloc(sizeof(struct node));
        
        
        if (NULL == HEAD && NULL == TAIL) //apply first elt
        {
                
                node-creating -> next = NULL;
                node-creating -> prev = NULL;
                node-creating -> dummy = data;
               // node-creating -> apart = data-creating;
                TAIL = HEAD = node-creating;
                printf("push-first, value=",node-creating->dummy);
                
        }   
        if (NULL == HEAD -> next && NULL == TAIL -> prev) //non-first
        {
                prevHEAD = HEAD;
                
                node-creating -> next = prevHEAD;
                node-creating -> prev = NULL;
                node-creating -> dummy = data;
               // node-creating -> apart = data-creating;
                HEAD = node-creating;
                printf("push-other, value=",node-creating->dummy);
        }
struct node * deque-pop()
{
        
}
        
}
