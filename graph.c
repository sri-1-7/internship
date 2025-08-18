/*To draw adjacent matrix for the graph*/

//header file
#include<stdio.h>
#include<stdlib.h>

//function declaration
int input_matrix(int No_of_nodes,int **Matrix,char *Nodes_name);   //to reading matrix
int input_nodes_name(int No_of_nodes,char *Nodes_name);            //to reads nodes name
int display_matrix(char *Nodes_name,int No_of_nodes,int **Matrix); //to display matrix

//function definition

//intput parameter:Nodes_name,No_of_nodes,matrix
int display_matrix(char *Nodes_name,int No_of_nodes,int **Matrix)
{
  //counter variables
  int counter1; 
  int counter2;

  //printing the matrix
  printf("\nNodes\t");
  for(counter1=0;counter1<No_of_nodes;counter1++)
  {
      printf("%c\t",Nodes_name[counter1]);
  }
  printf("\n");
  for(counter1=0;counter1<No_of_nodes;counter1++)
  {
    printf("%c\t",Nodes_name[counter1]);
    for(counter2=0;counter2<No_of_nodes;counter2++)
    {
      printf("%d\t",Matrix[counter1][counter2]);
    }  
    printf("\n");
  }
  return 1;
}

//input parameter:No_of_nodes,Nodes_name
int input_nodes_name(int No_of_nodes,char *Nodes_name)
{
  int counter;//counter name

  //reading nodes name
  printf("Enter the nodes name(should be in character or in single positive nums):");
  for(counter=0;counter<No_of_nodes;counter++)
  {
      scanf(" %c",&Nodes_name[counter]);
  }
  return 1;
}

//input parameter:No_of_nodes,Matrix,nodes_name
int input_matrix(int No_of_nodes,int **Matrix,char *Nodes_name)
{
  //counter variable
  int counter1;
  int counter2;

  //reading matrix
  for(counter1=0;counter1<No_of_nodes;counter1++)
  {
    for(counter2=0;counter2<No_of_nodes;counter2++)
    {
      printf("Links from %c to %c:",Nodes_name[counter1],Nodes_name[counter2]);
      scanf("%d",&Matrix[counter1][counter2]);
    }  
  }
  return 1;
}

//main function
int main()
{
    int **Matrix;    //to store matrix
    int No_of_nodes; //to store nodes count
    char *Nodes_name;//to store the nodes name of
    int counter;    //counter variables


    //reading the no of nodes
    printf("Enter the count of nodes:");
    scanf("%d",&No_of_nodes);

    //allocating the memory for the matrix
    Matrix=(int**)malloc(No_of_nodes*(sizeof(int*)));//for rows
    for(counter=0;counter<No_of_nodes;counter++)
    {
        Matrix[counter]=(int*)malloc(No_of_nodes*(sizeof(int)));//for columns
    }

    //allocating memory to store nodes name 
    Nodes_name=(char*)malloc((No_of_nodes+1)*sizeof(char));
    //reading the nodes name
    
    input_nodes_name(No_of_nodes,Nodes_name);      //to get nodes name
    input_matrix(No_of_nodes,Matrix,Nodes_name);   //to get matrix
    display_matrix(Nodes_name,No_of_nodes,Matrix); //to display matrix
    
    for (counter=0; counter<No_of_nodes;counter++)
    {
      free(Matrix[counter]);
    }
    free(Matrix);
    free(Nodes_name);

    return 1;
}