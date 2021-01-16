#include <iostream>

using namespace std;

#define M 9     // M is a 2D matrix representing the soduko board (M*M)


// Checks if given row and column can have a placeable number
bool placeables(int grid[M][M], int row, int col, int num)
{

    // Return false, if the same number is found in the same row
    for (int x=0; x<=8; x++){
        if (grid[row][x]==num){
            return false;
        }
    }

    // Return false, if the same number is found in the same column
    for (int y=0; y<=8; y++){
        if (grid[y][col]==num){
            return false;
        }
    }

    //Return false, if the same number is found in the same 3x3 block
    int Row = row-row % 3;      //From the starting row
    int Col = col-col % 3;      //From the starting column

    for (int x=0; x<3; x++){
         for (int y=0; y<3; y++){
             if (grid[x+Row][y+Col]==num)
                return false;
         }
    }
    return true;
}

// Solving soduko by using backtracking
bool Solve_Suduko(int board[M][M], int row, int col)
{
    // Return true and avoid further backtracking if reached the 8th row and 9th column
    if (row == M-1 && col == M){
        return true;
    }

    // If column value becomes 9, move to next row and column start from 0
    if (col == M) {
        row++;
        col = 0;
    }

    // Check if the cell of the soduko board has a given value, from there we move to the next column
    if (board[row][col] > 0){
        return Solve_Suduko(board, row, col + 1);
    }

    for (int num=1; num<=M; num++){

        // Checking if placing a number can be done on a specific cell/element of the board
        if (placeables(board, row, col, num)){

            //Assigning a number to a cell/element
            board[row][col] = num;

            //  Checking for next placeable with next column
            if (Solve_Suduko(board, row, col + 1)){
                return true;
            }
        }
        board[row][col] = 0;
    }
    return false;
}

// A function to print the Soduko board
void Print_Board(int arr[M][M]){

    for (int x=0; x<M; x++)
    {
        for (int y=0; y<M; y++)
            cout << arr[x][y] << " ";
        cout << endl;
    }
}

int main()
{
    cout<<"\n_______________________"<<endl;
    cout<<"THE SWIFT SOLVER"<<endl;
    cout<<endl;
    // 0 means unassigned cells
    int board[M][M] = { { 0, 7, 0, 0, 0, 0, 0, 0, 9 },
                       { 5, 1, 0, 4, 2, 0, 6, 0, 0 },
                       { 0, 8, 0, 3, 0, 0, 7, 0, 0 },
                       { 0, 0, 8, 0, 0, 1, 3, 7, 0 },
                       { 0, 2, 3, 0, 8, 0, 0, 4, 0 },
                       { 4, 0, 0, 9, 0, 0, 1, 0, 0 },
                       { 9, 6, 2, 8, 0, 0, 0, 3, 0 },
                       { 0, 0, 0, 0, 1, 0, 4, 0, 0 },
                       { 7, 0, 0, 2, 0, 3, 0, 9, 6 } };

    if (Solve_Suduko(board, 0, 0)){
       Print_Board(board);
    }
    else{
         cout << "No solution  exists " << endl;
    }
    cout<<"_______________________"<<endl;

    return 0;
}
