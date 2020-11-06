/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 08_count_subset_diff.c
 * Created on    : Thursday 05 November 2020 07:18:58 AM IST
 * Last modified : Thursday 05 November 2020 08:44:25 AM IST
 * Description   : 
 * ***********************************************************************/

#include <stdio.h>

int count_subset(int sum, int *arr, int n)
{
	printf("sum calue: %d\n", sum);
	int t[n+1][sum+1];
	int i, j;

	/* initialize t array */
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
			if(arr[i -1] <= j){
				t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	for(i = 0; i < n+1; i++){
		for(j = 0; j < sum+1; j++){
			printf("%d ", t[i][j]);
		}
		printf("\n");
	}	
	return t[n][sum];
}

int sum_arr(int *arr, int n)
{
	int i, total = 0;
	for(i = 0; i < n; i++)
		total += arr[i];
	return total;
}

int target_sum(int sum, int *arr, int n)
{
	/* s2 - s1 = diff
	 * s2 + s1 = sum
	 * 2s2 = sum + diff
	 * s2 = (sum + diff) / 2
	 * then count the subset whose sum is (sum + diff) / 2
	 */
	return count_subset((sum_arr(arr, n) + sum) / 2, arr, n);
}

int main()
{
	int arr[] = {6, 1, 3, 4, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 4;

	printf("Number of subsets with difference %d : %d\n", sum, target_sum(sum, arr, n));

	return 0;
}
