
#include<stdlib.h>
#include <stdio.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_pos();
void delete_begin();
void delete_end();
void insert_nonce_master();
void insert_nonce2();
void pop();
void master_push();
void slave_push();
void slave_pack_push();
void poppoppop();
void ptrcmp();

struct node *next_master();
struct node *tail_supplier();
struct node *pre_tail_supplier();

struct node
{
        int info; //TODO: implement a pointer to some container
        struct node *next;
	struct node *prev;//can not operate with the other side of the list w/o loops
        int deletable; //can change int to bool if i will cast #include <boolean.h>
        int master; //TODO: implement an LMSL
        int slave; //TODO: flood the slave queue of ZhekaMQ here and the master queue still works!
        char nothing;// _ or %
        /*
        my intuition tells me that there is a need to have some spacers between elements with data.
        i can not name why do i think so, but since i believe my intuition i implement this anyway
        */
        struct node *next_master;
};
struct item //not working yet
{
        int number;
        char symbol;
};



struct node *start=NULL; //TODO: rename global variable with caps
struct node *TAIL = NULL;//TODO: implement a source of information about the last element of the LL.
struct node *PRETAIL = NULL;// pop operation needs an access to second-last element
struct node * CAR = NULL; //start
struct node * CAAR = NULL; //start->next
struct node * CAAAR = NULL; //start->next->next
struct node * CDR = NULL; //TAIL
struct node * CDDR = NULL; //PRETAIL

int main()
{
        int choice;
        while(1){

                printf("\n                MENU                             \n");
                printf("n 1.Create and do not try this option again! PRETAIL is not implemented here!\n");
                printf("n 2.Display    \n");
                printf("n 3.autoPush wheenie-betweenie and push normal value    \n");//insert master or insert slave
                printf("n 4.Push Master (not implemented)            \n");
                printf("n 5.Push Slave            \n");
                printf("n 6.Pop            \n");
                printf("n 7.Pop which can destroy the q    \n");

                printf("n 9.Exit       \n");
                printf("n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);//sometimes I prefer not to think what those symbols mean, just programming as usual
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        insert_begin();
                                        break;
                        case 4:

                                        master_push();
                                        break;
                        case 5:

                                        slave_push();
                                        break;
                        case 6:
                                        printf("\n Undestroyable pop isn't implemented \n");
                                        pre_tail_supplier();
                                        break;
                        case 7:
                                        pop();
                                        break;
                        case 8:
                                        insert_nonce2();
                                        break;

                        case 9:
                                        exit(0);
                                        break;

                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
void create()//create START and do not shift no value in it; shift as JS
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                exit(0);
        }
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->info);
        temp->next=NULL;
	temp->prev=NULL;
        if(start==NULL)//0 becomes 1
        {
                start=temp;//create first
                CAR = temp;//i do not comment reads but all writes are commented
                CDR = start;//remember that everything in create() is violating of rules because this is shift() not push()
        }
        else if (start -> next == NULL)//1 turns to 2
        {//last case copied
                ptr=start;
                //ptr = CAR;
                while(ptr->next!=NULL)//while because this is insert_end which is a forbidden function in ZhekaMQ
                {
                        ptr=ptr->next;
			//TAIL = ptr;
                }
                CDDR = ptr;
                ptr->next=temp;
		ptr->prev=start;
                CDR = temp;
        }
        else if (start -> next -> next == NULL)//moving from 2 to 3 requires another case if not in Lisp
        {
                ptr=start;
                //ptr = CAR;
                while(ptr->next!=NULL)//while because this is insert_end which is a forbidden function in ZhekaMQ
                {
                        ptr=ptr->next;
			//TAIL = ptr;
                }
                CDDR = ptr;
                ptr->next=temp;
                CDR = temp;
        }
        else
        {
                ptr=start;
                //ptr = CAR;
                while(ptr->next!=NULL)//while because this is insert_end which is a forbidden function in ZhekaMQ
                {
                        ptr=ptr->next;
			//TAIL = ptr;
                }
                CDDR = ptr;
                ptr->next=temp;
                CDR = temp;
        }
}
void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                //ptr = CAR;
                printf("\nThe List elements are:\n");

                while(ptr!=NULL)//C one love
                {
                        printf("%d\t",ptr->info );
                        ptr=ptr->next;
                }
                //Lisp another
        }
}
void insert_begin()
{
        insert_nonce2();
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info);
        temp->nothing = '_';//usual element is _ and between element is '%'
        temp->next =NULL;
        if(start==NULL)
        {
		printf("start was NULL");
                start=temp;
                CAR = temp;
		TAIL = temp;//dear Lord, please make my code not facing race condition in this place. amen.
		CDR = temp;
		PRETAIL = NULL;
		CDDR = NULL;
        }
        else
        {
		printf("start wasn't NULL");
                temp->next=start;
                start=temp;
        }
}
void pop()
{
        struct node *temp,*ptr,*pre,*ptrcopy;
	/*temp is for the element building and ptr is pointer to START*/
        if(start==NULL) //TODO:if the item is last, pop the NULL value
	/*if global == null than there is no list*/
        {
                printf("\nList is Empty and I believe the TAIL == NULL as well");
                CAR = NULL;
                printf("print car %p\t tail %p\t",CAR,TAIL);
                exit(0);
        }
        else if(start->next ==NULL) //the single item scenario
        {
                ptr=start;//this needs to be run earlier
                //ptr = CAR
                start=NULL;//singular item becomes zero items
                CAR = NULL;
                printf("\nThe elif popped element is:%d\t",ptr->info);
                TAIL = NULL;
                CDR = NULL;
                free(ptr);
        }
        else if(start->next->next ==NULL) //the double item scenario
        {
                printf("\nkilroy was here %p",start->next->info);
                ptr=start->next;//this needs to be run earlier
                //ptr = CAAR;
                ptrcopy = ptr;
                printf("the next ptr is: %p\n",ptr->next );
                //start=NULL;//double item becomes singular item
                printf("\nThe doubleif popped element is:%d\t",ptr->info);
                //start- = NULL;
                PRETAIL = NULL;
                CDDR = NULL;
                start->next = NULL;
                CAAR = NULL;
                free(ptrcopy);
                printf("\nlet's inspect a start element %p with meaning %d having next element %p",start,start->info,start->next);
        }
        else
        {
                ptr=start;
                //ptr = CAR;
                //pre=pre_tail_supplier();//lisp experimenting starts from here
                pre = CDDR;
                printf("ive got a pre, %p , its value is %d\t",pre, pre->info);
                while(ptr->next!=NULL)//this while lets temp to be show to CDDR
                {
			printf("\ninside pop-while");
                        temp=ptr;
                        ptr=ptr->next;
                }

                //ptrcmp(temp, pre_tail_supplier());

                if (temp == CDDR)
                {
                        printf("\nOMG\n");
                }
                else
                {
                        printf("\n???poiner temp %p",temp);
                        printf("\n???pointer CDDR ts %p",CDDR);//TODO: give some info right here
                }

                printf("\nend of print madness. The tail was popped is%p\n",ptr);
                //temp->next=NULL; //earlier
                pre_tail_supplier()->next = NULL;//second lisp action
                //CDDR->next = NULL;
                //ptrcmp(temp->next,pre->next->next); //find that value
                printf("\nThe else popped element is:%d\t",ptr->info);
                printf("new pretail, %p , has a value %d\t",pre_tail_supplier(), pre_tail_supplier()->info);
                //ptrcmp(pre->next,ptr);//dont work anymore
                free(pre_tail_supplier()->next->next);//second lisp action
                //free(CDDR->next->next);
                if (!CDR && !CDDR && CDDR->next->info != CDR->info)
                /*if you will ever check NULL->something you will get segfault!*/
                {
                        printf("fatal error! cddr %d\t cdr %d\t ",CDDR->info,CDR->info);
                }
                else
                {
                        printf("CDR ready");
                }
                //free(CDDR->next);

                //ptrcmp(ptr, pre->next->next);//also find that
                //free(ptr);
        }
}
void insert_nonce_master()
{
}

