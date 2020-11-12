/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : egg_dropping.cpp
 * Created on    : Thursday 12 November 2020 07:19:09 AM IST
 * Last modified : 
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int t[1001][1001];

int max(int a, int b){
    return a > b ? a : b;
}

int eggDrop(int eggs, int floors)
{
    if(eggs == 1){
        return floors;
    }
    if(floors <= 1){
        return floors;
    }

    if(t[eggs][floors] != -1){
        return t[eggs][floors];
    }

    int min = INT32_MAX;

    for(int k = 1; k <= floors; k++){
               /* if egg breaks at kth floor - eggDrop(eggs-1,k-1)
                    number eggs will reduce 
                    total height of building is floors 
                    if egg breaks move down the kth floor*/
        //int  temp = 1 + max(eggDrop(eggs-1, k-1), eggDrop(eggs, floors-k));
        /* optimization */
        int low, high;
        if(t[eggs-1][k-1] != -1){
            low = t[eggs-1][k-1];
        }
        else{
            low = eggDrop(eggs-1, k-1);
            t[eggs-1][k-1] = low;
        }

        if(t[eggs][floors-k] != -1){
            high = t[eggs][floors-k];
        }
        else{
            high = eggDrop(eggs, floors-k);
            t[eggs][floors-k] = high;
        }

        int temp  = 1 + max(low, high);

        if(temp < min){
            min = temp;
        }
    }

    return t[eggs][floors] = min;  /* memoization */
}

int main()
{
    int eggs = 2;
    int floors = 10;
    memset(t, -1, sizeof(t));
    cout << "Minimum trial required to find critical/threshold floor: " << eggDrop(eggs, floors) << endl;

    return 0;
}