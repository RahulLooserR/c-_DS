/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 31_eval_expr_true.cpp
 * Created on    : Wednesday 11 November 2020 08:21:05 AM IST
 * Last modified : 
 * Description   : 
 * ***********************************************************************/

#include <iostream>

using namespace std;

int countWays(string s, int i, int j, bool isTrue)
{
    /* Base condition */
    if(i > j){
        return false;
    }
    if(i ==  j){
        if(isTrue == true){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }

    int ways = 0;

    for(int k = i+1; k < j; k+=2){
        int lTrue = countWays(s, i, k-1, true);
        int lFalse = countWays(s, i, k-1, false);
        int rTrue = countWays(s, k+1, j, true);
        int rFalse = countWays(s, k+1, j, false);

        switch (s[k])
        {
        case '|':
                if(isTrue == true){
                    ways += lFalse * rTrue + lTrue * rFalse + lTrue * rTrue;
                }
                else{
                    ways += lTrue * rTrue;
                }
            break;
        
        case '&':
                if(isTrue == true){
                    ways += lTrue * rTrue;
                }
                else{
                    ways += lFalse * rFalse + lFalse * rTrue + rTrue * lFalse;
                }
            break;
        
        case '^':
                if(isTrue == true){
                    ways += lTrue * rFalse + lFalse * rTrue;
                }
                else{
                    ways += lFalse * rFalse + lTrue * rTrue;
                }
            break;

        default:
                cout << "Not an operator !!" << endl;
                return 0;
            break;
        }
    }

    return ways;
}

int main()
{
    //string s = "T|T&F^T";
    string s = "T^F&T";

    cout << "Number of ways for the expression to be TRUE: " << countWays(s, 0, s.length()-1, true);
    cout << endl;
    return 0;
}
