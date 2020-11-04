/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 05_equal_sum_partition.c
 * Created on    : Wednesday 04 November 2020 08:12:47 AM IST
 * Last modified : Wednesday 04 November 2020 08:32:10 AM IST
 * Description   : 
 * ***********************************************************************/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

/* same definition as subset sum problem in 4 */
int equal_partition(int sum, int *arr, int n)
{
	if(sum == 0)
		return TRUE;
	if(n == 0 && sum >= 0)
		return FALSE;

	if(arr[n-1] <= sum){
		return (equal_partition(sum - arr[n-1], arr, n-1) || equal_partition(sum, arr, n-1));
	}
	else
		return equal_partition(sum, arr, n-1);
}

int sum (int *arr, int n)
{
	int i, sum = 0;
	for(i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

int equal_sum_partition(int *arr, int n)
{
	int total = sum(arr, n);
	if(total % 2 != 0)
		return FALSE;
	printf("total: %d\n", total);
	return equal_partition(total/2, arr, n);
}

int main()
{
	int arr[] = {1, 6, 13, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Possible: %d\n", equal_sum_partition(arr, n));
	return 0;
}
