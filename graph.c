/*To draw adjacent matrix for the graph*/

//header file
#include<stdio.h>
#include<stdlib.h>

//main function
void main()
{
    int **Matrix;    //to store matrix
    int No_of_nodes; //to store nodes count
    char *Nodes_name;//to store the nodes name of
    //counter variables
    int counter1;       
    int counter2;


    //reading the no of nodes
    printf("Enter the count of nodes:");
    scanf("%d",&No_of_nodes);

    //allocating the memory for the matrix
    Matrix=(int**)malloc(No_of_nodes*(sizeof(int*)));//for rows
    for(counter1=0;counter1<No_of_nodes;counter1++)
    {
        Matrix[counter1]=(int*)malloc(No_of_nodes*(sizeof(int)));//for columns
    }

    //allocating memory to store nodes name 
    Nodes_name=(char*)malloc((No_of_nodes+1)*sizeof(char));
    //reading the nodes name
    printf("Enter the nodes name(should be in character or in single positive nums):");
    for(counter1=0;counter1<No_of_nodes;counter1++)
    {
        scanf(" %c",&Nodes_name[counter1]);
    }
    
    //reading the matrix
    for(counter1=0;counter1<No_of_nodes;counter1++)
    {
      for(counter2=0;counter2<No_of_nodes;counter2++)
      {
        printf("Links from %c to %c:",Nodes_name[counter1],Nodes_name[counter2]);
        scanf("%d",&Matrix[counter1][counter2]);
      }  
    }

    //printing the Matrix
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
}