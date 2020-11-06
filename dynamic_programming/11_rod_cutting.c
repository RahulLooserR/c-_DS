/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 11_rod_cutting.c
 * Created on    : Friday 06 November 2020 07:49:35 AM IST
 * Last modified : Friday 06 November 2020 08:39:36 AM IST
 * Description   : 
 * ***********************************************************************/

#include <stdio.h>

int max(int a, int b)
{
	return (a > b ? a : b); 
}

/* unbounded knapsack */
int max_profit(int L, int *len, int *val, int n)
{
	int t[n+1][L+1];
	int i, j;

	/* initiaalization */
	for(i = 0; i < n+1; i++){
		for(j = 0; j < L+1; j++){
			if(i == 0 || j == 0)
				t[i][j] = 0;
		}
	}

	for(i = 1; i < n+1; i++){
		for(j = 1; j < L+1; j++){		
		 /* included -> not processed (can be included again)
		 * not included -> processed (cannot be include again)
	 	 */
			if(len[i-1] <= j){
				t[i][j] = max(val[i-1] + t[i][j-len[i-1]], t[i-1][j]);
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][L];
}

int main()
{
	int len[] = {1, 3, 5, 6, 8};
	int val[] = {1, 4, 7, 7, 14};
	int L = 16;
	int n = sizeof(len) / sizeof(len[0]);

	printf("Max Profit: %d\n", max_profit(L, len, val, n));

	return 0;
}
