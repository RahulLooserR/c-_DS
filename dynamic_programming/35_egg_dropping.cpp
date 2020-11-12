/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : egg_dropping.cpp
 * Created on    : Thursday 12 November 2020 07:19:09 AM IST
 * Last modified : 
 * Description   : 
 * ***********************************************************************/

#include <iostream>

using namespace std;

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

    int min = INT32_MAX;

    for(int k = 1; k <= floors; k++){
               /* if egg breaks at kth floor - eggDrop(eggs-1,k-1)
                    number eggs will reduce 
                    total height of building is floors 
                    if egg breaks move down the kth floor*/
        int  temp = 1 + max(eggDrop(eggs-1, k-1), eggDrop(eggs, floors-k));

        if(temp < min){
            min = temp;
        }
    }

    return min;
}

int main()
{
    int eggs = 2;
    int floors = 10;

    cout << "Minimum trial required to find critical/threshold floor: " << eggDrop(eggs, floors) << endl;

    return 0;
}