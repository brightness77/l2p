#include<string>
#include<iostream>


using std::string;



bool helper(const string& s) {
    //helper with strict palindrome standard

    int front = 0, back = s.size() - 1;

    while (front < back) {
        if (s[front] == s[back]) {
            //if same checked
            front++;
            back--;
        }
        else {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s) {

    //use two pointers to check if it is valid
    //one allowed character, which means we can try to ignore one
    //can have an algorithm to check that

    int front = 0, back = s.size() - 1;

    while (front < back) {
        if (s[front] == s[back]) {
            //if same checked
            front++;
            back--;
        }
        else {
            //if not same

            if (front + 1 == back) {
                //if this is last 2 chars
                //can eliminate one
                back--;
            }
            else {
                //if not last 2 chars
                if (!helper(s.substr(front + 1, back - front)) && !helper(s.substr(front, back - front))) {
                    //if none of the sub string is valid
                    return false;
                }
                else {
                    return true;
                }
            }
        }
    }

    return true;

}





string reverseString(const string& s) {

    int front = 0, back = s.size() - 1;

    string result = s;

    while (front < back) {
        std::swap(result[front], result[back]);
        front++;
        back--;
    }

    return result;
}









int main() {

    string test = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    std::cout << test << std::endl << reverseString(test) << std::endl;
    std::cout << validPalindrome(test) << std::endl;

	return 0;
}



/*
* 
aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga
aguokepatgbnvfqmgmlucupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuclmgmqfvnbgtapekouga

aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuclmgmqfvnbgtapekouga
aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuclmgmqfvnbgtapekouga

*/

