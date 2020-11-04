/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 01_knapsack.c
 * Created on    : Sunday 01 November 2020 09:14:38 PM IST
 * Last modified : Monday 02 November 2020 08:37:56 AM IST
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

void print_matrix(int *matrix, int row, int col)
{
	int i, j;
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
		   printf("%d ", *((matrix+i*row) + j));
		}
 		printf("\n");
	}		

}

int knapsack_itr(int W, int *wt, int *value, int n)
{
	int t[n+1][W+1];
	int i, j;

	/* initialization */
	for(i = 0; i < n+1; i++)
		for(j = 0; j < W+1; j++)
			if(i == 0 || j == 0)
				t[i][j] = 0;

	for(i = 1; i < n+1; i++){
		for(j = 0; j < W+1; j++){
			if(wt[j] < W){
				t[i][j] = max(value[i-1] + t[i-1][W-wt[j]], t[i-1][j]);
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}

//	print_matrix(t, n+1, W+1); 

	return t[n][W];
}

int main()
{
	int weight[] = {10, 20, 30};
	int value[]  = {600, 50, 12};
	int n = sizeof(weight) / sizeof(weight[0]);
	int capacity = 50;
	
	/* we will store dynamic programming result in this array */
	//int solution[n+1][capacity+1];
	memset(solution, -1, sizeof(solution));
	
	printf("maximum profit: %d\n", knapsack(capacity, weight, value, n));
	
	printf("maximum profit: %d\n", knapsack_itr(capacity, weight, value, n));

	// printing dp array
	//print_matrix(solution, n+1, capacity + 1);

	return 0;
}	
