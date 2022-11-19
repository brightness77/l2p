#include<iostream>
#include<vector>



using std::vector;
using std::cout;
using std::endl;





vector<vector<int>> permutePattern(int numSize) {

    vector<vector<int>> resultPattern;

    if (numSize <= 1) { //end case
        vector<int> addVector(1, 0);
        resultPattern.push_back(addVector);
        return resultPattern;
    }

    resultPattern = permutePattern(numSize - 1);
    int origSize = resultPattern.size();

    //iterate through every existing pattern
    for (int toAddVectorI = 0; toAddVectorI < origSize; toAddVectorI++) {
        for (int addI = 0; addI < resultPattern[toAddVectorI].size() + 1; addI++) {
            //add the newest, biggest value to all positions of this patterns
            vector<int> addVector = resultPattern[toAddVectorI];
            addVector.insert(addVector.begin() + addI, numSize - 1);
            resultPattern.push_back(addVector);
        }
    }

    //delete all obsolete pattern
    resultPattern.erase(resultPattern.begin(), resultPattern.begin() + origSize);

    return resultPattern;
}



vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> resultVector;
    vector<vector<int>> resultPattern = permutePattern(nums.size());

    for (vector<int> patternVector : resultPattern) { //iterate every pattern
        vector<int> addVector;
        for (int posI : patternVector) {
            // iterate every element in this pattern
            addVector.push_back(nums[posI]);
        }
        resultVector.push_back(addVector);
    }
    return resultVector;
}













int main() {

    vector<int> test1 = {
        4, 6, 9, 15
    };

    /*
    vector<vector<int> > resultPattern = permutePattern(3);
    for (vector<int> subVector : resultPattern) {
        for (int subInt : subVector) {
            cout << subInt << ' ';
        }
        cout << endl;
    }
    */

    vector<vector<int> > result;
    result = permute(test1);

    for (vector<int> subVector : result) {
        for (int subInt : subVector) {
            cout << subInt << ' ';
        }
        cout << endl;
    }

	return 0;
}



