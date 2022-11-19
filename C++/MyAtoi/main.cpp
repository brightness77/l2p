#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;



int myAtoi(string s) {

    int result = 0;
    bool firstDigitMet = false;
    int positivity = 1;

    for (char c : s) {
        if (!firstDigitMet) { //if did not encounter the first digit
            if (c == 43) { //+
                positivity = 1;
            }
            else if (c == 45) {
                positivity = -1;
            }
            else if (c >= 48 && c <= 57) { //if it is a digit
                firstDigitMet = true;
                result = c - 48;
            }
        }
        else { //if first digit is met, no need to adjust positivity
            if (c >= 48 && c <= 57) { //if it is a digit
                //oversize check
                if (positivity == 1) { //if positive number
                    if ((result > INT_MAX / 10) || ((result == INT_MAX / 10) && c > 54)) { //if exceed max
                        return INT_MAX;
                    }
                    else {
                        result = result * 10 + c - 48;
                    }
                }
                else if (positivity == -1) { //if negative number
                    if ((result > INT_MAX / 10) || ((result == INT_MAX / 10) && c > 55)) {
                        return INT_MIN;
                    }
                    else {
                        result = result * 10 + c - 48;
                    }
                }
            }
            else { //if it is not a digit
                break; //leave the loop
            }
        }
    }

    return result * positivity;

}


int main() {

    string test1 = "   42413425193 1323 with words";

    int result1 = myAtoi(test1);

    cout << result1 << endl;


	return 0;
}