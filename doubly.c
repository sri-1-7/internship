//header file
#include<stdio.h>
#include<stdlib.h>

//structure definition
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int print(struct node **head)//function to display list
{
    struct node *traverse;//structure variable use to traverse
    traverse=*head;

    //printing the datas of the list
    while(traverse!=NULL)
    {
        printf("%d ",traverse->data);
        traverse=traverse->next;
    }
    printf("\n");
    return 1;
}
int create_node_at_end(struct node **old)//add values at the end of the list
{   
    int counter=1;//counter variable
    struct node *fresh;//structure variable used to add data

    //adding nodes
    while(counter)
    {
        printf("Enter the data:");
        fresh=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&fresh->data);
        fresh->prev=(*old);
        fresh->next=NULL;
        (*old)->next=fresh;
        *old=(*old)->next;
        printf("if u want to enter one more value [1-yes/0-no]:");
        scanf("%d",&counter);
    }
    return 1;
}

//main function
void main()
{
    //structure variables
    struct node *head;
    struct node *old;
    int counter;//counter variable

    //reading the head data
    head=malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&head->data);
    head->prev=NULL;
    head->next=NULL;

    //reading the next values
    old=head;
    printf("if u want to enter one more value [1-yes/0-no]:");
    scanf("%d",&counter);
    if(counter==1)
    {
        create_node_at_end(&old);  
    }

    //printing the datas
    printf("Entered datas:\n");
    print(&head);
}