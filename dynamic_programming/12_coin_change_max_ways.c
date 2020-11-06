/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 12_coin_change_max_ways.c
 * Created on    : Friday 06 November 2020 08:47:44 AM IST
 * Last modified : Friday 06 November 2020 08:59:25 AM IST
 * Description   : 
 * ***********************************************************************/

#include <stdio.h>

/* unbounded knapsack */
int max_ways(int sum, int *coins, int n)
{
	int t[n+1][sum+1];
	int i, j;

	/* initialisation */
	for(i = 0; i < n+1; i++){
		for(j = 0; j < sum+1; j++){
			if(i == 0)
				t[i][j] = 0;
			if(j == 0)
				t[i][j] = 1;
		}
	}

	for(i = 1; i < n+1; i++){
		for(j = 1; j < sum+1; j++){
			if(coins[i-1] <= j){
				t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}

	return t[n][sum];
}

int main()
{	
	int coins[] = {1, 2, 3, 5};
	int sum = 5;
	int n = sizeof(coins) / sizeof(coins[0]);

	printf("Maximum number of ways: %d\n", max_ways(sum, coins, n));

	return 0;
}
