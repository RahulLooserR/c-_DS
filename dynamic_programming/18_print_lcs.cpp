/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 18_print_lcs.cpp
 * Created on    : Saturday 07 November 2020 07:06:04 PM IST
 * Last modified : Saturday 07 November 2020 07:23:14 PM IST
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}

void print_lcs(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	string s = "";
	int t[l1+1][l2+1];

	for(int i = 0; i < l1+1; i++){
		for(int j = 0; j < l2+1; j++){
			if(i == 0 || j == 0)
				t[i][j] = 0;
		}
	}

	for(int i = 1; i < l1+1; i++){
		for(int j = 1; j < l2+1; j++){
			if(s1[i-1] == s2[j-1]){
				t[i][j] = 1 + t[i-1][j-1];
			}
			else{
				t[i][j] = max(t[i][j-1], t[i-1][j]);
			}
		}
	}
	cout << "lcs: " << t[l1][l2] << endl;

	while(l1 > 0 && l2 > 0){
		if(s1[l1-1] == s2[l2-1]){
			s.push_back(s1[l1-1]);
			l1--;
			l2--;
		}
		else{
			if(t[l1-1][l2] > t[l1][l2-1])
				l1--;
			else
				l2--;
		}
	}
	reverse(s.begin(), s.end());
	cout << "largest common subsequence: " << s << endl;
}

int main()
{
	string s1, s2;

	cout << "Enter first string: ";
	cin >> s1;
	cout << "Enter second string: ";
	cin >> s2;

	print_lcs(s1, s2);

	return 0;
}
