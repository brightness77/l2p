#include<iostream>
#include<string>

using std::string;



string countAndSay(int n) {

    //dp detection
    if (n == 1) {
        return "1";
    }

    //previous calculation detection

    string previous = countAndSay(n - 1);
    int start = 0;
    int end = 0;

    string result = "";

    while (end <= previous.size()) {
        //proceed
        if (previous[end] == previous[start]) {
            //if still the same number
            end++;
        }
        else {
            //if a different number encountered
            //first add number
            result += end - start + '0';

            //then add this number
            result += previous[start];

            start = end;
            end++;
        }

    }


    return result;
}



int main() {

    std::cout << countAndSay(4) << std::endl;


	return 0;
}

