#include<vector>
#include<string>
#include<iostream>




using std::vector;
using std::cout;
using std::endl;
using std::min;





int jumpH(vector<int>& nums, vector<int>& stepList, int target) {

    //cout << "Dealing with arrving slot " << target << endl;

    //exit case
    if (target == 1) {
        return 1;
    }

    int result = 10000;

    //iterate through previous cases
    for (int i = 0; i < target; i++) {

        if (target - i <= nums[i]) {
            //if it is enough distance to jump

            if (stepList[i] < 0) {
                //if the current step does not exist
                //need to calculate

                stepList[i] = jumpH(nums, stepList, i);
            }

            result = min(stepList[i] + 1, result);
        }
        //if cannot reach, just give up
    }

    //cout << "Need " << result << " steps to arrive slot " << target << endl;
    return result;

}



int jump(vector<int>& nums) {

    if (nums.size() == 1) { //edge case
        return 0;
    }

    vector<int> stepList(nums.size(), -1);
    stepList[0] = 0; //slot 0 need 0 jumps

    return jumpH(nums, stepList, nums.size() - 1);

}








int main() {

    vector<int> test = {
        2,3,1,1,4,
    };

    cout << jump(test) << endl;



	return 0;
}

