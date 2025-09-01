/*solution for post fix expression*/

//header file
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>


//node declaration
struct node
{
    float data;
    struct node *address;
};
struct node *stack=NULL;
int push(float value)
{
    struct node *newnode;
    if(stack==NULL)
    {
        stack=(struct node *)malloc(sizeof(struct node));
        stack->data=value;
        stack->address=NULL;
    }
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->address=stack;
        stack=newnode;
    }
    return 0;
}

float pop()
{
    struct node *traverse;
    float value;
    traverse=stack;
    value=stack->data;
    stack=stack->address;
    free(traverse);
    return value;
}
//main function
int main()
{
    char expression[40];
    int counter=0;
    float result;
    int operand1;
    int operand2;
    int flag=1;

    while(flag)
    {
        printf("Enter the expression(in digits):");
        gets(expression);
        counter=0;
        while(expression[counter]!='\0')
        {
            if(isdigit(expression[counter]))
            {
                push(expression[counter]-'0');
            }
            else if(expression[counter]!=32)
            {
                operand2=pop();
                operand1=pop();
                switch(expression[counter])
                {
                    case '+':
                    {
                        result=operand1+operand2;
                        break;
                    }
                    case '-':
                    {
                        result=operand1-operand2;
                        break;
                    }
                    case '/':
                    {
                        result=operand1/operand2;
                        break;
                    }
                    case '*':
                    {
                        result=operand1*operand2;
                        break;
                    }
                    case '%':
                    {
                        result=operand1%operand2;
                        break;
                    }
                    
                }
                push(result);
            }
            counter++;
        }
        result=pop();
        printf("%.2f\n",result); 
        printf("If u want to enter one more expression[1-yes/0-no]:");
        scanf("%d",&flag);
        expression[0]=getchar();
    }   
}