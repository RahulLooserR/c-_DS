/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 29_min_palindrome_part.cpp
 * Created on    : Tuesday 10 November 2020 07:00:19 AM IST
 * Last modified : 
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <cstring> /* memset */

using namespace std;

int t[1001][1001];

bool isPalindrome(string s, int i, int j)
{
    if(i >= j){
        return true;
    }
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minPartition(string s, int i, int j)
{
    /* base condition */
    if(i >= j){
        return 0;   /* minimum number of partion required for 1  or 0 element */
    }
    if(isPalindrome(s, i, j)){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int min =  - 1;

    for(int k = i; k < j; k++){
        //int temp = minPartition(s, i, k) + minPartition(s, k+1, j) + 1;
        int left, right;
        if(t[i][k] !=  -1){
            left = t[i][k];
        }
        else{
            left = minPartition(s, i, k);
            t[i][k] = left;
        }
        if(t[k+1][j] != -1){
            right = t[k+1][j];
        }
        else{
            right = minPartition(s, k+1, j);
            t[k+1][j] = right;
        }
        int temp = left + right + 1;
        if(temp < min){
            min = temp;
        }
    }
    return min;
}


int main()
{
    string s;
    memset(t, -1, sizeof(t));
    cout << "Enter the string: ";
    cin >> s;
    cout << minPartition(s, 0, s.length() - 1) << endl;

    return 0;
}