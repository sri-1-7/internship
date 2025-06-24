//header files
#include<stdio.h>
#include<stdlib.h>

//strcture node
struct node{
        int data;
        struct node *link;
    };
void create_node(struct node **old,struct node **fresh)//function to create linked list
{   
    int counter=1;
    while(counter)
    {
        printf("Enter:");
        *fresh=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&(*fresh)->data);
        (*fresh)->link=NULL;
        (*old)->link=*fresh;
        *old=(*old)->link;
        printf("if u want to enter one more value [1-yes/0-no]:");
        scanf("%d",&counter);
    }
}