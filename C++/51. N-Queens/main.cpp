#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>




using std::string;
using std::vector;
using std::unordered_set;





vector<string> resultTranslator(const int& n, unordered_set<int>& cResult) {

    string allEmpty(n, '.');
    vector<string> result(n, allEmpty);

    for (int qIP : cResult) {
        result[qIP / n][qIP % n] = 'Q';
    }

    return result;
}




bool piece(const int& n, unordered_set<int>& cResult, int& cP) {
    //the number here is the numeric position of the board

    for (int cQ : cResult) {

        //column check
        if (cQ % n == cP % n) {
            return false;
        }

        //row check
        if (cQ / n == cP / n) {
            return false;
        }

        //diagonal check
        //translate coordinates
        int xDiff = (cP / n) - (cQ / n);
        int yDiff = (cP % n) - (cQ % n);

        if (xDiff == yDiff || xDiff == -yDiff) {
            //either \ or /
            return false;
        }
    }

    //if all passed
    return true;
}



void solveHelper(const int& n, vector<vector<string>>& result, unordered_set<int>& cResult, int qPos) {

    //exit
    if (cResult.size() == n) {
        //if enough was collected
        result.push_back(resultTranslator(n, cResult));
        return;
    }


    //start finding
    //here for saving time, we will know that we must have one queen on each row
    for (int cP = qPos; cP < n * n; cP++) {
        //using all remaining position to try
        if (piece(n, cResult, cP)) {
            //if no conflicts
            cResult.insert(cP); //add the current one

            //this will find out all the future pieceful path for current selections
            //if does not meet exit condition(where n queens present)
            //it will not add anything but return to last layer
            solveHelper(n, result, cResult, cP + 1);

            //after solving the future possible
            //need to delete current position
            cResult.erase(cP);
        }
    }

    //if all the position turns out to be not working
    //last round will end and return to previous situation
}


vector<vector<string>> solveNQueens(int n) {

    //need to find all answers

    vector<vector<string>> result;
    unordered_set<int> oneResult;

    solveHelper(n, result, oneResult, 0);

    return result;
}











int main() {

    vector<vector<string>> result;
    result = solveNQueens(4);

    for (vector<string> oneResult: result) {
        std::cout << "Solution Begins!" << std::endl;
        for (string oneRow : oneResult) {
            std::cout << oneRow << std::endl;
        }
        std::cout << "Solution Ends!" << std::endl;
    }


	return 0;
}

