/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 14_lcs_recursion.cpp
 * Created on    : Saturday 07 November 2020 08:29:13 AM IST
 * Last modified : Saturday 07 November 2020 12:22:29 PM IST
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <cstring>

int t[1002][1002];

using namespace std;

int max(int a, int b)
{
    return (a > b ? a : b);
}

int lcs(string s1, string s2, int l1, int l2)
{
    if(l1 == 0 || l2 == 0){
        return 0;
    }

	/* checking if solution exists */
	if(t[l1][l2] != -1)
		return t[l1][l2];

    /* if last character of both string matches
        then call lcs on lower input, l1-1, l2-1
     */
    if(s1[l1-1] == s2[l2-1]){
        return t[l1][l2] = 1 + lcs(s1, s2, l1-1, l2-1);
    }

    /* if not matches then call max of
        l1, l2-1 and l1-1, l2
    */
    else{
        return t[l1][l2] =  max(lcs(s1, s2, l1, l2-1), lcs(s1, s2, l1-1, l2));
    }
}

int main()
{
    string s1;
    string s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

	memset(t, -1, sizeof(t));

    cout << "Longest common subsequence: " << lcs(s1, s2, s1.length(), s2.length()) << endl;
	cout << t[s1.length()][s2.length()] << endl;
    return 0;
}
