/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 01_knapsack.c
 * Created on    : Sunday 01 November 2020 09:14:38 PM IST
 * Last modified : Sunday 01 November 2020 10:39:12 PM IST
 * Description   : solving knapsack problem with recursion using 
 * 				   memoisation, this includes storing all the possible
 * 				   solution in the matrix 
 * ***********************************************************************/

#include <stdio.h>
#include <string.h> /* memset */


int solution[100][100];

/* return maximum of two number */
int max(int a, int b)
{
	return((a > b) ? a : b);
}

/* knapsack function definition */
int knapsack(int capacity, int *weight, int *value, int n)
{
	/* Base condition */
	if(capacity == 0 || n == 0){
		return 0;
	}

	/* if solution exists, return the solution */
	if(solution[n][capacity] != -1){
		return solution[n][capacity];
	}
	
	/* if given weight(last index) is less than capacity
	 * include it into solution and calculate maximum of 
	 * including or not including the weight
	 *
	 * if weight is included then capacity will decrease
	 * if weight is not included capacity will remain same
	 *
	 * store the value and return
	 */
	if(weight[n-1] <= capacity){
		return solution[n][capacity] = max(value[n-1] + knapsack(capacity - weight[n-1], weight, value, n - 1), knapsack(capacity, weight, value, n - 1));
	}

	/* weight is greater than capacity then don't
	 * include in the solution
	 */
	else{
		return solution[n][capacity] = knapsack(capacity, weight, value, n - 1);
	}

}

int main()
{
	int weight[] = {10, 20, 30};
	int value[]  = {600, 100, 120};
	int n = sizeof(weight) / sizeof(weight[0]);
	int capacity = 50;
	
	/* we will store dynamic programming result in this array */
	//int solution[n+1][capacity+1];
	memset(solution, -1, sizeof(solution));
	
	printf("maximum profit: %d\n", knapsack(capacity, weight, value, n));
	
	// printing dp array
	int i, j;
	for(i = 0; i < n+1; i++){
		for(j = 0; j < capacity+1; j++){
		   printf("%d ", solution[i][j]);
		}
 		printf("\n");
	}		
	return 0;
}	
