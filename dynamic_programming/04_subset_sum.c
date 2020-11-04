/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 04_sum_of_elements.c
 * Created on    : Tuesday 03 November 2020 10:17:30 PM IST
 * Last modified : Wednesday 04 November 2020 07:55:20 AM IST
 * Description   : print if array contains the elements whose sum
 * 				   is equal to x. (output should be yes or no)
 * ***********************************************************************/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isSum_recursion (int sum, int *arr, int n)
{
	if(sum == 0){
		return TRUE;
	}
	if(n == 0 && sum > 0){
		return FALSE;
	}


	if(arr[n-1] <= sum){
		return (isSum_recursion(sum - arr[n-1], arr, n-1) || isSum_recursion(sum, arr, n-1));
	}
	else{
		return isSum_recursion(sum, arr, n-1);
	}
}	

int isSum_iteration(int sum, int *arr, int n)
{
	int t[n+1][sum+1];
	int i, j;

	/* initailisation */
	for(i = 0; i < n+1; i++){
		for(j = 0; j < sum+1; j++){
			if(i == 0)
				t[i][j] = FALSE;
			if(j == 0)
				t[i][j] = TRUE;
		}
	}

	for(i = 1; i < n+1; i++){
		for(j = 1; j < sum+1; j++){
			if(arr[i-1] <= j){
				t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
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
	int sum = 35;
	int arr[] = {2, 8, 3, 11, 9};
	int n = sizeof(arr) / sizeof(arr[0]);


	printf("possible: %d\n", isSum_recursion(sum, arr, n));
	printf("possible: %d\n", isSum_iteration(sum, arr, n));

	return 0;
}
