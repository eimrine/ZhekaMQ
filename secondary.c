struct          node *           HEAD;
struct          node *           TAIL;

struct  data
{
                char *           json;
};
struct  node
{
        struct  node *           prev;
        struct  node *           next;
        struct  data *          apart;
        int                     dummy;
};
void deque_push(data)
{
        struct data * data_creating;
        //dyn array of chars with trailling /0
        struct node * node_creating;
        node_creating = (struct node *) malloc(sizeof(struct node));


        if (NULL == HEAD && NULL == TAIL) //apply first elt
        {

                node_creating -> next = NULL;
                node_creating -> prev = NULL;
                node_creating -> apart = data_creating; //array with json will be not a part of struct node
                TAIL = HEAD = node_creating;
                printf("push-first, value=",node_creating->dummy);

        }
        if (NULL == HEAD -> next && NULL == TAIL -> prev) //non-first
        {
                prevHEAD = HEAD;

                node_creating -> next = prevHEAD;
                node_creating -> prev = NULL;
                node_creating -> dummy = data;
               // node-creating -> apart = data-creating;
                HEAD = node_creating;
                printf("push-other, value=",node_creating->dummy);
        }
void dummy_deque_push(data)
{
        struct data * data_creating;
        //data-creating = (struct data *) malloc(sizeof(struct data));
        struct node * node_creating;
        node_creating = (struct node *) malloc(sizeof(struct node));


        if (NULL == HEAD && NULL == TAIL) //apply first elt
        {

                node_creating -> next = NULL;
                node_creating -> prev = NULL;
                node_creating -> dummy = data;
               // node-creating -> apart = data-creating;
                TAIL = HEAD = node_creating;
                printf("push-first, value=",node_creating->dummy);

        }
        if (NULL == HEAD -> next && NULL == TAIL -> prev) //non-first
        {
                prevHEAD = HEAD;

                node_creating -> next = prevHEAD;
                node_creating -> prev = NULL;
                node_creating -> dummy = data;
               // node-creating -> apart = data-creating;
                HEAD = node-creat_ng;
                printf("push-other, value=",node_creating->dummy);
        }
char * deque_pop()
{
        struct node * node_destroying;
        if (!HEAD && !TAIL) //Do nothing
        if (NULL != HEAD && NULL != TAIL && HEAD == TAIL)//1 item case
        {
                node_destroying = TAIL;
                char * returning_value;
                returning_value = node_destroying -> apart;
                //TAIL = node-destroying -> prev;
                TAIL = HEAD = NULL;
                free(node_destroying);
                return returning_value
        }
        else
        {
                node_destroying = TAIL;
                int returning_value = node_destroying -> dummy;
                TAIL  = node_destroying -> prev;
                free(node_destroying);
                return returning_value;
        }

}
int dummy_deque_pop()
{
        struct node * node_destroying;
        if (!HEAD && !TAIL) //Do nothing
        if (NULL != HEAD && NULL != TAIL && HEAD == TAIL)//1 item case
        {
                node_destroying = TAIL;
                int returning_value = node_destroying -> dummy;
                //TAIL = node-destroying -> prev;
                TAIL = HEAD = NULL;
                free(node_destroying)
                return returning_value
        }
        else
        {
                node_destroying = TAIL;
                int returning_value = node_destroying -> dummy;
                TAIL  = node_destroying -> prev;
                free(node_destroying);
                return returning_value;
        }

}
