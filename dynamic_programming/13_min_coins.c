/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 13_min_coins.c
 * Created on    : Friday 06 November 2020 09:44:18 PM IST
 * Last modified : Friday 06 November 2020 10:05:45 PM IST
 * Description   : 
 * ***********************************************************************/

#include <stdio.h>
#include <limits.h>

#define INFINITE INT_MAX-1

int min(int a, int b)
{
	return (a < b ? a : b);
}

int min_coins(int sum, int *coins, int  n)
{
	int i, j;
	int t[n+1][sum+1];

	/* initializing */
	for(i = 0; i < n+1; i++){
		for(j = 0; j < sum+1; j++){
			if(j == 0)
				t[i][j] = 0;
			if(i == 0)
				t[i][j] = INFINITE;
		}
	}

	/* initializing second row */
	for(j = 1; j < sum+1; j++){
		if(coins[1] % j == 0)
			t[1][j] = coins[1] / j;
		else
			t[1][j] = INFINITE;
	}	

	for(i = 2; i < n+1; i++){
		for(j = 1; j < sum+1; j++){
			if(coins[i-1] <= j)
				t[i][j] = min(t[i][j-coins[i-1]] + 1, t[i-1][j]);
			else
				t[i][j] = t[i-1][j];
		}
	}
	
	return t[n][sum];
}


int main()
{
	int coins[] = {1, 2, 3, 4, 5, 6};
	int sum = 4;
	int n = sizeof(coins) / sizeof(coins[0]);

	printf("Minimum number of coins: %d\n", min_coins(sum, coins, n));

	return 0;
}


