
#include<stdlib.h>
#include <stdio.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void insert_nonce();


struct node
{
        int info; //TODO: implement a pointer to some container
        struct node *next;
        int deletable; //can not just assign true LOL i will do a proper bitpacking later
        int master; //TODO: implement a LMSL
        int slave;
        char nothing;
        /*
        my intuition tells me that there is a need to have some spacers between elements with data.
        i can not name why do i think so, but since i believe my intuition i implement this anyway
        */
};
struct item //not working yet
{
        int number;
        char symbol;
};

struct node *start=NULL; //TODO: implement a non-deletable item of list
int main()
{
        int choice;
        while(1){

                printf("\n                MENU                             \n");//i tebyu tozhe
                printf("\n 1.Create and insert at the end    \n");//why do you also option #4 ?
                printf("\n 2.Display    \n");//debug
                printf("\n 3.Insert at the beginning    \n");//insert master or insert slave
                printf("\n 4.Insert at the end  \n");//no
                printf("\n 5.Insert at specified position       \n");//no
                printf("\n 6.Delete from beginning      \n");//no
                printf("\n 7.Delete from the end        \n");//pop
                printf("\n 8.Insert wheenie-betweenie     \n");//push
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
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        insert_nonce();
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
void create()
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
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
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
                while(ptr!=NULL)
                {
                        printf("%d\t",ptr->info );
                        ptr=ptr->next ;
                }
        }
}
void insert_begin()
{
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
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
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
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("\nThe unshifted element is :%d\t",ptr->info);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL) //TODO:if the item is last, pop the NULL value
        {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(start->next ==NULL) //the last item scenario, can i do this undeletable w/o additional flags?
        {
                ptr=start;
                start=NULL;
                printf("\nThe popped element is:%d\t",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)//why while?
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\nThe popped element is:%d\t",ptr->info);
                free(ptr);
        }
}
void insert_nonce()/*at the beginning*/
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        temp->nothing = '%';//usual element is _ and between element is '%'
        temp->info = 666;//i want between element to have noticeable usual value
        temp->next =NULL;
        if(start==NULL)//i assume this happens always
        {
                start=temp;
        }
        else
        {
                printf("\nthis happens not always\t" );
                printf("%d\t",start->info);
                temp->next=start;
                start=temp;
        }
}
