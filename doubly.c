#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int print(struct node **head)//function to display list
{
    struct node *traverse;
    traverse=*head;
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
    int counter=1;
    struct node *fresh;
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

void main()
{
    struct node *head;
    struct node *old;
    int counter;
    head=malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&head->data);
    head->prev=NULL;
    head->next=NULL;
    old=head;
    printf("if u want to enter one more value [1-yes/0-no]:");
    scanf("%d",&counter);
    if(counter==1)
    {
        create_node_at_end(&old);  
    }
    printf("Entered datas:\n");
    print(&head);
}