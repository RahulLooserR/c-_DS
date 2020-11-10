/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 27_mcm_recursion.cpp
 * Created on    : Monday 09 November 2020 07:55:29 AM IST
 * Last modified : 
 * Description   : 
 * ***********************************************************************/

#include <iostream>

using namespace std;

int mcm(int *arr, int i, int j)
{
    int min = INT32_MAX;
    if(i >= j){
        return 0;
    }

    for(int k = i; k < j; k++){
        int temp = mcm(arr, i, k) + mcm(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        if(temp < min){
            min = temp;
        }
    }

    return min;
}

int main()
{   
    int arr[] = {20, 30, 4, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum cost of matrix chain multiplication: " << mcm(arr, 1, n-1) << endl;

    return 0;
}