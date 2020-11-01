/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 03_shortest_dist_from_mine.cpp
 * Created on    : Monday 19 October 2020 06:31:35 PM IST
 * Last modified : Monday 19 October 2020 06:33:23 PM IST
 * Description   : to calculate the shortest distance of each cell from a
 * 					a mine in the given matrix
 * ***********************************************************************/
	
#include <iostream>
#include <queue>
#define M 6
#define N 5

using namespace std;
int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

template <typename T>

void printBoard(T board[M][N])
{
    for(auto i = 0; i < M; i++){
        for(auto j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(char board[M][N], int x, int y)
{
    return (x >= 0 && x <= M && y >= 0 && y <= N && board[x][y] != 'M' && board[x][y] != 'X');
}

void getDistance(char board[M][N], int distance[M][N])
{
    queue<pair<int, int >> q;
    int dist = 0;
    int x = 0, y = 0;

    if(distance[x][y] == 0){
        q.push({x, y});
        
        while(!q.empty()){
            int x1 = q.front().first;
            int y1 = q.front().second;

            q.pop();
            for(int i = 0; i < 8; i++){
                if(isValid(board, x1 + i, y1 + i)){
                    dist++;
                    q.push({x1 + i, y1 + i});
                    break;
                }
                
                dist++;
            }
        }
        distance[x][y] = dist;
    }
    
}

int main()
{
    /* 
    X denotes blocked cell
    O denotes cell, for which we have to calculate shotest
    distance from mine
    M denotes mine
    */

    char board[M][N] = 
    {
		{'O', 'M', 'O', 'O', 'X'},
		{'O', 'X', 'X', 'O', 'M'},
		{'O', 'O', 'O', 'O', 'O'},
		{'O', 'X', 'X', 'X', 'O'},
		{'O', 'O', 'M', 'O', 'O'},
		{'O', 'X', 'X', 'M', 'O'}
	};
    int distance[M][N] = {0};
    for(auto i = 0; i < M; i++){
        for(auto j = 0; j < N; j++){
            if(board[i][j] == 'X'){
                distance[i][j] = -1;
            }
        }
        cout << endl;
    }

    printBoard(board);
    cout << endl;
    
    getDistance(board, distance);
    

    printBoard(distance);

    return 0;
}