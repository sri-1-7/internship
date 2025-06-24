//header file
#include<stdio.h>
#include<stdlib.h>
int create_node();
struct node
{
    int data;
    struct node *previous;
    struct node *next;
};
struct node *head,*old,*fresh,*finder;//struct and struct variable
int create_node()
{
    int counter=1;
    int size=1;
    while(counter)
    {
        fresh=malloc(sizeof(struct node));
        scanf("%d",&fresh->data);
        size++;
        fresh->previous=old;
        fresh->next=NULL;
        old->next=fresh;
        old=old->next;
        printf("if u want to enter one more value [1-yes/0-no]:");
        scanf("%d",&counter);
    }
    return size;
}
void main()
{
    int counter;//counter variable
    int reverse_index;//to store the reverse index value
    int size;//to store of the list
    printf("enter the elements:");
    head=malloc(sizeof(struct node));
    scanf("%d",&head->data);
    head->previous=NULL;
    head->next=NULL;
    old=head;
    printf("if u want to enter one more value [1-yes/0-no]:");
    scanf("%d",&counter);
    if(counter=1)
    {
    size=create_node();
    }
    //reading the list elements 
    finder=fresh;
    //reading the reverse index value
    printf("enter the index:");
    scanf("%d",& reverse_index);
    if(reverse_index<=0||reverse_index>size)
    {
        printf("-1\n");
        printf("*-1 indicates no index found*\n");
        exit(2);
    }

    //finding and printing the reverse index value;
    counter=1;
    while(counter!=reverse_index)
    {
       finder=finder->previous;
       counter++;
    }
    printf("value:%d\n",finder->data);
}
