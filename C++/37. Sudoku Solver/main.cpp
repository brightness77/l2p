#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::endl;




bool isValid(vector<vector<char>>& board, const int& cX, const int& cY, const char& val) {

    //validation function
    //verify row, column and 3*3

    //NOTICE: val is a CHAR not an INT!!

    //row validation
    for (int i = 0; i < 9; i++) {
        if (i == cY) {
            // skip itself
            continue;
        }
        if (board[cX][i] == val) {
            return false;
        }
    }

    //column validation
    for (int i = 0; i < 9; i++) {
        if (i == cX) {
            // skip itself
            continue;
        }
        if (board[i][cY] == val) {
            return false;
        }
    }

    //area validation
    //using bay to detect
    int xBay = cX / 3;
    int yBay = cY / 3;

    for (int i = (xBay * 3); i < (xBay * 3 + 3); i++) {
        for (int j = (yBay * 3); j < (yBay * 3 + 3); j++) {
            if (cX == i && cY == j) { //skip self
                continue;
            }
            if (board[i][j] == val) {
                return false;
            }
        }
    }

    //if all validation passes
    return true;

}



void nextValidPos(vector<vector<char>>& board, const int& cX, const int& cY, int& nextX, int& nextY) {

    for (int i = cX; i < 9; i++) {
        if (i == cX) { //if it is the current row
            for (int j = cY; j < 9; j++) {
                if (board[i][j] == '.') {
                    nextY = j;
                    break;
                }
            }
        }
        else if (i > cX) { //if it is not the currentTow
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    nextY = j;
                    break;
                }
            }
        }

        if (nextY != -1) { //if blank found
            nextX = i;
            return;
        }
    }

    //if did not return, which means no blank found
    nextX = -1;
    nextY = -1;

}



bool solveHelper(vector<vector<char>>& board, int posX, int posY) {

    //exit
    if (posX == -1 && posY == -1) {
        return true;
    }

    cout << "trying " << posX << " , " << posY << endl;

    for (int tryD = '1'; tryD <= '9'; tryD++) {
        if (isValid(board, posX, posY, tryD)) { //if current is valid

            //record the digit for next blank try
            board[posX][posY] = tryD;

            int nextX = -1, nextY = -1;
            nextValidPos(board, posX, posY, nextX, nextY); //get next valid


            //IMPORTANT STEP!!
            //this will call helper in next blank
            //it will go recursively to all the blank
            //if this returns true, which means final solve is found
            if (solveHelper(board, nextX, nextY)) {
                //if solve found 
                return true;
            }
            else {
                //there is no possible solution for current value
                //need to try other digit of current blank
            }
        }
        else {
            //if current digit did not succeed
            //will let it proceed to another digit
        }
    }

    //if the loop ends but did not return
    //which means no possible solve for this root is found
    board[posX][posY] = '.'; //need to reset to blank for backtracking issue
    return false;

}


void solveSudoku(vector<vector<char>>& board) {

    //using backtracking
    //try every blank space with every possible number
    //when one works, proceed to next one
    //when a blank cannot fit any digit
    //which means the initial try is not correct
    //need to backtrack to the next possibilities of the previous blank

    //using helper with more parameters


    //find next position
    int nextX = -1;
    int nextY = -1;

    nextValidPos(board, 0, 0, nextX, nextY);


    //run the solver
    if (solveHelper(board, nextX, nextY)) {
        cout << "solve found!" << endl;
    }

}








int main() {

    vector<vector<char> > testBoard = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    vector<vector<char> > solutionBoard = {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','9'},
    };



    solveSudoku(testBoard);

    bool isCorrect = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (testBoard[i][j] != solutionBoard[i][j]) {
                isCorrect = false;
                cout << "Position " << i << " , " << j << " should be " << solutionBoard[i][j] << " instead of " << testBoard[i][j] << endl;
            }
        }
    }

    if (isCorrect) {
        cout << "Well Done" << endl;
    }
    else {
        cout << "Oh no mistakes!" << endl;
    }




	return 0;
}

