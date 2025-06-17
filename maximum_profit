//to find  the maximum profit

//header file
#include <stdio.h>

//main function
void main()
{
	int array[]={2,4,3,8,3,1,4};//array definition
	int profit=0;//to store profit
	int counter1,counter2;//counter variable
	int sell_day;//to store the selling day
	int buy_day;//to store the buy day;

  //printing the datas
  for(counter1=0;counter<7;counter++)
  {
    printf("%d ",array[counter1]);
  }
  printf("%d ",array[counter1]);
	//finding the profit
	for(counter1=0;counter1<7;counter1++)
	{
		for(counter2=counter1+1;counter2<7;counter2++)
		{
			
			if(profit<array[counter2]-array[counter1])
			{
				profit=array[counter2]-array[counter1];
				sell_day=counter2;
				buy_day=counter1;
			}
		}
	}
	
	//printing the profit details
	printf("maximun profit: %d\nbuy date:%d\nsell day:%d\n",profit,buy_day+1,sell_day+1);
	getch();
}
