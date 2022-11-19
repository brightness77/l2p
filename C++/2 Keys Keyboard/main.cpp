#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::endl;
using std::min;


//dp memory list
vector<int> stepList = vector<int>(1001, INT_MAX);


int minSteps(int n) {



    //initialize 1
    stepList[1] = 0;

    if (stepList.at(n) == INT_MAX) { //if does not exist

        for (int stepI = 1; stepI <= n / 2; stepI++) {
            //iterate through all options
            //must exclude item 0

            if (stepList[stepI] == INT_MAX) { //if never calculated
                stepList[stepI] = minSteps(stepI); //calculate this value
            }
            
            
            if (n % stepI == 0) {
                //if it is stored
                //and it is a factor of the designated I
                int cStep = stepList[stepI] + n / stepI;
                //factor steps + one operation to copy + operations to paste(exclude one original copy)
                stepList[n] = min(cStep, stepList[n]); //find the smaller value

            }
        }
    }

    return stepList[n];

}






int main() {

    cout << minSteps(6) << endl;

	return 0;
}









