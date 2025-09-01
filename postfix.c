/*infix to postfix using stack*/

//header file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//node structure
struct node
{
    char data;
    struct node *address;
};
struct node *stack=NULL;

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
int priorityof(char symbol)
{
    if(symbol=='/'||symbol=='%'||symbol=='*')
        return 1;
    else
        return 0;
}
int rev(char *expression,char *pre_string)
{
    int counter1=0;
    strcpy(pre_string,strrev(expression));
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
}
int postfix(char * expression,char *target_string)
{
    int counter1=0;
    int counter2=0;
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
}
int main()
{
    char expression[10];
    printf("Enter the expression:");
    scanf("%s",expression);
    char post_string[10];
    char pre_string[10];
    char target_prestring[10];
    postfix(expression,post_string);
    printf("The postfix expression is %s\n",post_string);
    rev(expression,pre_string);
    postfix(pre_string,target_prestring);
    strcpy(target_prestring,strrev(target_prestring));
    printf("The prefix expression is %s\n",target_prestring);
}