#include<stdio.h>
#include<stdlib.h>

struct node
{
    long long int num;
    char name[20];
    struct node *link;
};

//function definition
void create_node(struct node **old)//function to create linked list
{   
    int counter=1;
    struct node *fresh;
    while(counter)
    {
        printf("Enter:\n");
        fresh=malloc(sizeof(struct node));
        printf("name:");
        char ch=getchar();
        gets(fresh->name);
        printf("num:");
        scanf("%lld",&fresh->num);
        fresh->link=NULL;
        (*old)->link=fresh;
        *old=(*old)->link;
        printf("if u want to enter one more value [1-yes/0-no]:");
        scanf("%d",&counter);
    }
}
void main()
{
    struct node *head;
    struct node *old;
    struct node *traverse;
    int counter;
    head=malloc(sizeof(struct node));
    printf("Enter the name:");
    gets(head->name);
    printf("Enter the number:");
    scanf("%lld",&head->num);
    head->link=NULL;
    old=head;
    printf("if u want to enter one more value [1-yes/0-no]:");
    scanf("%d",&counter);
    if(counter=1)
    {
    create_node(&old);
    }
    traverse=head;
    while(traverse!=NULL)
    {
        printf("name:%s\nno:%lld\n",traverse->name,traverse->num);
        traverse=traverse->link;
    }
}