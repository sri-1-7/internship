//header file
#include<stdio.h>
#include<stdlib.h>

//structure definition
struct node
{
    int data;//to store data
    struct node *next;//to point next location
    struct node *prev;//to point previous location
};


int print(struct node **head)//function to display list
{
    struct node *traverse;//structure variable use to traverse
    traverse=*head;
    int counter;
    printf("if u want to print in reverse order [1-yes/0-no]:");
    scanf("%d",&counter);
    if(counter==1)
    {
        while(traverse->next!=NULL)
        {
           traverse=traverse->next;
        }
        printf("The list is :\n");
        while(traverse->prev!=NULL)
        {
            printf("%d ",traverse->data);
            traverse=traverse->prev;
        }
    return 1;
    }
    //printing the datas of the list
    printf("The list is:\n");
    while(traverse!=NULL)
    {
        printf("%d ",traverse->data);
        traverse=traverse->next;
    }
    printf("\n");
    return 1;
}


int create_node_at_end(struct node **old,int *count)//add values at the end of the list
{   
    int counter=1;//counter variable
    struct node *fresh;//structure variable used to add data
    struct node *traverse=*old;
    
    
    if((*count)!=1)
    {
        while(traverse->next!=NULL)
        {

            traverse=traverse->next;
        }
    }
    //linking nodes and reading data for each nodes
    while(counter)
    {
        printf("Enter the data:");
        fresh=(struct node *)malloc(sizeof(struct node));
        (*count)++;
        scanf("%d",&fresh->data);
        fresh->prev=traverse;
        fresh->next=NULL;
        traverse->next=fresh;
        traverse=traverse->next;
        printf("if u want to enter one more value [1-yes/0-no]:");
        scanf("%d",&counter);
    }
    return 1;
}


struct node* creating_at_begining(struct node **old,int *count)//add nodes at begining
{
    int counter=1;//counter variables
    struct node *fresh;//used to add data at begining
    while(counter)
    {
        fresh=malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&fresh->data);
        (*count)++;
        fresh->prev=NULL;
        (*old)->prev=fresh;
        fresh->next=(*old);
        (*old)=(*old)->prev;
        printf("if u want add another data at begining [1-yes/0-no]:");
        scanf("%d",&counter);
    }
    return fresh;
}


struct node* delete_a_node(struct node **old,int *count)
{
    struct node *traverse;//struct variable to traverse
    int counter=1;
    int data;
    while(counter)
    {
        traverse=*old;
        printf("Enter the data:");
        scanf("%d",&data);
        if(data==traverse->data)
        {
            if(traverse->next!=NULL)
            {
                traverse->next->prev=NULL;
            }
            (*old)=(*old)->next;
        }
        else
        {
            while(traverse!=NULL&&traverse->data!=data)
            {
                traverse=traverse->next;
            }
            if(traverse==NULL)
            {   
            printf("data not found\n");
            return *old;
            }
            traverse->prev->next=traverse->next;
            if (traverse->next!=NULL)
            {
                traverse->next->prev=traverse->prev;
            }
        }
        (*count)--;
        if((*count)==0)
        {
            printf("now no data is in the list\n");
            return *old;
        }
        printf("if u want to delete another data[1-yes/0-no]:");
        scanf("%d",&counter);
    }
        return *old;
}

struct node* insert_at_pos(struct node **old,int *count)
{
    int counter1=1;
    struct node *traverse;
    struct node *fresh;
    int place;
    int counter2;
    while(counter1)
    {
        printf("Enter the position:");
        scanf("%d",&place);
        if(place<=0||place>(*count)+1)
        {
            printf("not possible\n");
            return *old;
        }
        else if(place==1)
        {
            fresh=malloc(sizeof(struct node));
            printf("Enter the data:");
            scanf("%d",&fresh->data);
            fresh->prev=NULL;
            fresh->next=*old;
            (*old)->prev=fresh;
            *old=(*old)->prev;
            (*count)++;
        }
        else if(place==*(count)+1)
        {
            traverse=*old;
            while(traverse->next!=NULL)
            {
                traverse=traverse->next;
            }
            fresh=malloc(sizeof(struct node));
            printf("Enter the data:");
            scanf("%d",&fresh->data);
            (*count)++;
            fresh->next=NULL;
            fresh->prev=traverse;
            traverse->next=fresh;
        }
        else
        {
            traverse=*old;
            counter2=1;
            while((place-1)!=counter2)
            {
                traverse=traverse->next;
                counter2++;
            }
            fresh=malloc(sizeof(struct node));
            printf("Enter the data:");
            scanf("%d",&fresh->data);
            (*count++);
            fresh->prev=traverse;
            fresh->next=traverse->next;
            traverse->next=fresh;
        }
        printf("if u want to insert another data[1-yes/0-no]:");
        scanf("%d",&counter1);
    }    
    return *old;
}

struct node* reverse(struct node **old)
{
    struct node *traverse;
    traverse=*old;
    while(traverse->next!=NULL)
    {
        traverse=traverse->next;
    }
    while(traverse->prev!=NULL)
    {
        traverse=traverse->prev;
    }
    return traverse;
}