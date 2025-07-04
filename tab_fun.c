//header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure definition
struct node
{
    char *data;
    struct node *prev;
    struct node *next;
};

//function to create homepage
//input parameter:hompage
struct node* homepage_create(char *homepage)
{
    struct node *head;//structure variable used to create node

    //creating a node
    head=malloc(sizeof(struct node));
    head->data=malloc(strlen(homepage)+1);
    strcpy(head->data,homepage);
    head->prev=NULL;
    head->next=NULL;

    return head;//returning the created node
}


//fuction to visit anothe tab
//input parameter:obj,tab
struct node* visit(struct node **obj,char *tab)
{   
    struct node *fresh;//structure variable used to create node

    //printing the current tab and visited tab
    printf("you are currently in %s and visit %s\n",(*obj)->data,tab);
    
    //creating a node and linking with existing node
    fresh=malloc(sizeof(struct node));
    fresh->data=malloc(strlen(tab)+1);
    strcpy(fresh->data,tab);
    fresh->prev=*obj;
    fresh->next=NULL;
    (*obj)->next=fresh;

    return fresh;//returning the created node
}

//function to go back from tab by nth steps
//input parameter:obj,steps
struct node* back(struct node **obj,int steps)
{
    int counter=1;//counter variable
    struct node *traverse;//structure variable used to traverse
    
    //traversing by nth steps back
    traverse=*obj;
    if(traverse->prev==NULL)
    {
        printf("you cannot go back\n");
        return *obj;
    }
    while(counter-1!=steps&&traverse->prev!=NULL)
    {
        traverse=traverse->prev;
        counter++;
    }

    //printing the info from where we back and now where we are
    printf("from %s u back %d no u r in %s\n",(*obj)->data,counter-1,traverse->data);
    
    return traverse;//return the current node 
}

//function to go back from tab by nth steps
//input parameter:obj,steps
struct node *forward(struct node **obj,int steps)
{
    struct node *traverse;//structure variable used to traverse
    int counter=1;//counter variable
    
    //traversing by nth steps forward
    traverse=*obj;
    if(traverse->next==NULL)
    {
        printf("you cannot go forward\n");
        return *obj;
    }
    while(counter-1!=steps&&traverse->next!=NULL)
    {
        traverse=traverse->next;
        counter++;
    }

    //printing the info from where we back and now where we are
    printf("from %s u forward %d no u r in %s\n",(*obj)->data,counter-1,traverse->data);
   
    return traverse;//return the current position
}