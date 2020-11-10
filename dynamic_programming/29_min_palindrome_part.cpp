/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 29_min_palindrome_part.cpp
 * Created on    : Tuesday 10 November 2020 07:00:19 AM IST
 * Last modified : 
 * Description   : 
 * ***********************************************************************/

#include <iostream>

using namespace std;

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
    int min = INT32_MAX - 1;

    for(int k = i; k < j; k++){
        int temp = minPartition(s, i, k) + minPartition(s, k+1, j) + 1;

        if(temp < min){
            min = temp;
        }
    }
    return min;
}


int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << minPartition(s, 0, s.length() - 1) << endl;

    return 0;
}