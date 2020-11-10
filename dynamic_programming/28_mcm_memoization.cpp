/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 27_mcm_recursion.cpp
 * Created on    : Monday 09 November 2020 07:55:29 AM IST
 * Last modified : Monday 09 November 2020 08:16:29 PM IST
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <cstring>  /* memset */

using namespace std;

int t[1001][1001];

int mcm(int *arr, int i, int j)
{
    int min = INT32_MAX;
    if(i >= j){
        return 0;
    }

	if(t[i][j] !=  -1)
		return t[i][j];

    for(int k = i; k < j; k++){
        int temp = mcm(arr, i, k) + mcm(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        if(temp < min){
            min = temp;
        }
    }

    return t[i][j] = min;
}

int main()
{   
    int arr[] = {20, 30, 4, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
	memset(t, -1, sizeof(t));

    cout << "Minimum cost of matrix chain multiplication: " << mcm(arr, 1, n-1) << endl;

    return 0;
}
