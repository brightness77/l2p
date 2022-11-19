#include<vector>
#include<iostream>


using namespace std;



void nextPermutation(vector<int>& nums) {

    //basically is to find the first discrepancy
    //whenever there is an ascending 2 digits, we know there are next permutation there
    //we need to find the last ascending 2 digits

    //whenever we find the last 2 ascending digits
    //the latter digits till end would be the biggest number with these digits
    //we need to swap the former of 2 with the smallest digit larger than it in the latter digits
    //the latter all digits will still in descending order, so we want the smallest of it
    //reverse all the latter digits

    //edge cases
    if (nums.size() == 1) { //if it has only one element
        return;
    }

    int size = nums.size();
    int firstTR = size - 2;

    while (firstTR >= 0 && nums[firstTR] >= nums[firstTR + 1]) {
        --firstTR;
    }
    //we will get the first descending now

    if (firstTR < 0) {
        //if the whole sequence is descending
        //need to reverse the whole list
    }
    else {
        //swap it!

        int iSwap = firstTR + 1;

        while (iSwap < size && nums[firstTR] < nums[iSwap]) {
            //here we need to see if iSwap is larger than size
            iSwap++;
        }

        iSwap--;

        swap(nums[firstTR], nums[iSwap]);

    }

    //now swap the latter part of number
    int left = firstTR + 1;
    int right = size - 1;

    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }

}




int main() {

    vector<int> test1 = {
        5,1,1,
    };

    nextPermutation(test1);

    for (int i : test1) {
        cout << i << " ";
    }

	return 0;
}

