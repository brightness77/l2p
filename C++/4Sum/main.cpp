#include<iostream>
#include<vector>
#include<algorithm>



using std::vector;
using std::sort;






vector<vector<int>> fourSum(vector<int>& nums, int target) {

    vector<vector<int>> result;

    //edge cases
    if (nums.size() < 4) {
        return result;
    }

    //sort
    sort(nums.begin(), nums.end());

    //avoid repeating middleValue
    int lastOne = nums[0] - 1;

    //fix one and start iterating
    for (int indexOne = 0; indexOne < nums.size() - 3; indexOne++) {

        //check One
        if (lastOne == nums[indexOne]) {
            continue;
        }
        else {
            lastOne = nums[indexOne];
        }

        int lastTwo = nums[indexOne] - 1;

        //fix another one
        for (int indexTwo = indexOne + 1; indexTwo < nums.size() - 2; indexTwo++) {

            //check Two
            if (lastTwo == nums[indexTwo]) {
                continue;
            }
            else {
                lastTwo = nums[indexTwo];
            }


            //initialize index
            int indexThree = indexTwo + 1;
            int indexFour = nums.size() - 1;

            while (indexThree < indexFour) {
                if (nums[indexOne] + nums[indexTwo] + nums[indexThree] + nums[indexFour] > 0) {
                    //situation where sum is bigger than 0
                    indexFour--;
                }
                else if (nums[indexOne] + nums[indexTwo] + nums[indexThree] + nums[indexFour] < 0) {
                    //situation where sum is smaller than 0
                    indexThree++;
                }
                else { //situation that it is the result
                    vector<int> add = {
                        nums[indexOne], nums[indexTwo], nums[indexThree], nums[indexFour],
                    };

                    result.push_back(add);
                    while (indexThree < indexFour && nums[indexThree] == nums[indexThree + 1]) { //if next negative is equal
                        indexThree++;
                    }
                    while (indexThree < indexFour && nums[indexFour] == nums[indexFour - 1]) { //if next positive is equal
                        indexFour--;
                    }

                    indexThree++;
                    indexFour--;
                }
            }

        }

    }

    return result;
}




int main() {

    vector<int> test = {
                        2, 2, 2, 2, 2,
    };

    vector<vector<int> > testResult = fourSum(test, 8);

    for (vector<int> vs : testResult) {
        for (int ints : vs) {
            std::cout << ints << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}



