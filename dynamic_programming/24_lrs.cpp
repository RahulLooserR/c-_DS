/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 16_lcs_top_down.cpp
 * Created on    : Saturday 07 November 2020 02:55:56 PM IST
 * Last modified : Sunday 08 November 2020 06:46:54 PM IST
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}

/* longest repeating subsequence */
int lrs(string s1)
{
	int l1 = s1.length();
	string s2 = s1;
	int l2 = l1;

	int t[l1+1][l2+1];

	for(int i = 0; i < l1+1; i++){
		for(int j = 0; j < l2+1; j++){
			if(i == 0 || j == 0)
				t[i][j] = 0;
		}
	}

	for(int i = 1; i < l1+1; i++){
		for(int j = 1; j < l2+1; j++){
			/* if i == j, then we are comparing same index*/
			if(s1[i-1] == s2[j-1] && i != j){
				t[i][j] = 1 + t[i-1][j-1];
			}
			else{
				t[i][j] = max(t[i][j-1], t[i-1][j]);
			}
		}
	}
	
	return t[l1][l2];
}

int main()
{
	string s1;

	cout << "Enter the string: ";
	cin >> s1;

	cout << "longest repeating subsequence: " << lrs(s1) << endl;

	return 0;
}
