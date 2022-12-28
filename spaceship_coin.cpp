#include<bits/stdc++.h>

using namespace std;
int ans = INT_MIN,rows=1;
void getMaxCoins(vector<vector<int>> board, int isRowSafe, int cur_row, int cur_col, bool bombUsed, int coins)
{
    if (cur_row < 0 || cur_col >= 5 || cur_col < 0)
    {
        ans = max(ans, coins);
        return;
    }

    //if cell is 1 or zero
    if (board[cur_row][cur_col] == 1 || board[cur_row][cur_col] == 0)
    {
        int new_coins = coins;
        if (board[cur_row][cur_col] == 1)
        {
            new_coins++;
        }
        if (bombUsed)
        {
            isRowSafe--;
        }
        getMaxCoins(board, isRowSafe, cur_row - 1, cur_col, bombUsed, new_coins);
        getMaxCoins(board, isRowSafe, cur_row - 1, cur_col + 1, bombUsed, new_coins);
        getMaxCoins(board, isRowSafe, cur_row - 1, cur_col - 1, bombUsed, new_coins);
    }
    else if (board[cur_row][cur_col] == 2)
    {
        if (bombUsed && isRowSafe <= 0)
        {
            ans = max(ans, coins);
            return;
        }
        else if (bombUsed && isRowSafe > 0)
        {
            isRowSafe--;
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col, bombUsed, coins);
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col + 1, bombUsed, coins);
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col - 1, bombUsed, coins);
        }
        else
        {
            bombUsed = true;
            isRowSafe = 4;
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col, bombUsed, coins);
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col + 1, bombUsed, coins);
            getMaxCoins(board, isRowSafe, cur_row - 1, cur_col - 1, bombUsed, coins);
        }
    }

}


int main()
{
    cin>>rows;

    vector<vector<int>> board(rows,vector<int>(5));


    // inputting the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>board[i][j];
        }
    }
    int isRowSafe = 0;
    getMaxCoins(board, isRowSafe, board.size() - 1, 1, false, 0);
    getMaxCoins(board, isRowSafe, board.size() - 1, 2, false, 0);
    getMaxCoins(board, isRowSafe, board.size() - 1, 3, false, 0);

    cout<<"Max_coins : "<< ans<<endl;

}


