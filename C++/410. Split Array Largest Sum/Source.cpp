#include<vector>
#include<iostream>

using std::vector;





int splitArray(vector<int>& nums, int m) {

    //calculate sum and max
    int wholeSum = 0;
    int singleMax = 0;

    for (int i : nums) {
        wholeSum += i;
        if (i > singleMax) {
            singleMax = i;
        }
    }

    //starting binary search on possible minimum max sub sum
    int low = singleMax;
    int high = wholeSum;

    while (low < high) {
        //this mid is the supposed value
        int mid = (low + high) / 2;
        int cSum = 0;
        int subCount = 0;

        //finding numbers of segments
        for (int i : nums) {
            if (cSum + i > mid) {
                //if cut is needed here
                subCount++;
                cSum = i;
            }
            else {
                //just add the value
                cSum += i;
            }
        }

        //analyse sub count
        if (subCount + 1 > m) {
            //more sub count is not acceptable, need to raise the sub sum for larger sum and less sub counts
            low = mid + 1;
        }
        else {
            //less sub count means the minimum sum is too large, can have possible smaller sums
            //note that this also counts for equal sub count
            //even if equal, we cannot guarantee mid is the correct value, need low = high
            //note here high is assigned mid, which is because mid could be the possible answer
            //if we finally prove mid - 1 cannot meet the condition
            high = mid;
        }

    }

    return low;

}










int main() {

    vector<int> test1 = {
        7,2,5,10,8,
    };

    std::cout << splitArray(test1, 2) << std::endl;



	return 0;
}

