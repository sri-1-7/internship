//sell on differ days and buy also

//header file
#include <stdio.h>

//main function
int main() {
    
    int prices[] = {100, 180, 260, 310, 40, 535, 695};//array storing the prices
    int size = sizeof(prices) / sizeof(prices[0]);//size of array 
    int counter = 0;//counter variable
    int profit = 0;//to store profit
    
    //finding the profit
    while (counter< size - 1) 
    {
        while ( prices[counter + 1] <= prices[counter]) 
        {
            counter++;
        }
        if (counter == size- 1) 
        {
            break;
        }
        int buy = prices[counter++];  
        while (counter< size && prices[counter] >buy) {
            counter++;
        }
        int sell = prices[counter- 1]; 

        profit += sell - buy;
        printf("Buy at %d, Sell at %d, Profit: %d\n", buy, sell, sell-buy);
    }

    printf("Total Profit: %d\n", profit);
    return 0;
}
