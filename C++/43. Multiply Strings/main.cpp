#include<string>
#include<iostream>



using std::string;





string addSingle(string num1, string num2) {

    string result = "";

    int carry = 0;

    while (!num1.empty() || !num2.empty()) {

        if (num1.empty()) {

            int cNumber = num2.back() - '0' + carry;
            char toAdd = cNumber % 10 + '0';
            carry = cNumber / 10;

            num2.pop_back();

            result = toAdd + result;

        }
        else if (num2.empty()) {

            int cNumber = num1.back() - '0' + carry;
            char toAdd = cNumber % 10 + '0';
            carry = cNumber / 10;

            num1.pop_back();

            result = toAdd + result;

        }
        else {

            int cNumber = num1.back() - '0' + num2.back() - '0' + carry;
            char toAdd = cNumber % 10 + '0';
            carry = cNumber / 10;

            num1.pop_back();
            num2.pop_back();

            result = toAdd + result;
        }
    }

    if (carry > 0) {
        char toAdd = carry + '0';
        result = toAdd + result;
    }

    return result;

}



string multiplySingle(string num, char digit) {

    string result = "";

    int carry = 0;

    for (int i = num.size() - 1; i >= 0; i--) {
        int cNumber = (num[i] - '0') * (digit - '0') + carry;
        char toAdd = cNumber % 10 + '0';

        //add this digit
        result = toAdd + result;

        //update carry
        carry = cNumber / 10;
    }

    //update last carry
    if (carry != 0) {
        char toAdd = carry + '0';
        result = toAdd + result;
    }

    return result;
}



string multiply(string num1, string num2) {

    if ((num1.size() == 1 && num1[0] == '0') || (num2.size() == 1 && num2[0] == '0')) {
        return 0;
    }

    string result = "";

    for (int i = num2.size() - 1; i >= 0; i--) {
        string cString = multiplySingle(num1, num2[i]);

        for (int zI = 0; zI < num2.size() - 1 - i; zI++) {
            //multiply by 10
            cString += '0';
        }

        result = addSingle(result, cString);


    }

    return result;
}







int main() {

    //std::cout << multiplySingle("123", '5') << std::endl;
    //std::cout << addSingle("364", "182") << std::endl;
    std::cout << multiply("0", "0") << std::endl;




	return 0;
}









