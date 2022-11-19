#include<vector>
#include<iostream>


using std::vector;


int removeElement(vector<int>& nums, int val) {

    int result = 0;
    int i = 0;
    int cSize = nums.size();

    while (i < cSize) {
        if (nums[i] == val) {
            nums.erase(nums.begin() + i);
            cSize--;
            result++;
        }
        else {
            i++;
        }
    }

    return result;
}





int main() {

    vector<int> test1 = {
        0,1,2,2,3,0,4,2,
    };

    int test1b = 2;

    int testResult = removeElement(test1, test1b);

    for (int i = 0; i < testResult; i++) {
        std::cout << test1[i] << " ";
    }

	return 0;
}
