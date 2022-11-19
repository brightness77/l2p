#include<string>
#include<iostream>

using std::string;
using std::cout;






bool isNumber(string s) {

    int phase = -1;
    /*
    phase indicators
    0 sign for number(skippable)
    1 number before decimal(must exist)(need to evaluate leading 0)
    2 decimal point(skippable)
    3 number after decimal(should not exist if no decimal point found)
    4 E(skippable)
    5 sign for e(should not exist if no E found)
    6 number for e(should not exist if no E found)
    */
    bool numberFoundBefore = false;
    bool numberFoundAfter = false;



    for (char c : s) {
        if (c == '+' || c == '-') {
            if (phase == -1) {
                phase = 0;
            }
            else if (phase == 4) {
                phase = 5;
            }
            else { //wrong phase
                return false;
            }
        }
        else if (c == 'e' || c == 'E') {
            if (phase == 1 || phase == 2 || phase == 3) { //situation that 3, 3., 3.3 are all acceptable
                phase = 4;
            }
            else {
                return false;
            }
        }
        else if (c == '.') {
            if (phase == -1 || phase == 0 || phase == 1) { //situation that .2, 1.2, -.2 are all acceptable
                phase = 2;
            }
            else {
                return false;
            }
        }
        else if (c >= '0' && c <= '9') {

            if (phase == -1) { //if no sign found
                numberFoundBefore = true;
                phase = 1;
            }
            else if (phase == 0) { //if sign is found
                numberFoundBefore = true;
                phase = 1;
            }
            else if (phase == 1) { //if it is already the number before decimal
                numberFoundBefore = true;
                //this will keep phase 1
            }
            else if (phase == 2) { //if decimal point found
                numberFoundBefore = true;
                phase = 3;
            }
            else if (phase == 3) { //if it is already the number after decimal
                numberFoundBefore = true;
                //this will keep phase 3
            }
            else if (phase == 4) { //if number directly found after E
                numberFoundAfter = true;
                phase = 6;
            }
            else if (phase == 5) { //if found after sign E
                numberFoundAfter = true;
                phase = 6;
            }
            else if (phase == 6) { //if found in the E number
                numberFoundAfter = true;
                //this will keep phase 6
            }

        }
        else { //other invalid characters
            return false;
        }
    }

    //to judge if there is at least number found
    if (phase >= 4) { //if there is E exist
        return numberFoundBefore && numberFoundAfter;
    }
    else { //if there is no E exist
        return numberFoundBefore;
    }

    return false;
}



int main() {

    string test1 = "459277e38+";

    cout << isNumber(test1);

    return 0;
}


