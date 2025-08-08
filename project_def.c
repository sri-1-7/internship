//header file
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//macro definition
#define TIME_TO_LIVE 60 //defining life time of token

//node structure
struct node 
{
    //data part
    char *Token_name;       //to store token name
    time_t Created_time;    //to store created time
    time_t Expiry_time;     //to store a expiry time
    int Renew_count;        //to store a renew count

    //address part
    struct node *link;      //to store a next node address
};
typedef struct node node;

node *head=NULL;            //setting head to NULL

//function declarations
int generate_token(char *token_name);//to generate token
int print_token_details(node** details);//to print a token details
int delete_token();//to delete token
int renew_token(char *token_name);//to renew token
int display_active_token();//to display active token

//function definitions

//input parameter:token_name
int generate_token(char *token_name)
{
    node *traverse;     //to traverse
    node *last_node;    //to store last node
    node *newnode;      //to create new node
    int flag=0;         //flag variable
    
    //checking if head is NULL then assign data
    if(head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        head->Token_name=(char *)malloc(strlen(token_name)+1);
        strcpy(head->Token_name,token_name);
        head->Created_time=time(NULL);
        head->Expiry_time=head->Created_time+TIME_TO_LIVE;
        head->Renew_count=0;
        head->link=NULL;
        printf("Token generated:\n");
        print_token_details(&head);//printing generated token details
    }

    //else using traverse variable for checking all the nodes if the token name is not exist then creating a node at end
    else
    {
        traverse=head;
        while(traverse!=NULL)
        {
            if(strcmp(token_name,traverse->Token_name)!=0)
            {
                if(traverse->Expiry_time<time(NULL))
                {
                    flag=1;//if token is expired setting flag is one
                }
                last_node=traverse;
                traverse=traverse->link;
            }  
            else
            {
               if(traverse->Expiry_time<time(NULL))
                {
                    flag=1;
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
        // creating newnode and assigning datas
        newnode=(node*)malloc(sizeof(node));
        newnode->Token_name=(char *)malloc(strlen(token_name));
        strcpy(newnode->Token_name,token_name);
        newnode->Created_time=time(NULL);
        newnode->Expiry_time=newnode->Created_time+TIME_TO_LIVE;
        newnode->Renew_count=0;
        last_node->link=newnode;
        newnode->link=NULL;
        printf("Token generated:\n");
        print_token_details(&newnode);
        if(flag==1)
        {
            delete_token();
        }
        return 1;
    }
}
// input parameter:detail
int print_token_details(node** details)
{
   // printing node details
    printf("\nToken name:%s\n",(*details)->Token_name);
    printf("created time:%s",ctime(&(*details)->Created_time));
    printf("Expiry time:%s",ctime(&(*details)->Expiry_time));
    printf("Renew count:%d\n",(*details)->Renew_count);
}
//no input parameter
int delete_token()
{
    node *traverse;//to traverse
    node *previous;//to store previous node address
    traverse=head;
    //deleting process
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
//input parameter:token_name
int renew_token(char *token_name)
{
    node *traverse;      //to traverse
    time_t current_time; //to store current time
    int flag=0;          //set flag variable at zero
    
    traverse=head;

    //renewing process
    while(traverse!=NULL)
    {

        if(strcmp(traverse->Token_name,token_name)!=0)
        {
            if(traverse->Expiry_time<time(NULL))
            {
                flag=1;//if token is expired setting flag is one
            }
            traverse=traverse->link;
        }
        else
        {
           if(traverse->Expiry_time<time(NULL))
            {
                flag=1;
                traverse=traverse->link;
            }
            else
            {
                current_time=time(NULL);
                printf("\nToken is renewed at %s",ctime(&current_time));
                traverse->Expiry_time=traverse->Expiry_time+TIME_TO_LIVE;
                traverse->Renew_count++;//increasing renew count
                print_token_details(&traverse);//printing renewed token details
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

//no input parameter
int display_active_token()
{
    node *traverse;//to traverse
    int flag=0;//flag variable
    int counter=0;//counter variable
    traverse=head;
    while(traverse!=NULL)
    {
        if(traverse->Expiry_time<time(NULL))
        {
            flag=1;//if token is expired setting flag is one
            traverse=traverse->link;
        }
        else
        {
            print_token_details(&traverse);//printing active token details
            traverse=traverse->link;
            counter++;
        }
    }

    if(counter==0)
    {
        printf("no tokens in active now\n");
    }
    else 
    {
        printf("%d token(s) are active now\n",counter);
    }

    if(flag==1)
    {
        delete_token();
    }
    return 1;
}