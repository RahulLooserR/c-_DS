/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 04_count_island.cpp
 * Created on    : Monday 19 October 2020 10:11:54 AM IST
 * Last modified : 
 * Description   :  count the number of island in the graph
 *                  or count the disconnected component of the graph
 * ***********************************************************************/

#include <iostream>
#include <queue>
// #include <pair>

#define M  10    // row
#define N  10    // column

using namespace std;

void printBoard(int board[M][N])
{
    for (int i = 0;  i < M; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 0)
            cout << " " << " ";
            
            else
            cout  << board[i][j] << " ";
        }
        cout << endl;
    }
}

int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(int board[M][N], bool processed[M][N], int x, int y)
{
    // return (x >= 0 && x <= M && y >= 0 && y <= N && board[x][y] == 1 && !processed[x][y]);
    return (x >= 0) && (x < M) && (y >= 0) && (y < N) &&
		(board[x][y] && !processed[x][y]);
}

void floodFill(int board[M][N], bool processed[M][N], int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    processed[x][y] = 1;
   

    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        int x1 = node.first, y1 = node.second;
        // board[x1][y1] = color;

        /* check all adjacent values are valid, total 8 */
        for(int i = 0; i <  8; i++){
           if(isValid(board, processed, x1 + row[i], y1 + col[i])){
               processed[x1 + row[i]][y1 + col[i]] = 1;
               q.push({x1 + row[i], y1 + col[i]});
           }
        }
    }
}
void printProcessed(bool processed[M][N])
{
    for (int i = 0;  i < M; i++){
        for(int j = 0; j < N; j++){
            cout  << processed[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int board[M][N]=
	{
		{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
		{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
	};

    bool processed[M][N] = {0};
    int count = 0;

    printBoard(board);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(processed[i][j] == 0 && board[i][j] == 1){
                floodFill(board, processed, i, j);
                count++;
                cout << "i: " << i <<  ", j: " << j << endl;
                printProcessed(processed);
            }
        }
    }

    cout << count << endl;

    return 0;
}
