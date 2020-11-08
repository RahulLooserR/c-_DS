/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 23_print_scs.cpp
 * Created on    : Sunday 08 November 2020 05:17:42 PM IST
 * Last modified : 
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return (a > b ? a : b);
}

void printSCS(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    int t[l1+1][l2+2];

    /* initialization */
    for(int i  =  0; i < l1+1; i++){
        for(int j = 0; j < l2+1; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }

    /* lcs */
    for(int i = 1; i < l1+1; i++){
        for(int j = 0; j < l2+1; j++){
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    /* printing shortest common supersequence */
    string s = "";
    while(l1 > 0 && l2 > 0){
        if(s1[l1-1] == s2[l2-1]){
            s.push_back(s1[l1-1]);
            l1--;
            l2--;
        }
        else{
            if(t[l1-1][l2] > t[l1][l2-1]){
                s.push_back(s1[l1-1]);
                l1--;
            }
            else{
                s.push_back(s1[l2-1]);
                l2--;
            }
        }
    }

    /* filling the remaining string 
     * if l1 > l2
     * if l1 < l2
     */
    while(l1 > l2){
        s.push_back(s1[l1-1]);
        l1--;
    } 
    while(l1 < l2){
        s.push_back(s2[l2-1]);
        l2--;
    }

    reverse(s.begin(), s.end());
    cout << "Shortest supersequence: " << s << endl;
}

int main()
{
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    printSCS(s1, s2);

    return 0;
}