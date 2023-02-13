
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
struct node *next_master();
struct node *tail_supplier();

struct node
{
        int info; //TODO: implement a pointer to some container
        struct node *next;
        int deletable; //can not just assign true LOL i will do a proper bitpacking later
        int master; //TODO: implement a LMSL
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
int main()
{
        int choice;
        while(1){

                printf("\n                MENU                             \n");
                printf("\n 1.Create and do not try this option again!    \n");
                printf("\n 2.Display    \n");
                printf("\n 3.autoPush wheenie-betweenie and push normal value    \n");//insert master or insert slave
                printf("\n 4.Push Master (not implemented)            \n");
                printf("\n 5.Push Slave            \n");
                printf("\n 6.Pop            \n");
                printf("\n 7.Pop which can destroy the q    \n");

                printf("\n 9.Exit       \n");
                printf("\n--------------------------------------\n");
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
                                        tail_supplier();
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
void create()//create undeletable queue
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
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)//while because this is insert_end which is a forbidden function in ZhekaMQ
                {
                        ptr=ptr->next;
			//TAIL = ptr;
                }
                ptr->next=temp;
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
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)//C one love
                {
                        printf("%d\t",ptr->info );
                        ptr=ptr->next ;
                }
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
		TAIL = temp;
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
        struct node *temp,*ptr;
	/*temp is for the element building and ptr is pointer to START*/
        if(start==NULL) //TODO:if the item is last, pop the NULL value
	/*if global == null than there is no list*/
        {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(start->next ==NULL) //the single item scenario
        {
                ptr=start;//mem value of global
                start=NULL;//singular item becomes zero items
                printf("\nThe elif popped element is:%d\t",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;//mem value of global
                while(ptr->next!=NULL)//why while?
		/*i need a tail element for not looping at the end*/
                {
			printf("inside while");
                        temp=ptr;
                        ptr=ptr->next;
                }
                printf("\nstart print madness\n");
                if (temp == tail_supplier())
                {
                        printf("OMG");
                }
                else
                {
                        printf("poiner temp %p",temp);
                        printf("pointer from ts %p",tail_supplier());
                }
                printf("\nend of print madness. The tail was popped is%p\n",ptr);
                temp->next=NULL;
                printf("\nThe else popped element is:%d\t",ptr->info);
                free(ptr);
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
struct node *tail_supplier()
{
	struct node * temp1;
	printf("please do not use this w/o list it causes segfault");
	int how_many = 0;
	temp1 = start;
        while(temp1->next!=NULL)//no more loops, this is the ultimate loop.

        {
                printf("temp1 inside while%p\n",temp1);
                how_many++;
                temp1=temp1->next;
        }
        printf("\nlast pointer was TAIL, number of items was%d",how_many);
        printf("the meaning of TAIL is: %d\n",temp1->info );
	return temp1;
}

void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:\t");
        scanf("%d",&temp->info) ;

        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}

void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is:%d\t",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d\t",ptr->info );
                        free(ptr);
                }
        }
}
