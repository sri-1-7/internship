#include<stdio.h>
#include<stdlib.h>
void main()
{
    struct node
    {
        int data;
        struct node *previous;
        struct node *next;
    };
    struct node *head,*old,*fresh,*finder;
    int size;
    int counter;
    int reverse_index;
    printf("enter the size:\n");
    scanf("%d",&size);
    if(size<=0)
    {
        exit(1);
    }
    printf("enter the elements:\n");
    head=malloc(sizeof(struct node));
    scanf("%d",&head->data);
    head->previous=NULL;
    head->next=NULL;
    old=head;
    for(counter=0;counter<size-1;counter++)
    {
     fresh=malloc(sizeof(struct node));
     scanf("%d",&fresh->data);
     fresh->previous=old;
     fresh->next=NULL;
     old->next=fresh;
     old=old->next;
    }
    finder=fresh;
    printf("enter the index:");
    scanf("%d",& reverse_index);
    if(counter<=0||counter>size)
    {
        printf("-1\n");
        printf("*-1 indicates no index found*\n");
    }
    counter=1;
    while(counter!=reverse_index)
    {
       finder=finder->previous;
       counter++;
    }
    printf("value:%d\n",finder->data);
}
