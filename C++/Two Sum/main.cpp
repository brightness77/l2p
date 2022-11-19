#include <vector>
#include <iostream>

using std::vector;

int makePartition(vector<int>& toSortList, int leftIndex, int rightIndex, int cPivotIndex) {
    //this is partition function that operate the list once and return new index positions

    int cPivot = toSortList.at(cPivotIndex); //PivotValue
    int newPivotIndex = leftIndex; //record new Pivot Index

    std::swap(toSortList.at(cPivotIndex), toSortList.at(rightIndex)); //move pivot to the end

    for (int i_list = leftIndex; i_list < rightIndex; i_list++) {
        if (toSortList.at(i_list) < cPivot){ //if the current value is smaller than pivot
            std::swap(toSortList.at(i_list), toSortList.at(newPivotIndex)); //it will be swapping to front
            newPivotIndex++; //add up to where index should be stored
        }
    }
    std::swap(toSortList.at(newPivotIndex), toSortList.at(rightIndex));
    return newPivotIndex;
}

void sortQ(vector<int>& toSortList, int leftIndex, int rightIndex) {
    if (rightIndex > leftIndex) {
        int toPartitionPivotIndex = makePartition(toSortList, leftIndex, rightIndex, leftIndex); //choosing left as pivot
        sortQ(toSortList, leftIndex, toPartitionPivotIndex - 1);
        sortQ(toSortList, toPartitionPivotIndex + 1, rightIndex);
    }
}

int main() {
    vector<int> test1;


    test1.push_back(0);
    test1.push_back(5);
    test1.push_back(2);
    test1.push_back(5);
    test1.push_back(6);
    test1.push_back(3);
    test1.push_back(4);

    sortQ(test1, 0, test1.size() - 1);
    for (int intsInVector : test1) {
        std::cout << intsInVector << " ";
    }

	return 0;
}