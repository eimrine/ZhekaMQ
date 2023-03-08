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
void yalpsid();

void main()
    {
    int choice =0;
        while(choice != 9)
        {
            printf("\n*********Main Menu*********\n");
            printf("\nChoose one option from the following list ...\n");
            printf("\n===============================================\n");
            //printf("\n1.Insert in Beginning\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search\n6.Show\n7.Exit\n");
            printf("\nEnter your choice? 1-push 2-pop 6-display-7 8-exit\n");
            scanf("\n%d",&choice);
            switch(choice)
            {
                case 1:
                dummy_deque_push();
                break;
                case 2:
                dummy_deque_pop();
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
                yalpsid();
                break;
                case 8:
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
void dummy_deque_push()//at start
{
        int userinput;
        struct node * node_creating;
        node_creating = (struct node *) malloc(sizeof(struct node));
        printf("\nUser, please enter some int value\t");
        scanf("%d", &userinput);
/*
        if (NULL != HEAD && NULL != TAIL && NULL != HEAD -> next/* && NULL == TAIL -> prev) //non-second
        {
                printf("\n~~~non-first~~~");
                struct node * prevHEAD = HEAD;


                node_creating -> prev = NULL;
                node_creating -> next = prevHEAD;


                node_creating -> dummy = userinput;
                HEAD = node_creating;
                printf("\nshow 2nd value=\t");
                printf("%d",node_creating->dummy);
                printf("\tgo 2nd next\n");
        }
*/
        if (NULL != HEAD && NULL != TAIL/* && NULL == HEAD -> next && NULL == TAIL -> prev*/) //non-first
        {//this block is STRICTLY first
                printf("\n~~~non-first~~~");
                //struct node * prevHEAD = HEAD;
                //prevHEAD -> prev = NULL;

                HEAD -> prev = node_creating;
                node_creating -> prev = NULL;
                node_creating -> next = /*prev*/HEAD;


                node_creating -> dummy = userinput;

                HEAD = node_creating;
                printf("\nshow 2nd value=\t");
                printf("%d",node_creating->dummy);
                printf("\tgo 2nd next\n");
        }

        if (NULL == HEAD && NULL == TAIL) //apply first elt
        {//this block is STRICTLY second
                node_creating -> next = NULL;
                node_creating -> prev = NULL;
                node_creating -> dummy = userinput;
                TAIL = HEAD = node_creating;
                printf("\nshow 1st value=\t");
                printf("%d",node_creating->dummy);
                printf("\tgo 1st next\n");
        }
        printf("\n~~~lets print head");
        printf("%d\n", HEAD -> dummy);
        printf("\n~~~lets print TAIL");
        printf("%d\n", TAIL -> dummy);
        //printf("~~~Now iterator");
        //printf("%d\n", iterator -> dummy);
        printf("\nZBS!~~~");
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

int dummy_deque_pop()
{
        struct node * node_destroying;
        int returning_value;

        printf("\nlets print head");
        printf("%d\n", HEAD -> dummy);
        printf("\nlets print TAIL");
        printf("%d\n", TAIL -> dummy);
        printf("Now returning value");
        printf("%d\n", node_destroying -> dummy);
        printf("Now prev!!!!!!!!!!!!!!!!!!!!!");
        printf("%d\n", node_destroying -> prev);
        printf("\nZBS!");

        if (!HEAD && !TAIL) printf("\nlets print head"); //Do nothing
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

void display()
{
    printf("BEFORE ENTERING DISPLAY");
        struct node *iterator;
        iterator = HEAD;
        printf("\nlets print head");
        printf("%d\n", HEAD -> dummy);
        printf("\nlets print TAIL");
        printf("%d\n", TAIL -> dummy);
        printf("Now iterator");
        printf("%d\n", iterator -> dummy);
        printf("Now prevprevprevprev");
        printf("%d\n", iterator -> prev);
        printf("\nZBS!");
        if(NULL == HEAD)
        {
            printf("\nnothing to print");
        }
        else
        {
            printf("\n printing values ... \n");

            while(NULL != iterator && NULL != iterator -> next)
            {

                printf("%d\n", iterator -> dummy);
                iterator = iterator -> next;
            }
            printf("%d\n", iterator -> dummy);
            printf("else");
        }
        printf("after else (QUITTING DISPLAY)");

}
void yalpsid()
{
    printf("BEFORE ENTERING DISPLAY");
        struct node *iterator;
        iterator = TAIL;
        printf("\nlets print head");
        printf("%d\n", HEAD -> dummy);
        printf("\nlets print TAIL");
        printf("%d\n", TAIL -> dummy);
        printf("Now iterator");
        printf("%d\n", iterator -> dummy);
        printf("\nZBS!");
        if(NULL == TAIL)
        {
            printf("\nnothing to print");
        }
        else
        {
            printf("\n printing values ... \n");

            while(NULL != iterator && NULL != iterator -> prev)
            {

                printf("%d\n", iterator -> dummy);
                iterator = iterator -> prev;
            }
            printf("%d\n", iterator -> dummy);
            printf("else");
        }
        printf("after else (QUITTING DISPLAY)");

}
