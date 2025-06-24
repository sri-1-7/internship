//header files
#include<stdio.h>
#include<stdlib.h>

//strcture node
struct node{
        int data;
        struct node *link;
    };
int create_node(struct node **old)//function to create linked list
{   
    int counter=1;
    int size=1;
    struct node *fresh;
    while(counter)
    {
        printf("Enter:");
        fresh=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&fresh->data);
        size++;
        fresh->link=NULL;
        (*old)->link=fresh;
        *old=(*old)->link;
        printf("if u want to enter one more value [1-yes/0-no]:");
        scanf("%d",&counter);
    }
    return size;
}