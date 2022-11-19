#include<vector>

using std::vector;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};




ListNode* reverseKGroup(ListNode* head, int k) {

    //first k group
    //k <= n so at least one group is guaranteed

    if (k == 1) { //edge cases that k is 1
        return head;
    }

    ListNode* currentP = head;

    vector<ListNode*> currentGroup;

    for (int i = 0; i < k; i++) {
        //getting the right head
        currentGroup.push_back(currentP);
        currentP = currentP->next;
    }

    //get the result returning node
    ListNode* resultHeadP = currentGroup[k - 1];

    currentGroup[0]->next = currentGroup[k - 1]->next;
    for (int i = 1; i < k; i++) {
        currentGroup[i]->next = currentGroup[i - 1];
    }



    bool isNextGroupComplete = true;

    do {
        //first determine if next group is complete
        ListNode* lastTailP = currentGroup.front();
        currentP = lastTailP -> next;
        currentGroup.clear();

        for (int i = 0; i < k; i++) {
            if (currentP->next != nullptr) {
                currentGroup.push_back(currentP);
                currentP = currentP->next;
            }
            else {
                isNextGroupComplete = false;
                break;
            }
        }

        if (!isNextGroupComplete) { //if incomplete group detected
            break;
        }

        //start giving values
        lastTailP->next = currentGroup[k - 1];
        currentGroup[0]->next = currentGroup[k - 1]->next;
        for (int i = 1; i < k; i++) {
            currentGroup[i]->next = currentGroup[i - 1];
        }


    } while (isNextGroupComplete);

    return resultHeadP;

}






int main() {

    ListNode testHead(1);

    ListNode test2(2);
    testHead.next = &test2;

    ListNode test3(3);
    test2.next = &test3;

    ListNode test4(4);
    test3.next = &test4;

    ListNode test5(5);
    test4.next = &test5;

    reverseKGroup(&testHead, 2);


	return 0;
}





