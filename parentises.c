/*stack to check parenthesis*/

//header file
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//macro definition
#define TRUE 1

//node declaration
struct node
{
    char data;
    struct node *address;
};
struct node *stack=NULL;

//function definition
int push(char symbol);  //push operation
int pop();              //pop operation

//function declaration
int push(char symbol)
{
    struct node *newnode;
    if(stack==NULL)
    {
        stack=(struct node *)malloc(sizeof(struct node));
        stack->data=symbol;
        stack->address=NULL;
    }
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=symbol;
        newnode->address=stack;
        stack=newnode;   
    }
    return 0;
}
char pop()
{
    struct node *traverse;
    char symbol;
    traverse=stack;
    symbol=traverse->data;
    stack=stack->address;
    free(traverse);
    return symbol;
}

//main function
int main()
{
    char expression[10];   //to store expression
    int counter;           //counter variable
    int length;            //to store length of the expression
    int flag=1;            //flag variable
    char previous;         //to store last poped simple
    
    //reading the expression
    printf("Enter the expression:");
    scanf("%s",expression);

    //storing the length
    length=strlen(expression);

    //finding the valid expression
    for(counter=0;counter<length;counter++)
    {
        if(expression[counter]=='('||expression[counter]=='{'||expression[counter]=='[')
        {
            push(expression[counter]);
        }
        else if(expression[counter]==')'||expression[counter]=='}'||expression[counter]==']')
        {
            if(stack==NULL)
            {
                flag=0;
            }
            else
            {
                previous=pop();
                if(previous=='('&&(expression[counter]=='}'||expression[counter]==']'))
                {
                    flag=0;
                }
                else if(previous=='{'&&(expression[counter]==']'||expression[counter]==')'))
                {
                   flag=0;
                }
                else if(previous=='['&&(expression[counter]=='}'||expression[counter]==')'))
                {
                    flag=0;
                }
            }
            }
            if(flag==0)
            {
                printf("Invalid pair or braces");
                return 1;
            }
        }
    printf("valid\n");
    printf("If u want to continue[1]:");
    scanf("%d",&counter);
    return 0;    
}