/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 06_count_subset.c
 * Created on    : Wednesday 04 November 2020 08:54:07 AM IST
 * Last modified : Wednesday 04 November 2020 09:26:15 AM IST
 * Description   : 
 * ***********************************************************************/

#include <stdio.h>

int isSum_iteration(int sum, int *arr, int n)
{
    int t[n+1][sum+1];
    int i, j;

    /* initailisation */
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
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

int isSum_recursion (int sum, int *arr, int n)
{
    if(sum == 0){
        return 1;
    }
    if(n == 0 && sum > 0){
        return 0;
    }


    if(arr[n-1] <= sum){
        return (isSum_recursion(sum - arr[n-1], arr, n-1) + isSum_recursion(sum, arr, n-1));
    }
    else{
        return isSum_recursion(sum, arr, n-1);
    }
}

int main()
{
    int sum = 10;
    int arr[] = {2, 8, 3, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);


    printf("possible: %d\n", isSum_recursion(sum, arr, n));
    printf("possible: %d\n", isSum_iteration(sum, arr, n));

    return 0;
}