void insert_nonce2()//push 666
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        //printf("\nEnter the data value for the node:\t" );
        //scanf("%d",&temp->info);
        temp->info = 666;
        temp->nothing = '%';//usual element is _ and between element is '%'
        temp->next =NULL;//because this is the new beginning but undeletable yet to be implemented
        if(start==NULL)
        {
                printf("\n start == null\t" );
                start=temp;
        }
        else
        {
                printf("\n start != null\t" );
                temp->next=start;
                start=temp;
        }
}
void master_push()
{
        printf("\n Master isn't implemented \n");
}
void slave_push()
{
        insert_nonce2();
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter what to push, quickly!:\t" );
        scanf("%d",&temp->info);
        temp->nothing = '_';//usual element is _ and between element is '%'
        temp->slave = 1;
        temp->next =NULL;
        temp->next_master = NULL;//sorry
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                printf("\n i don't believe this will ever run \n");
                temp->next=start;
                start=temp;
        }
}
void slave_pack_push(){}
void poppoppop(){}
/*
struct node *next_master(struct node *remember_this_pointer){
        struct node *temp;
        temp->next_master = remember_this_pointer->next_master;
        return temp;
}
*/
struct node *pre_tail_supplier()
{
        printf("\nTAILSUPstartiter\n");
	struct node * temp1;
	//printf("please do not use this w/o list it causes segfault");
	int how_many = 0;
	temp1 = start;
        while(temp1->next->next!=NULL && temp1->next != NULL && temp1 != NULL)//only pretail has such a chain
        {
                printf("number %d inside while in pre%p\n",temp1->info,temp1);
                how_many++;
                temp1=temp1->next;
        }
        if (temp1->next == NULL) return NULL;
        printf("\nMenwhile in CDDR: %d\n",CDDR->info);
        printf("\nlast pointer was PRETAIL, number of items was%d",++how_many);
        printf("the meaning of PRETAIL is: %d\n",temp1->info );
        printf("\nPRETAIL has a tail as many as%d\n",temp1->next->info);
        printf("\nMenwhile in CDDR: %d\n",CDDR->info);
	return temp1;
}
struct node *tail_supplier()
{
        printf("\nTAILSUPstartiter\n");
	struct node * temp1;
	//printf("please do not use this w/o list it causes segfault");
	int how_many = 0;
	temp1 = start;
        while(temp1->next->next!=NULL)//no more loops, this is the ultimate loop.

        {
                //printf("temp1 inside while%p\n",temp1);
                how_many++;
                temp1=temp1->next;
        }
        printf("\nlast pointer was TAIL, number of items was%d",++how_many);
        printf("the meaning of TAIL is: %d\n",temp1->info );
        printf("\nTAILSUPenditer\n");
	return temp1;
}

void ptrcmp(struct node * ptr1, struct node * ptr2)
{
        struct node * ptr1good, * ptr2good;
        ptr1good = ptr1;
        ptr2good = ptr2;
        if (ptr1good == ptr2good)
        printf ("voila!");
        else
        {
                printf("ptr1 has an address %p and value\t%d\n",ptr1good,ptr1good->info);
                printf("ptr2 has an address %p and value\t%d\n",ptr2good,ptr2good->info);
                //printf("\nThe cmp element is:%p\t",ptr1 );
                //printf("\nThe gmp element is:%p\t",ptr2 );
        }
}
