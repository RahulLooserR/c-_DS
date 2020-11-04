/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 07_min_subset_diff.c
 * Created on    : Wednesday 04 November 2020 08:23:01 PM IST
 * Last modified : Wednesday 04 November 2020 09:26:40 PM IST
 * Description   : 
 * ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* calculate the sum of an array */
int sum_arr(int *arr, int n)
{
	int i, sum = 0;
	for(i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

/* same as subset sum problem
 * storing result in 2d array
 * iterative way
 */
void subset_sum(int sum, int t[][sum+1], int *arr, int n)
{
	/* initialise the dp array */
	int i, j;
	for(i = 0; i < n+1; i++){
		for(j = 0; j < sum+1; j++){
			if(i == 0){
				t[i][j] = FALSE;
			}
			if(j == 0){
				t[i][j] = TRUE;
			}
		}
	}

	for(i = 1; i < n+1; i++){
		for(j = 1; j < sum+1; j++){
			if(arr[i-1] <= j){
				t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
}

int min_subset_sum_diff(int *arr, int n)
{
	int i, node = 0;
	int sum = sum_arr(arr, n);
	int t[n+1][sum+1];

	subset_sum(sum, t, arr, n);

	int k;
	for(k = 0; k < sum+1; k++)
		printf("%d ", t[n][k]);

	printf("\n");

	/* adding all true value of last row of t
	 * into an array pointed by head
	 */
	int *head = malloc(sizeof(int));
	for(i = 0; i < sum+1; i++){
		if(t[n][i] == TRUE){
			node++;
			head = realloc(head, node * sizeof(int));
			head[node-1] = i;
		}
	}
	for(k = 0; k < node - 1; k++)
		printf("%d ", head[k]);

	printf("\n");

	/* s1 + s2  = sum
	 * s2 = sum - s1
	 * s2 - s1 -> sum - s1 -s1 = sum - 2s2
	 */
	return (sum - 2 * head[node/2 - 1]);
}	

int main()
{
	int arr[] = {1, 11, 11, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Minimum difference: %d\n", min_subset_sum_diff(arr, n));

	return 0;
}
