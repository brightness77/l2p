#include<iostream>
#include<vector>

using std::vector;



int numRescueBoats(vector<int>& people, int limit) {

    vector<int> guysSet(limit, 0);
    int result = 0;

    //count weight
    for (int weight : people) {
        guysSet[weight - 1]++;
    }


    //calculating boats
    int thinBoy = 0, fatBoy = limit - 1;
    while (thinBoy < fatBoy) {
        //boy finder
        if (guysSet[thinBoy] == 0) {
            thinBoy++;
            continue;
        }
        if (guysSet[fatBoy] == 0) {
            fatBoy--;
            continue;
        }

        if (thinBoy + fatBoy > limit - 2) { //if too heavy
            guysSet[fatBoy]--;
        }
        else { //if can fit these 2
            guysSet[fatBoy]--;
            guysSet[thinBoy]--;
        }

        result++;
    }

    if (thinBoy * 2 > limit - 2) {
        result += guysSet[thinBoy];
    }
    else {
        result += (guysSet[thinBoy] + 1) / 2;
    }

    return result;

}





int main(){

    vector<int> test1 = {
        2, 2,
    };

    std::cout << numRescueBoats(test1, 6) << std::endl;

	return 0;
}






