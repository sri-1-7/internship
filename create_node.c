//header files
#include<stdio.h>
#include<stdlib.h>

//strcture node
struct node{
        int data;
        struct node *link;
    };
int create_node_at_end(struct node **old,int *count)//add values at the end of the list
{   
    int counter=1;//counter variable
    int size=1;//to store the size of list
    struct node *fresh;//structure variable used to add node

    //adding nodes
    while(counter)
    {
        printf("Enter the data:");
        fresh=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&fresh->data);
        (*count)++;
        size++;
        fresh->link=NULL;
        (*old)->link=fresh;
        *old=(*old)->link;
        printf("if u want to enter one more value [1-yes/0-no]:");
        scanf("%d",&counter);
    }
    return size;
}

struct node* create_node_at_first(struct node **add,int *count)//add values at the bogining of the list
{
    struct node *fresh;//structure variable for link nodes
    int counter=1;//counter variable

    //linking nodes
    while(counter)
    {
        printf("Enter the data:");
        fresh=malloc(sizeof(struct node));
        scanf("%d",&fresh->data);
        fresh->link=*add;
        (*count)++;
        *add=fresh;
        printf("Want to create an another node [1-yes/0-no]:");
        scanf("%d",&counter);
    }
    return fresh;
}
struct node* reverse(struct node **head)//to reverse linked list
{
    //structure varaiables used to reverse a list
    struct node *current;
    struct node *next=NULL;
    struct node *previous=NULL;
    current=*head;

    //reversing the list
    while(current!=NULL)
    {   
       next=current->link;
       current->link=previous;
       previous=current;
       current=next;
    }
    return previous;
}
int print(struct node **head)//function to display list
{
    //structure variables used to traverse
    struct node *traverse;
    traverse=*head;
    while(traverse!=NULL)
    {
        printf("%d ",traverse->data);
        traverse=traverse->link;
    }
    printf("\n");
    return 1;
}

int insert_at_any(struct node**head,int *count,int place)//function to insert at place
{
    int counter=1;//counter variable
    //structure variable used to insert at position
    struct node *traverse;
    struct node *fresh;
    struct node *next;
    struct node *previous;
    int counter1=1;//another variables

    //inserting the new node
    while(counter1)
    {
        if(place==1)
        {
        fresh=malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&fresh->data);
        fresh->link=*head;
        (*count)++;
        *head=fresh;
        }
        else if(place-(*count)==1)
        {
            traverse=*head;
            while(counter!=*count)
            {
                traverse=traverse->link;
                counter++;
            }
            fresh=malloc(sizeof(struct node));
            printf("Enter the data:");
            scanf("%d",&fresh->data);
            fresh->link=NULL;
            traverse->link=fresh;
            (*count)++;
        }
        else
        {
           traverse=*head;
           counter=1;
            while(counter!=place)
            {
                previous=traverse;
                traverse=traverse->link;
                counter++;
            }
            fresh=malloc(sizeof(struct node));
            printf("Enter the data:");
            scanf("%d",&fresh->data);
            next=traverse;
            previous->link=fresh;
            fresh->link=next;
            (*count)++; 
        }
        printf("countt:%d\n",*count);
        printf("if u want to enter one more value [1-yes/0-no]:");
        scanf("%d",&counter1);
        if(counter1==0)
        {
            return 1;
        }
        printf("insertion place:");
        scanf("%d",&place);
        if(place<=0)
        {
            printf("not posible\n");
            return 1;
        }
        if(place>((*count)+1))
        {
            printf("not posible\n");
            return 1;
        }
    }
}

struct node * delete_node(struct node ** old,int *count,int data)//to delete a node
{
    //structure variables used to deleteting a node
    struct node *traverse;
    struct node *previous;
    struct node *next;
    traverse=*old;

    //deleting a node
    if(traverse->data==data)
    {
      (*count)--;  
      *old=(*old)->link;
      return *old;  
    }
    while(traverse!=NULL&&traverse->data!=data)
    {
        previous=traverse;
        traverse=traverse->link;
    }
    if(traverse==NULL)
    {
        printf("data not found\n");
        return *old;
    }
    previous->link=traverse->link;
    (*count)--;
    return *old; 
}
int insert(struct node **old,int item)//function to insert item in list
{
    //structure variable used to insert
    struct node *fresh;

    //inserting the nodes
    fresh=malloc(sizeof(struct node));
    fresh->data=item;
    fresh->link=NULL;
    (*old)->link=fresh;
    *old=(*old)->link;
}