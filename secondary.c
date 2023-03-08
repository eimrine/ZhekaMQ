#include        <stdio.h>
#include        <stdlib.h>
//#include        <boolean.h>


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
struct          node *           HEAD;
struct          node *           TAIL;

void        deque_push();
void  dummy_deque_push();
//char * deque pop();
int deque_pop();
void display();

void main()
    {
    int choice =0;
        while(choice != 9)
        {
            printf("\n*********Main Menu*********\n");
            printf("\nChoose one option from the following list ...\n");
            printf("\n===============================================\n");
            printf("\n1.Insert in Beginning\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search\n6.Show\n7.Exit\n");
            printf("\nEnter your choice? 1267\n");
            scanf("\n%d",&choice);
            switch(choice)
            {
                case 1:
                dummy_deque_push();
                break;
                case 2:
                //dummy_deque_pop();
                break;
                case 3:

                break;
                case 4:
                //deletion_last();
                break;
                case 5:
                //search();
                break;
                case 6:
                display();
                break;
                case 7:
                exit(0);
                break;
                default:
                printf("Please enter valid choice..");
            }
        }
    }
/*
void deque_push(int data)
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
                struct node * prevHEAD = HEAD;

                node_creating -> next = prevHEAD;
                node_creating -> prev = NULL;
                node_creating -> dummy = data;
               // node-creating -> apart = data-creating;
                HEAD = node_creating;
                printf("push-other, value=",node_creating->dummy);
        }
}
*/
void dummy_deque_push(int data)
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
                struct node * prevHEAD = HEAD;

                node_creating -> next = prevHEAD;
                node_creating -> prev = NULL;
                node_creating -> dummy = data;
               // node-creating -> apart = data-creating;
                HEAD = node_creating;
                printf("push-other, value=",node_creating->dummy);
        }
}
/*
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
                return returning_value;
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
*/
/*
int dummy_deque_pop()
{
        struct node * node_destroying;
        int returning_value;
        if (!HEAD && !TAIL) //Do nothing
        if (NULL != HEAD && NULL != TAIL && HEAD == TAIL)//1 item case
        {
                node_destroying = TAIL;
                returning_value = node_destroying -> dummy;
                //TAIL = node-destroying -> prev;
                TAIL = HEAD = NULL;
                free(node_destroying);
                //return returning_value;
        }
        else
        {
                node_destroying = TAIL;
                returning_value = node_destroying -> dummy;
                TAIL  = node_destroying -> prev;
                free(node_destroying);
                //return returning_value;
        }
        return returning_value;
}
*/
void display()
{
        struct node *iterator;
        iterator = HEAD;
        if(NULL == HEAD)
        {
            printf("\nnothing to print");
        }
        else
        {
            printf("\n printing values ... \n");

            while(NULL != iterator -> next)
            {

                printf("%d\n", iterator -> dummy);
                iterator = iterator -> next;
            }
            printf("%d\n", iterator -> dummy);
        }

    }
