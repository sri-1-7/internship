/*infix to postfix & prefixusing stack*/

//header file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//node structure
struct node
{
    char data;              //data part 
    struct node *address;   //address part
};
struct node *stack=NULL;

//function declaration
int push(char symbol);                              //for push operation
char pop();                                         //for pop operation
int priorityof(char symbol);                        //for check the priority
int rev(char *expression,char *pre_string);         //for reverse purpose
int postfix(char * expression,char *target_string); //for postfix conversion

//function definition
int push(char symbol)
{
    struct node *newnode;   //to create newnode

    //creating a node
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
    struct node *traverse;  //for delete operation
    char symbol;            //to store poped data

    traverse=stack;
    symbol=traverse->data;
    stack=stack->address;
    free(traverse);
    return symbol;
}


int priorityof(char symbol)
{
    if(symbol=='/'||symbol=='%'||symbol=='*')
        return 1;
    else
        return 0;
}


int rev(char *expression,char *pre_string)
{
    int counter1=0; //counter variable

    strcpy(pre_string,strrev(expression));  //copying the reverse string

    //converting ( to ) and vice versa
    while(pre_string[counter1]=='\0')
    {
        if(pre_string[counter1]=='(')
        {
            pre_string[counter1]=')';
        }
        else if(pre_string[counter1]==')')
        {
            pre_string[counter1]='(';
        }
        counter1++;
    }
    return 0;
}
int postfix(char * expression,char *target_string)
{
   //counter variables
    int counter1=0;
    int counter2=0;

    //converting into post fix
    while(expression[counter1]!='\0')
        {
            if(expression[counter1]=='(')
            {
                push(expression[counter1]);
                counter1++;
            }
            else if(expression[counter1]==')')
            {
                if(stack==NULL)
                {
                    printf("invalid expression\n");
                    exit(1);
                }
                else 
                {
                    while(stack!=NULL&&stack->data!='(')
                    {
                        target_string[counter2]=pop();
                        counter2++;
                    }
                }
                pop();
                counter1++;
            }
            else if(isalpha(expression[counter1])||isdigit(expression[counter1]))
            {
                target_string[counter2]=expression[counter1];
                counter1++;
                counter2++;
            }
            else if(expression[counter1]=='+'||expression[counter1]=='*'||expression[counter1]=='%'||expression[counter1]=='/'||expression[counter1]=='-')
            {
                while(stack!=NULL&&stack->data!='('&&priorityof(stack->data)>priorityof(expression[counter1]))
                {
                    target_string[counter2]=pop();
                    counter2++;
                }
                push(expression[counter1]);
                counter1++;
            }
            else
            {
                printf("invalid string\n");
                exit(1);
            }
        }
        while(stack!=NULL&&stack->data!='(')
        {
            target_string[counter2]=pop();
            counter2++;
        }
        target_string[counter2]='\0';
        return 0;
}

//main function
int main()
{
    char expression[10];        //to store expression
    char post_string[10];       //to store the postfix string
    char rev_string[10];        //to store rev string for prefix oconversion
    char pre_string[10];        //to store prefix string
    int flag=1;                 //flag variable
    
    //conversion takes here
    while(flag)
    {   
        //reading the expression
        printf("Enter the expression:");
        scanf("%s",expression);

        //into post fix
        postfix(expression,post_string);
        printf("The postfix expression is %s\n",post_string);

        //into prefix
        rev(expression,rev_string);
        postfix(rev_string,pre_string);
        strcpy(pre_string,strrev(pre_string));
        printf("The prefix expression is %s\n",pre_string);
        
        printf("If u want to enter one more expression[1-yes/0-n0]:");
        scanf("%d",&flag);
    }
    return 0;
}