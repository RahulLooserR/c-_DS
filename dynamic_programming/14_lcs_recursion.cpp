/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 14_lcs_recursion.cpp
 * Created on    : Saturday 07 November 2020 08:29:13 AM IST
 * Last modified : 
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <string>

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

    /* if last character of both string matches
        then call lcs on lower input, l1-1, l2-1
     */
    if(s1[l1-1] == s2[l2-1]){
        return 1 + lcs(s1, s2, l1-1, l2-1);
    }

    /* if not matches then call max of
        l1, l2-1 and l1-1, l2
    */
    else{
        return max(lcs(s1, s2, l1, l2-1), lcs(s1, s2, l1-1, l2));
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
    cout << "Longest common subsequence: " << lcs(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}
