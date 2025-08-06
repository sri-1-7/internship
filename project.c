//header file
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define TIME_TO_LIVE 10
//node structure
struct node 
{
    char *Token_name;
    time_t Created_time;
    time_t Expiry_time;
    int Renew_count;
    struct node *link;
};
typedef struct node node;

node *head=NULL;

//function declaration
int generate_token(char *token_name);
int print_token_details(node** details);
int delete_token();
int renew_token(char *token_name);

//function definition
int generate_token(char *token_name)
{
    node *traverse;
    node *last_node;
    node *newnode;
    int flag=0;
    if(head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        head->Token_name=(char *)malloc(strlen(token_name));
        strcpy(head->Token_name,token_name);
        head->Created_time=time(NULL);
        head->Expiry_time=head->Created_time+TIME_TO_LIVE;
        head->Renew_count=0;
        head->link=NULL;
        print_token_details(&head);
    }
    else
    {
        traverse=head;
        while(traverse!=NULL)
        {
            if(strcmp(token_name,traverse->Token_name)!=0)
            {
                if(traverse->Expiry_time<time(NULL))
                {
                    flag=0;
                }
                last_node=traverse;
                traverse=traverse->link;
            }  
            else
            {
               if(traverse->Expiry_time<time(NULL))
                {
                    flag=0;
                    last_node=traverse;
                    traverse=traverse->link;
                } 
                else
                {
                    printf("Token name is already exist try another\n");
                    return 1;
                }
            } 
        }
        newnode=(node*)malloc(sizeof(node));
        newnode->Token_name=(char *)malloc(strlen(token_name));
        strcpy(newnode->Token_name,token_name);
        newnode->Created_time=time(NULL);
        newnode->Expiry_time=newnode->Created_time+TIME_TO_LIVE;
        newnode->Renew_count=0;
        last_node->link=newnode;
        newnode->link=NULL;
        print_token_details(&newnode);
        if(flag==0)
        {
            delete_token();
        }
        return 1;
    }
}

int print_token_details(node** details)
{
    printf("\nToken name:%s\n",(*details)->Token_name);
    printf("created time:%s",ctime(&(*details)->Created_time));
    printf("Expiry time:%s\n",ctime(&(*details)->Expiry_time));
    printf("Renew count:%d\n",(*details)->Renew_count);
}

int delete_token()
{
    node *traverse;
    node *previous;
    traverse=head;
    while(traverse!=NULL)
    {
        if(traverse->Expiry_time<time(NULL))
        {
            if(traverse==head)
            {
                head=head->link;
                free(traverse->Token_name);
                free(traverse);
                traverse=head;
            }
            else
            {
                previous->link=traverse->link;
                free(traverse->Token_name);
                free(traverse);
                traverse=previous->link;
            }
        }
        else
        {    
            previous=traverse;
            traverse=traverse->link;
        }
    }
    return 1;
}

int renew_token(char *token_name)
{
    node *traverse;
    time_t current_time;
    int flag=0;
    traverse=head;

    while(traverse!=NULL)
    {
        if(strcmp(traverse->Token_name,token_name)!=0)
        {
            if(traverse->Expiry_time<time(NULL))
            {
                flag=1;
            }
            traverse=traverse->link;

        }
        else
        {
           if(traverse->Expiry_time<time(NULL))
            {
                flag=1;
            }
            else
            {
                current_time=time(NULL);
                printf("\nToken is renewed at %s",ctime(&current_time));
                traverse->Expiry_time=traverse->Expiry_time+TIME_TO_LIVE;
                traverse->Renew_count++;
                print_token_details(&traverse);
                return 1;
            } 
        }
    }
    current_time=time(NULL);
    printf("\n%s\ntoken name is not  exist \n",ctime(&current_time));
    if(flag==1)
    {
        delete_token();
    }
    return 1;
}


//main function
void main()
{
    int choice;
    char token_name[10];
    printf("MENU:\n1.Generate token.\n2.Renew token.\n3.Display active token details\n4.exit.\n");
    while(1)
    {
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the token name:");
                scanf("%s",token_name);
                generate_token(token_name);
                break;
            }
            case 2:
            {
                printf("Enter the token name:");
                scanf("%s",token_name);
                renew_token(token_name);
                break;   
            }
            case 3:
            {

            }
            case 4:
            {
                exit(1);
            }
            default:
            {
                printf("out of the choice\n");
            }
        }
    }
}