/*
  flood fill algorithm is used to fill the selected area
  with different color
  eg: bucket  fill in paint

*/

#include <iostream>
#include <queue>
#include <list>
#define M 4
#define N 5

using namespace std;

void printBoard(int board[M][N])
{
    for (int i = 0;  i < M; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

/* all possible adjacent nodes,total 8 
   currently checking only one at a time
*/
bool isValid(int board[M][N], int x, int y, int color)
{
    return (x >= 0 && x <= M && y >= 0 && y <= N && board[x][y] == color);
}

/* checking if given coordinate is valid */
int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

/* this fucntion takes argument
    1 -> board
    2 -> coordinate x & y
    3 -> color to be replaced
*/
void floodFill(int board[M][N], int x, int y, int color)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    int currentColor = board[x][y];

    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        int x1 = node.first, y1 = node.second;
        board[x1][y1] = color;

        /* check all adjacent values are valid, total 8 */
        for(int i = 0; i <  8; i++){
           if(isValid(board, x1 + row[i], y1 + col[i], currentColor)){
               q.push({x1 + row[i], y1 + col[i]});
           }
        }
    }
}

int main()
{
    int board[M][N] = {
        {0, 1, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    printBoard(board); 
    floodFill(board, 1, 0, 7);
    cout << "---------------------------" << endl;
    printBoard(board);

    return 0;
}