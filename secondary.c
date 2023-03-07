struct          node *           HEAD;
struct          node *           TAIL;

struct  data 
{
                char *           json;
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
        //dyn array of chars with trailling /0
        struct node * node-creating;
        node-creating = (struct node *) malloc(sizeof(struct node));
        
        
        if (NULL == HEAD && NULL == TAIL) //apply first elt
        {
                
                node-creating -> next = NULL;
                node-creating -> prev = NULL;
                node-creating -> apart = data-creating; //array with json will be not a part of struct node
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
void dummy-deque-push(data)
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
int deque-pop()
{
        struct node * node-destroying;
        if (!HEAD && !TAIL) //Do nothing
        if (NULL != HEAD && NULL != TAIL && HEAD == TAIL)//1 item case
        {
                node-destroying = TAIL;
                int returning-value = node-destroying -> dummy;
                //TAIL = node-destroying -> prev;
                TAIL = HEAD = NULL;
                free(node-destroying)
                return returning-value
        }
        else
        {
                node-destroying = TAIL;
                int returning-value = node-destroying -> dummy;
                TAIL  = node-destroying -> prev;
                free(node-destroying);
                return returning-value;
        }
}
        
