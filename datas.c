//header file
#include<stdio.h>
#include<stdlib.h>

struct node
{
    char name[30];
    long long int roll_no;
    int m1;
    int m2;
    int m3;
    int total;
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
        printf("roll no:");
        scanf("%lld",&fresh->roll_no);
        printf("Enter the three marks:");
        scanf("%d%d%d",&fresh->m1,&fresh->m2,&fresh->m3);
        fresh->total=fresh->m1+fresh->m2+fresh->m3;
        fresh->link=NULL;
        (*old)->link=fresh;
        *old=(*old)->link;
        printf("if u want to enter one more value [1-yes/0-no]:");
        scanf("%d",&counter);
    }
}
//main function
void main()
{
    struct node *head,*old,*traverse;
    int counter;
    head=malloc(sizeof(struct node));
    printf("Enter the data\n");
    printf("name:");
    gets(head->name);
    printf("roll no:");
    scanf("%lld",&head->roll_no);
    printf("Enter the three marks:");
    scanf("%d%d%d",&head->m1,&head->m2,&head->m3);
    head->total=head->m1+head->m2+head->m3;
    old=head;
    head->link=NULL;
    printf("if u want to enter one more value [1-yes/0-no]:");
    scanf("%d",&counter);
    if(counter=1)
    {
    create_node(&old);
    }
    printf("Enter datas");
    traverse=head;
    while(traverse!=NULL)
    {
        printf("name:%s\nroll no:%lld\nmark1:%d\nmark2:%d\nmark3:%d\ntotal:%d\n\n",traverse->name,traverse->roll_no,traverse->m1,traverse->m2,traverse->m3,traverse->total);
        traverse=traverse->link;
    }
}