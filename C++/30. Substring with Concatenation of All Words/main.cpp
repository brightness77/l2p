#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>



using std::vector;
using std::unordered_map;
using std::string;






vector<int> findSubstring(string s, vector<string>& words) {

    vector<int> result;

    int sSize = s.size();
    int wordSize = words.front().size();
    int wordsSize = words.size();
    int windowSize = wordsSize * wordSize;

    unordered_map<string, int> wordsTable;

    //recording the wordTable
    for (string word : words) {
        if (wordsTable.count(word) == 0) {
            wordsTable[word] = 1;
        }
        else {
            wordsTable[word]++;
        }
    }

    //exam part
    for (int sI = 0; sI <= sSize - windowSize; sI++) {

        unordered_map<string, int> countTable;
        bool isFalse = false;

        //count part
        for (int wI = 0; wI < wordsSize; wI++) {

            string subS = s.substr(sI + wI * wordSize, wordSize);

            //check this segment of word
            if (wordsTable.count(subS) > 0) {
                //if it exist
                if (countTable[subS] >= wordsTable[subS]) {
                    //if enough this word found
                    isFalse = true;
                    break;
                }
                else {
                    //could add up one
                    countTable[subS]++;
                }

            }
            else {
                //if it does not exist
                isFalse = true;
                break;
            }
        }

        //exam part
        if (isFalse) {
            continue;
        }
        else {
            result.push_back(sI);
        }
    }

    return result;

}







int main() {

    string testS = "wordgoodgoodgoodbestword";

    vector<string> testWords = {
        "word", "good", "best", "good",
    };

    vector<int> testResult = findSubstring(testS, testWords);

    for (int i : testResult) {
        std::cout << i << " ";
    }


	return 0;
}